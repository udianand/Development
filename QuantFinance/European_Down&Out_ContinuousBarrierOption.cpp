#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <random>
#include <algorithm>
#define ZERO 0.0

using namespace std;

double risk_free_rate, initial_stock_price, strike_price, expiration_time, volatility, barrier_price;
int no_of_trials, no_of_divisions;
double call_all_average = 0, call_alive_average = 0;
double put_all_average = 0, put_alive_average = 0;

std::default_random_engine generator;

double get_uniform()
{
	std::uniform_real_distribution <double> distribution(0.0, 1.0);
	double number = distribution(generator);
	return (number);
}

bool check_if_barrier_touched(double current_stock_price)
{
	return (current_stock_price <= barrier_price) ? false : true;
}

double N(const double& z) {
	if (z > 6.0) { return 1.0; }; // this guards against overflow 
	if (z < -6.0) { return 0.0; };
	double b1 = 0.31938153;
	double b2 = -0.356563782;
	double b3 = 1.781477937;
	double b4 = -1.821255978;
	double b5 = 1.330274429;
	double p = 0.2316419;
	double c2 = 0.3989423;
	double a = fabs(z);
	double t = 1.0 / (1.0 + a*p);
	double b = c2*exp((-z)*(z / 2.0));
	double n = ((((b5*t + b4)*t + b3)*t + b2)*t + b1)*t;
	n = 1.0 - b*n;
	if (z < 0.0) n = 1.0 - n;
	return n;
}

double option_price_call_black_scholes(const double& S,       // spot (underlying) price
	const double& K,       // strike (exercise) price,
	const double& r,       // interest rate
	const double& sigma,   // volatility 
	const double& time)	  // time to maturity 
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / K) + r*time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma*time_sqrt);
	return S*N(d1) - K*exp(-r*time)*N(d2);
}

double closed_form_down_and_out_european_call_option()
{
	// I took this formula from Wilmott, Howison and Dewynne, "The Mathematics of Financial Derivatives"
	double K = (2 * risk_free_rate) / (volatility*volatility);
	double A = option_price_call_black_scholes(initial_stock_price, strike_price,
		risk_free_rate, volatility, expiration_time);
	double B = (barrier_price*barrier_price) / initial_stock_price;
	double C = pow(initial_stock_price / barrier_price, -(K - 1));
	double D = option_price_call_black_scholes(B, strike_price, risk_free_rate, volatility, expiration_time);
	return (A - D*C);
}

double option_price_put_black_scholes(const double& S,      // spot price
	const double& K,      // Strike (exercise) price,
	const double& r,      // interest rate
	const double& sigma,  // volatility
	const double& time)
{
	double time_sqrt = sqrt(time);
	double d1 = (log(S / K) + r*time) / (sigma*time_sqrt) + 0.5*sigma*time_sqrt;
	double d2 = d1 - (sigma*time_sqrt);
	return K*exp(-r*time)*N(-d2) - S*N(-d1);
}

double closed_form_down_and_in_european_put_option()
{
	// just making it easier by renaming the global variables locally
	double S = initial_stock_price;
	double r = risk_free_rate;
	double T = expiration_time;
	double sigma = volatility;
	double H = barrier_price;
	double X = strike_price;

	// Took these formulae from some online reference
	double lambda = (r + ((sigma*sigma) / 2)) / (sigma*sigma);
	double temp = 2 * lambda - 2.0;
	double x1 = (log(S / H) / (sigma*sqrt(T))) + (lambda*sigma*sqrt(T));
	double y = (log(H*H / (S*X)) / (sigma*sqrt(T))) + (lambda*sigma*sqrt(T));
	double y1 = (log(H / S) / (sigma*sqrt(T))) + (lambda*sigma*sqrt(T));
	return (-S*N(-x1) + X*exp(-r*T)*N(-x1 + sigma*sqrt(T)) +
		S*pow(H / S, 2 * lambda)*(N(y) - N(y1)) -
		X*exp(-r*T)*pow(H / S, temp)*(N(y - sigma*sqrt(T)) - N(y1 - sigma*sqrt(T))));
}

double closed_form_down_and_out_european_put_option()
{
	double vanilla_put = option_price_put_black_scholes(initial_stock_price, strike_price,
		risk_free_rate, volatility, expiration_time);
	double put_down_in = closed_form_down_and_in_european_put_option();
	return (vanilla_put - put_down_in);
}

double probabilbity_of_touching_barrier(double current_stock_price)
{
	return exp(-((2 * log(initial_stock_price / barrier_price)*log(current_stock_price / barrier_price)) / (volatility*volatility*expiration_time)));
}

