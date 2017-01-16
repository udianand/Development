
#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#define PI 3.1415926
using namespace std;

vector < vector <double> > vec_european_call_option;
vector < vector <double> > vec_european_put_option;

double up_factor, uptick_prob, downtick_prob, notick_prob, risk_free_rate, strike_price;
double initial_stock_price, expiration_time, volatility, R;
int no_of_divisions;

//calculate the B-S model
vector<double> theoretical_pdf;
double theoretical_sum;

double N(const double & z) {
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
};

void initialize() {
	for (int k = 0; k<no_of_divisions; k++)
	{
		vector<double> temp;
		for (int i = 0; i<2 * k + 1; i++) {
			temp.push_back(-1.0);
		}
		vec_european_call_option.push_back(temp);
		vec_european_put_option.push_back(temp);
	}
}

double max(double a, double b) {
	return (b < a) ? a : b;
}

double european_call_option(int k, int i, double current_stock_price)
{
	if (k == no_of_divisions)
		return max(0.0, (current_stock_price - strike_price));
	else
	{

		if (-1.0 != vec_european_call_option[k][i + k]) {
			return vec_european_call_option[k][i + k];
		}
		else
		{
			vec_european_call_option[k][i + k] = (uptick_prob*european_call_option(k + 1, i + 1, current_stock_price*up_factor) + downtick_prob*european_call_option(k + 1, i - 1, current_stock_price / up_factor) + notick_prob*european_call_option(k + 1, i, current_stock_price)) / R;
			return vec_european_call_option[k][i + k];
		}
	}
}

double european_put_option(int k, int i, double current_stock_price)
{
	if (k == no_of_divisions)
		return max(0.0, (strike_price - current_stock_price));
	else
	{
		if (-1.0 != vec_european_put_option[k][i + k]) {
			return vec_european_put_option[k][i + k];
		}
		else
		{
			vec_european_put_option[k][i + k] = (uptick_prob*european_put_option(k + 1, i + 1, current_stock_price*up_factor) + downtick_prob*european_put_option(k + 1, i - 1, current_stock_price / up_factor) + notick_prob*european_put_option(k + 1, i, current_stock_price)) / R;
			return vec_european_put_option[k][i + k];
		}
	}
}

double bs_european_call_option() {
	double d1, d2;
	d1 = (log(initial_stock_price / strike_price) + (risk_free_rate + volatility*volatility / 2)*expiration_time) / (volatility*sqrt(expiration_time));
	d2 = d1 - volatility*sqrt(expiration_time);
	return initial_stock_price*N(d1) - strike_price*exp(-expiration_time*risk_free_rate)*N(d2);
}

double bs_european_put_option() {
	double d1, d2;
	d1 = (log(initial_stock_price / strike_price) + (risk_free_rate + volatility*volatility / 2)*expiration_time) / (volatility*sqrt(expiration_time));
	d2 = d1 - volatility*sqrt(expiration_time);
	return -initial_stock_price*(1 - N(d1)) + strike_price*exp(-expiration_time*risk_free_rate)*(1 - N(d2));
}

int main(int argc, char* argv[])
{

	sscanf_s(argv[1], "%lf", &expiration_time);
	sscanf_s(argv[2], "%d", &no_of_divisions);
	sscanf_s(argv[3], "%lf", &risk_free_rate);
	sscanf_s(argv[4], "%lf", &volatility);
	sscanf_s(argv[5], "%lf", &initial_stock_price);
	sscanf_s(argv[6], "%lf", &strike_price);


	R = exp(risk_free_rate*expiration_time / ((float)no_of_divisions));
	up_factor = exp(volatility*sqrt((2 * expiration_time) / ((float)no_of_divisions)));
	uptick_prob = pow((sqrt(R) - 1 / sqrt(up_factor)) / (sqrt(up_factor) - 1 / sqrt(up_factor)), 2);
	downtick_prob = pow((sqrt(up_factor) - sqrt(R)) / (sqrt(up_factor) - 1 / sqrt(up_factor)), 2);
	notick_prob = 1 - uptick_prob - downtick_prob;


	cout << "Recursive Trinomial European Option Pricing using Memoization." << endl;
	cout << "Expiration Time (Years) = " << expiration_time << endl;
	cout << "Number of Divisions = " << no_of_divisions << endl;
	cout << "Risk Free Interest Rate = " << risk_free_rate << endl;
	cout << "Volatility (%age of stock value) = " << volatility * 100 << endl;
	cout << "Initial Stock Price = " << initial_stock_price << endl;
	cout << "Strike Price = " << strike_price << endl;
	cout << "--------------------------------------" << endl;
	cout << "Up Factor = " << up_factor << endl;
	cout << "Uptick Probability = " << uptick_prob << endl;
	cout << "--------------------------------------" << endl;

	initialize();

	double call = european_call_option(0, 0, initial_stock_price);
	double put = european_put_option(0, 0, initial_stock_price);
	cout << "Trinomial Price of an European Call Option = " << call << endl;
	cout << "Call Price according to Black-Scholes = " << bs_european_call_option() << endl;
	cout << "--------------------------------------" << endl;
	cout << "Trinomial Price of an European Put Option = " << put << endl;
	cout << "Put Price according to Black-Scholes = " << bs_european_put_option() << endl;
	cout << "--------------------------------------" << endl;
	cout << "Verifying Put-Call Parity: S+P-C = Kexp(-r*T) for European Options" << endl;
	cout << initial_stock_price << " + " << put << " - " << call << " = " << strike_price << "exp(" << -risk_free_rate << " * " << expiration_time << ")" << endl;
	{
		if (initial_stock_price + put - call - strike_price*exp(-risk_free_rate*expiration_time)>0.000001)
		{
			cout << initial_stock_price + put - call << " ?=? " << strike_price*exp(-risk_free_rate*expiration_time) << endl;
			cout << "Looks like Put-Call Parity does NOT hold" << endl;
		}
		else
		{
			cout << initial_stock_price + put - call << " = " << strike_price*exp(-risk_free_rate*expiration_time) << endl;
			cout << "Looks like Put-Call Parity does hold" << endl;
		}
	}

	return 0;
}

