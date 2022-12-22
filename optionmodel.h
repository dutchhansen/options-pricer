#ifndef OPTIONMODEL_H
#define OPTIONMODEL_H

class OptionModel {
public:
  OptionModel(double s, double k, double r, double t, double sigma);
  void printCalculations(); // print all metrics
  virtual double price() = 0; // calculate price from parameters
  virtual double delta() = 0;
  virtual double gamma() = 0;
  virtual double vega() = 0;
  virtual double theta() = 0;
  virtual double rho() = 0;
protected:
  double phi(double x); // Normal CDF
  double s; // currStockPrice
  double k; // strikePrice
  double r; // risk-free interest
  double t; // time to maturity (years)
  double sigma; // volatility
};

class BlackScholes : public OptionModel {
public:
  BlackScholes(double c, double s, double k, double r, double t, double sigma);
private:
  // add data members as needed
};


#endif //OPTIONMODEL_H
