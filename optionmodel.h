#ifndef OPTIONMODEL_H
#define OPTIONMODEL_H

class OptionModel {
public:
  OptionModel(double s, double k, double r, double t, double sigma);
  void printCalculations() const; // print all metrics
  virtual double price() const = 0; // calculate price from parameters
  virtual double delta() const = 0;
  virtual double gamma() const = 0;
  virtual double vega() const = 0;
  virtual double theta() const = 0;
  virtual double rho() const = 0;
protected:
  double phi(double x) const; // Normal CDF
  double s; // currStockPrice
  double k; // strikePrice
  double r; // risk-free interest
  double t; // time to maturity (years)
  double sigma; // volatility
};

class BlackScholes : public OptionModel {
public:
  BlackScholes(double s, double k, double r, double t, double sigma);
  double price() const; // calculate price from parameters
  double delta() const;
  double gamma() const;
  double vega() const;
  double theta() const;
  double rho() const;
private:
  // add data members as needed
};


#endif //OPTIONMODEL_H
