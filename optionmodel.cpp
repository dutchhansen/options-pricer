#include <iostream>
#include "optionmodel.h"
#include <iomanip>
#include <cmath>

using namespace std;

// contructor for an option
OptionModel::OptionModel(double s, double k, double r, double t, double sigma)
: s(s), k(k), r(r), t(t), sigma(sigma) {
}

double s; // currStockPrice
double k; // strikePrice
double r; // risk-free interest
double t; // time to maturity (years)
double sigma; // volatility

void OptionModel::printCalculations() const {
  cout << "Theoretical Premium: $ " << setw(5) << price() << endl;
  cout << "Delta: " << setw(5) << delta() << endl;
  cout << "Gamma: " << setw(5) << gamma() << endl;
  cout << "Vega: " << setw(5) << vega() << endl;
  cout << "Theta: " << setw(5) << theta() << endl;
  cout << "Rho: " << setw(5) << rho() << endl;
}

// helper function for Normal CDF
double OptionModel::phi(double x) const {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

// constructor for Black Scholes model
BlackScholes::BlackScholes(double s, double k, double r, double t, double sigma)
: OptionModel(s, k, r, t, sigma) {
}

// pricing function for Black Scholes model
double BlackScholes::price() const {
  // calculate constants
  double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
  d1 = d1 / (sigma * sqrt(t));
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
    return 0.0;
}
double BlackScholes::vega() const {
    return 0.0;
}
double BlackScholes::theta() const {
    return 0.0;
}
double BlackScholes::rho() const {
    return 0.0;
}