void simulate_option_path()
{

	double T = expiration_time / ((double)no_of_divisions);
	double R = (risk_free_rate - 0.5*pow(volatility, 2))*T;
	double SD = volatility*sqrt(T);

	bool has_path1_touched_barrier, has_path2_touched_barrier, has_path3_touched_barrier,
		has_path4_touched_barrier;

	double simulated_alive_call_average, simulated_all_call_average;
	double simulated_alive_put_average, simulated_all_put_average;

	double pc1, pc2, pc3, pc4;

	for (int i = 0; i < no_of_trials; i++)
	{
		double S1 = initial_stock_price;
		double S2 = initial_stock_price;
		double S3 = initial_stock_price;
		double S4 = initial_stock_price;

		for (int j = 0; j < no_of_divisions; j++) {

			// create the unit normal variates using the Box-Muller Transform
			double x = get_uniform();
			double y = get_uniform();
			double a = sqrt(-2.0*log(x)) * cos(6.283185307999998*y);
			double b = sqrt(-2.0*log(x)) * sin(6.283185307999998*y);

			S1 = S1*exp(R + SD*a);
			S2 = S2*exp(R - SD*a);
			S3 = S3*exp(R + SD*b);
			S4 = S4*exp(R - SD*b);

			has_path1_touched_barrier = check_if_barrier_touched(S1);
			has_path2_touched_barrier = check_if_barrier_touched(S2);
			has_path3_touched_barrier = check_if_barrier_touched(S3);
			has_path4_touched_barrier = check_if_barrier_touched(S4);

		}

		pc1 = probabilbity_of_touching_barrier(S1);
		pc2 = probabilbity_of_touching_barrier(S2);
		pc3 = probabilbity_of_touching_barrier(S3);
		pc4 = probabilbity_of_touching_barrier(S4);

		simulated_alive_call_average = (((has_path1_touched_barrier) ? (std::max(ZERO, S1 - strike_price)) : ZERO) +
			((has_path2_touched_barrier) ? (std::max(ZERO, S2 - strike_price)) : ZERO) +
			((has_path3_touched_barrier) ? (std::max(ZERO, S3 - strike_price)) : ZERO) +
			((has_path4_touched_barrier) ? (std::max(ZERO, S4 - strike_price)) : ZERO)) / 4;

		simulated_all_call_average = ((std::max(ZERO, ((1 - pc1)*(S1 - strike_price)))) +
			(std::max(ZERO, ((1 - pc2)*(S2 - strike_price)))) +
			(std::max(ZERO, ((1 - pc3)*(S3 - strike_price)))) +
			(std::max(ZERO, ((1 - pc4)*(S4 - strike_price))))) / 4;


		simulated_alive_put_average = (((has_path1_touched_barrier) ? (std::max(ZERO, strike_price - S1)) : ZERO) +
			((has_path2_touched_barrier) ? (std::max(ZERO, strike_price - S2)) : ZERO) +
			((has_path3_touched_barrier) ? (std::max(ZERO, strike_price - S3)) : ZERO) +
			((has_path4_touched_barrier) ? (std::max(ZERO, strike_price - S4)) : ZERO)) / 4;

		simulated_all_put_average = ((std::max(ZERO, ((1 - pc1)*(strike_price - S1)))) +
			(std::max(ZERO, ((1 - pc2)*(strike_price - S2)))) +
			(std::max(ZERO, ((1 - pc3)*(strike_price - S3)))) +
			(std::max(ZERO, ((1 - pc4)*(strike_price - S4))))) / 4;

		call_all_average += (simulated_all_call_average / no_of_trials);
		call_alive_average += (simulated_alive_call_average / no_of_trials);

		put_all_average += (simulated_all_put_average / no_of_trials);
		put_alive_average += (simulated_alive_put_average / no_of_trials);
	}

	call_all_average = call_all_average*exp(-risk_free_rate*expiration_time);
	call_alive_average = call_alive_average*exp(-risk_free_rate*expiration_time);

	put_all_average = put_all_average*exp(-risk_free_rate*expiration_time);
	put_alive_average = put_alive_average*exp(-risk_free_rate*expiration_time);

}

int main(int argc, char* argv[])
{
	sscanf_s(argv[1], "%lf", &expiration_time);
	sscanf_s(argv[2], "%lf", &risk_free_rate);
	sscanf_s(argv[3], "%lf", &volatility);
	sscanf_s(argv[4], "%lf", &initial_stock_price);
	sscanf_s(argv[5], "%lf", &strike_price);
	sscanf_s(argv[6], "%d", &no_of_trials);
	sscanf_s(argv[7], "%d", &no_of_divisions);
	sscanf_s(argv[8], "%lf", &barrier_price);

	expiration_time = 1;
	risk_free_rate = 0.05;
	volatility = 0.25;
	initial_stock_price = 50;
	strike_price = 40;
	barrier_price = 20;
	no_of_trials = 1000000;
	no_of_divisions = 1000;

	cout << "---------------------------------------------------------" << endl;
	cout << "European Down-and-Out Continuous Barrier Option Pricing via Monte Carlo Simuation" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Expiration Time (years)\t\t= " << expiration_time << endl;
	cout << "Risk Free Interest Rate\t\t= " << risk_free_rate << endl;
	cout << "Volatility (% of stock value)\t= " << volatility * 100 << endl;
	cout << "Initial Stock Price\t\t= " << initial_stock_price << endl;
	cout << "Strike Price\t\t\t= " << strike_price << endl;
	cout << "Barrier Price\t\t\t= " << barrier_price << endl;
	cout << "Number of Trials\t\t= " << no_of_trials << endl;
	cout << "Number of Divisions\t\t= " << no_of_divisions << endl;

	simulate_option_path();

	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "Average Call price by explicit simulation\t= " << call_alive_average << endl;
	cout << "Call price using (1-p) adjustment term\t\t= " << call_all_average << endl;
	cout << "Theoretical call price\t\t\t\t= " << closed_form_down_and_out_european_call_option() << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "Average Put price by explicit simulation\t= " << put_alive_average << endl;
	cout << "Put price using (1-p) adjustment term\t\t= " << put_all_average << endl;
	cout << "Theoretical Put price\t\t\t\t= " << closed_form_down_and_out_european_put_option() << endl;
	cout << "---------------------------------------------------------" << endl;

	return 0;
}

