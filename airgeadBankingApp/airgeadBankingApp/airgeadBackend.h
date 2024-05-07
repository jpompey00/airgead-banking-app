
#ifndef AIRGEADBANKINGAPP_AIRGEADBACKEND_H_
#define AIRGEADBANKINGAPP_AIRGEADBACKEND_H_




#include <iostream>
#include <string>
#include <iomanip>


class AirgeadBackend {
public:
	
	

	//accessor methods
	long double getInitialInvestmentAmount();
	void setInitialInvestmentAmount(long double t_number);

	long double getMonthlyDeposits();
	void setMonthlyDeposits(long double t_number);
	
	long double getAnnualInterestPercent();
	void setAnnualInterestPercent(long double t_number);
	
	long double getNumberOfYears();
	void setNumberOfYears(long double t_number);

	void printResult(long double t_interestPercent, long double t_initialInvestment, long double t_years,
		long double t_monthlyDeposit);

private:
	//methods used for calculation
	long double m_calculateTotal(long double t_openingAmount, long double  t_depositedAmount);
	long double m_calculateInterest(long double t_total, long double t_interestRatePercentage);
	long double m_calculateClosingBalance(long double t_total, long double t_interestAmount);
	void m_formatChart(int t_year, long double t_yearEndBalance,
		long double t_yearEndEarnedInterest);

	//The values from the input
	long double m_initialInvestmentAmount; //opening amount
	long double m_monthlyDeposits; //deposited amounts
	long double m_annualInterestPercent;
	long double m_numberOfYears;


	//values used for calcuation and printing
	long double m_total;
	long double m_interestAmount;
	long double m_closingBalance;
	long double m_openingAmount;
	long double m_depositiedAmount;
	long double m_earnedInterest;
};
#endif // !AIRGEADBANKINGAPP_AIRGEADBACKEND_H