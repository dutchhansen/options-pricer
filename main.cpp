#include <iostream>
#include "blackscholes.h"

using namespace std;

// collect input from user
int main() {
    cout << "Welcome to options pricer!" << endl;

    BlackScholes model;
    model.getInput();
    model.calculatePrice();
    model.printCalculation();
}