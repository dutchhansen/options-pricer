#ifndef OPTIONMODEL_H
#define OPTIONMODEL_H
# include <string>

class OptionModel {
public:
  OptionModel(double s, double k, double r, double t, double sigma, std::string type);
  void printCalculations() const; // print all metrics
  virtual double callPrice() const = 0; // calculate price from parameters
  virtual double delta() const = 0;
  virtual double gamma() const = 0;
  virtual double vega() const = 0;
  virtual double theta() const = 0;
  virtual double rho() const = 0;
protected:
  double phi(double x) const; // Standard Normal CDF
  double pdf(double x) const; // Standard Normal PDF
  double s; // currStockPrice
  double k; // strikePrice
  double r; // risk-free interest
  double t; // time to maturity (years)
  double sigma; // volatility
  std::string type; // call or put
};

class BlackScholes : public OptionModel {
public:
  BlackScholes(double s, double k, double r, double t, double sigma, std::string type);
  double callPrice() const; // calculate price from parameters
  double delta() const;  // FIXME: IS this necessary?
  double gamma() const;
  double vega() const;
  double theta() const;
  double rho() const;
private:
  // add data members as needed
};


#endif //OPTIONMODEL_H
