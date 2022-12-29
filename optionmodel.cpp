#include <iostream>
#include "optionmodel.h"
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// contructor for an option
OptionModel::OptionModel(double s, double k, double r, double t, double sigma, string type)
: s(s), k(k), r(r), t(t), sigma(sigma), type(type) {
}

double s; // currStockPrice
double k; // strikePrice
double r; // risk-free interest
double t; // time to maturity (years)
double sigma; // volatility
string type; // call or put

void OptionModel::printCalculations() const {
  cout << endl;
  cout << "Theoretical Premium for " << type << " Option: $ " << setw(5) << callPrice() << endl;
  cout << "Delta: " << setw(5) << delta() << endl;
  cout << "Gamma: " << setw(5) << gamma() << endl;
  cout << "Vega: " << setw(5) << vega() << endl;
  cout << "Theta: " << setw(5) << theta() << endl;
  cout << "Rho: " << setw(5) << rho() << endl;
}

// helper function for Standard Normal CDF
double OptionModel::phi(double x) const {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

// heler function for Standarf Normal PDF
double OptionModel::pdf(double x) const {
  return (M_SQRT1_2 * sqrt(M_1_PI)) * exp(- pow(x, 2) / 2);
}

// constructor for Black Scholes model
BlackScholes::BlackScholes(double s, double k, double r, double t, double sigma, string type)
: OptionModel(s, k, r, t, sigma, type) {
}

// pricing function for Black Scholes model
double BlackScholes::callPrice() const {
  // calculate constants
  // d1
  double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
  d1 = d1 / (sigma * sqrt(t));
  // d2
  double d2 = d1 - (sigma * sqrt(t));

  // calculate price
  double c = s * phi(d1) - (k * exp(-1 * r * t)) * phi(d2);

  // return price
  return c;
}

// calculate Delta
double BlackScholes::delta() const {
    return 0.0;
}

double BlackScholes::gamma() const {
    // calculate constants
    // d1
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));

    // calculate Gamma
    double gamma = pdf(d1) / (s * sigma * sqrt(t));
    return gamma;
}

double BlackScholes::vega() const {
    // calculate constants
    // d1
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));

    // calculate Vega
    double vega = s * pdf(d1) * sqrt(t);
    return vega;  // FIXME: off by a factor of 10
}

double BlackScholes::theta() const {
    return 0.0;
}

double BlackScholes::rho() const {
    return 0.0;
}