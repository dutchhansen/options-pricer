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

void OptionModel::printCalculations() const {
    cout << endl;
    cout << "Theoretical Premium for " << type << " Option: $ ";
    cout << setw(5) << setprecision(3) << fixed << callPrice() << endl;

    // metrics
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
    double c;

    // CALL option
    if (type == "CALL") {
        c = s * phi(d1) - (k * exp(-r * t) * phi(d2));
    }
    // PUT option
    else {
        c = (phi(-d2) * k * exp(-r * t)) - (phi(-d1) * s);
    }

    // return price
    return c;
}


double BlackScholes::delta() const {
    // calculate constants
    // d1
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));
    double delta;

    // CALL option
    if (type == "CALL") {
        delta = phi(d1);
    }
    // PUT option
    else {
        delta = phi(d1) - 1;
    }

    return delta;
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
    // calculate constants
    // d1
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));
    // d2
    double d2 = d1 - (sigma * sqrt(t));
    double theta;

    // for CALL options
    if (type == "CALL") {
        theta = -(s * pdf(d1) * sigma) / (2 * t);
        theta -= (r * k) * exp(-r * t) * phi(d2);
    }
    // PUT option
    else {
        theta = -(s * pdf(d1) * sigma) / (2 * t);
        theta += (r * k) * exp(-r * t) * phi(-d2);
    }

    // for PUT options
    return theta;
}

double BlackScholes::rho() const {
    // calculate constants
    // d1
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));
    // d2
    double d2 = d1 - (sigma * sqrt(t));
    double rho;

    // for CALL options
    if (type == "CALL") {
        rho = (k * t) * exp(-r * t) * phi(d2);
    }
    // PUT option
    else {
        rho = (-k * t) * exp(-r * t) * phi(-d2);
    }

    // for PUT options
    return rho;
}