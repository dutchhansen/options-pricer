#include <iostream>
#include "blackscholes.h"
#include <cmath>

using namespace std;

double BlackScholes::phi(double x) {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

void BlackScholes::getInput() {
    // get derivative parameters
    cout << "Enter the following: " << endl;
    cout << "Current stock price (USD): ";
    cin >> s;
    cout << "Strike price (USD): ";
    cin >> k;
    cout << "Risk-free interest (decimal): ";
    cin >> r;
    cout << "Time to maturity (years): ";
    cin >> t;
    cout << "Volatility of asset (decimal): ";
    cin >> sigma;
}

void BlackScholes::calculatePrice() {
    // calculate constants
    double d1 = log(s / k) + ((r + (pow(sigma, 2) / 2)) * t);
    d1 = d1 / (sigma * sqrt(t));
    double d2 = d1 - (sigma * sqrt(t));

    // update price
    c = s * phi(d1) - (k * exp(-1 * r * t)) * phi(d2);
}

void BlackScholes::printCalculation() const {
    cout << "Theoretical Premium: $ " << c << endl;
}
