#include"stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <random>
#include <algorithm>
#define ZERO 0.0
#define UNITY 1.0

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


double probabilbity_of_touching_barrier(double current_stock_price)
{
	return exp(-((2 * log(initial_stock_price / barrier_price)*log(current_stock_price / barrier_price)) / (volatility*volatility*expiration_time)));
}

double calculate_pd(double pd, double current_stock_price, int time_ti)
{
	double sigma = sqrt((time_ti / no_of_divisions)*(1 - (time_ti / no_of_divisions)));
	double mean = initial_stock_price + (time_ti / no_of_divisions)*(current_stock_price - initial_stock_price);
	return pd*(1 - N((barrier_price - mean) / sigma));

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

	double pd1 = UNITY, pd2 = UNITY, pd3 = UNITY, pd4 = UNITY;

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

			pd1 = calculate_pd(pd1, S1, j);
			pd2 = calculate_pd(pd2, S2, j);
			pd3 = calculate_pd(pd3, S3, j);
			pd4 = calculate_pd(pd4, S4, j);

		}

		simulated_alive_call_average = (((has_path1_touched_barrier) ? (std::max(ZERO, S1 - strike_price)) : ZERO) +
			((has_path2_touched_barrier) ? (std::max(ZERO, S2 - strike_price)) : ZERO) +
			((has_path3_touched_barrier) ? (std::max(ZERO, S3 - strike_price)) : ZERO) +
			((has_path4_touched_barrier) ? (std::max(ZERO, S4 - strike_price)) : ZERO)) / 4;

		simulated_all_call_average = ((std::max(ZERO, ((pd1)*(S1 - strike_price)))) +
			(std::max(ZERO, ((pd2)*(S2 - strike_price)))) +
			(std::max(ZERO, ((pd3)*(S3 - strike_price)))) +
			(std::max(ZERO, ((pd4)*(S4 - strike_price))))) / 4;


		simulated_alive_put_average = (((has_path1_touched_barrier) ? (std::max(ZERO, strike_price - S1)) : ZERO) +
			((has_path2_touched_barrier) ? (std::max(ZERO, strike_price - S2)) : ZERO) +
			((has_path3_touched_barrier) ? (std::max(ZERO, strike_price - S3)) : ZERO) +
			((has_path4_touched_barrier) ? (std::max(ZERO, strike_price - S4)) : ZERO)) / 4;

		simulated_all_put_average = ((std::max(ZERO, ((pd1)*(strike_price - S1)))) +
			(std::max(ZERO, ((pd2)*(strike_price - S2)))) +
			(std::max(ZERO, ((pd3)*(strike_price - S3)))) +
			(std::max(ZERO, ((pd4)*(strike_price - S4))))) / 4;

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

	expiration_time = atof(argv[1]);
	risk_free_rate = atof(argv[2]);
	volatility = atof(argv[3]);
	initial_stock_price = atof(argv[4]);
	strike_price = atof(argv[5]);
	no_of_trials = atoi(argv[6]);
	no_of_divisions = atoi(argv[7]);
	barrier_price = atof(argv[8]);

	expiration_time = (double)expiration_time;
	risk_free_rate = (double)risk_free_rate;
	volatility = (double)volatility;
	initial_stock_price = (double)initial_stock_price;
	strike_price = (double)strike_price;
	barrier_price = (double)barrier_price;



	cout << "---------------------------------------------------------" << endl;
	cout << "European Down-and-Out Discrete Barrier Option Pricing via Monte Carlo Simuation" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Expiration Time (years)\t\t= " << expiration_time << endl;
	cout << "Risk Free Interest Rate\t\t= " << risk_free_rate << endl;
	cout << "Volatility (% of stock value)\t= " << volatility * 100 << endl;
	cout << "Initial Stock Price\t\t= " << initial_stock_price << endl;
	cout << "Strike Price\t\t\t= " << strike_price << endl;
	cout << "Barrier Price\t\t\t= " << barrier_price << endl;
	cout << "Number of Trials\t\t= " << no_of_trials << endl;
	cout << "Number of Discrete Barriers\t= " << no_of_divisions << endl;

	simulate_option_path();

	cout << "---------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "Average Call price by explicit simulation= " << call_alive_average << endl;
	cout << "Average Call price with Brownian-Bridge correction of the final price= " << call_all_average << endl;
	cout << "---------------------------------------------------------" << endl;

	cout << "Average Put price by explicit simulation= " << put_alive_average << endl;
	cout << "Average Put price with Brownian-Bridge correction of the final price= " << put_all_average << endl;
	cout << "---------------------------------------------------------" << endl;

	return 0;
}

