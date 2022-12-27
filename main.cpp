#include <iostream>

#include "optionmodel.h"

using namespace std;

// get input from getUserInput
void getUserInput(double& s, double& k, double& r, double& t, double& sigma, string& type) {
  cout << "Input option parameters:" << endl;
  cout << "Underlying Asset Price: " << endl;
  cin >> s;
  cout << "Strike Price: " << endl;
  cin >> k;
  cout << "Risk-Free Interest Rate: " << endl;
  cin >> r;
  cout << "Time to maturity (years): " << endl;
  cin >> t;
  cout << "Volatility: " << endl;
  cin >> sigma;
  cout << "Option type: " << endl;
  cin >> type;
}

// collect input from user
int main() {
    cout << "**************" << endl;
    cout << "OPTIONS PRICER. Select option model." << endl;
    cout << "**************" << endl;

    // get user to select option model for pricing
    char selection = 'z';
    while (selection != 'A') {
      cout << "(A) Black Scholes" << endl;
      cin >> selection;
    }

    // price based on option
    if (selection == 'A') {
        double s, k, r, t, sigma;
        string type;
        getUserInput(s, k, r, t, sigma, type);
        BlackScholes model(s, k, r, t, sigma, type);
        model.printCalculations();
    }
}