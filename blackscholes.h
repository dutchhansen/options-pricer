#ifndef OPTIONS_PRICER_BLACKSCHOLES_H
#define OPTIONS_PRICER_BLACKSCHOLES_H

class BlackScholes {
public:
    void getInput();
    void calculatePrice();
    void printCalculation() const;
private:
    double phi(double x);
    double c; // callPrice
    double s; // currStockPrice
    double k; // strikePrice
    double r; // risk-free interest
    double t; // time to maturity (years)
    double sigma; // volatility
};


#endif //OPTIONS_PRICER_BLACKSCHOLES_H
