#include <iostream>
#include <string>
#include "optionmodel.h"

using namespace std;

// get input from getUserInput
void getUserInput(double& s, double& k, double& r, double& t, double& sigma, string& type) {
    cout << "Input option parameters:" << endl;
    cout << "Underlying Asset Price (USD): " << endl;
    cin >> s;
    cout << "Strike Price (USD): " << endl;
    cin >> k;
    cout << "Risk-Free Interest Rate (decimal): " << endl;
    cin >> r;
    cout << "Time to maturity (years): " << endl;
    cin >> t;
    cout << "Volatility (decimal): " << endl;
    cin >> sigma;
    cout << "Option type (CALL/PUT): " << endl;
    cin >> type;
    while (type != "CALL" && type != "PUT") {
    cout << "Enter a valid option type: " << endl;
    cin >> type;
    }
}

// collect input from user
int main() {
    cout << "**************" << endl;
    cout << "OPTIONS PRICER. Select option model." << endl;
    cout << "**************" << endl;

    // get user to select option model for pricing
//    char selection = 'z';
//    while (selection != 'A') {
//      cout << "(A) Black Scholes" << endl;
//      cin >> selection;
//    }
//
//    // price based on option
//    if (selection == 'A') {
//        double s, k, r, t, sigma;
//        string type;
//        getUserInput(s, k, r, t, sigma, type);
//        BlackScholes model(s, k, r, t, sigma, type);
//        model.printCalculations();
//    }

        string type = "PUT";
        BlackScholes model(300.0, 250.0, 0.03, 1, 0.15, type);
        model.printCalculations();

//    BlackScholes model(30, 50, 0.03, 1, 0.3, "CALL");
//    int x;
//    cin >> x;
//    cout << model.pdf(x) << endl;
}