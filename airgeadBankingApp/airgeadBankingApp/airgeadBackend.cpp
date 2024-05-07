
#include "airgeadBackend.h"

//The accessor methods for the private variables
long double AirgeadBackend::getInitialInvestmentAmount()
{
	return m_initialInvestmentAmount;
}

void AirgeadBackend::setInitialInvestmentAmount(long double t_number) {
	this->m_initialInvestmentAmount = t_number;
}

long double AirgeadBackend::getMonthlyDeposits() {
	return m_monthlyDeposits;
}

void AirgeadBackend::setMonthlyDeposits(long double t_number) {
	this->m_monthlyDeposits = t_number;
}

long double AirgeadBackend::getAnnualInterestPercent() {
	return m_annualInterestPercent;
}

void AirgeadBackend::setAnnualInterestPercent(long double t_number) {
	this->m_annualInterestPercent = t_number;
}

long double AirgeadBackend::getNumberOfYears() {
	return m_numberOfYears;
}

void AirgeadBackend::setNumberOfYears(long double t_number) {
	this->m_numberOfYears = t_number;
}




//these methods do the calculations for the total, interest, and closing balance
long double AirgeadBackend::m_calculateTotal(long double t_openingAmount, long double  t_depositedAmount) {
	return t_openingAmount + t_depositedAmount;
}

long double AirgeadBackend::m_calculateInterest(long double t_total, long double t_interestRatePercentage) {
	return t_total * ((t_interestRatePercentage / 100) / 12);
}

long double AirgeadBackend::m_calculateClosingBalance(long double t_total, long double t_interestAmount) {
	return t_total + t_interestAmount;
}


//prints the results from the passed values into a chart.
void AirgeadBackend::printResult(long double t_initialInvestment, long double t_monthlyDeposit, long double t_interestPercent,
	long double t_years){

	//makes the values from the parameter into local variables so they can be modified
	//by subsequent loops.
	m_openingAmount = t_initialInvestment;
	m_depositiedAmount = t_monthlyDeposit;
	m_earnedInterest = 0;

	//loops through each month based on the years passed
	for (int i = 0; i < t_years*12; i++) {
		m_total = m_calculateTotal(m_openingAmount, t_monthlyDeposit);
		m_interestAmount = m_calculateInterest(m_total, t_interestPercent);
		m_closingBalance = m_calculateClosingBalance(m_total, m_interestAmount);
		m_earnedInterest += m_interestAmount;

		//every year will print out a summary.
		if (((i + 1) % 12) == 0 && i != 0) {

			m_formatChart((i / 12) + 1, m_closingBalance, m_earnedInterest);

			m_earnedInterest = 0;
		}
		m_openingAmount = m_closingBalance;
	}

}


//formats the spacing of the parameters into a chart thats readable.
void AirgeadBackend::m_formatChart(int t_year, long double t_yearEndBalance, 
	long double t_yearEndInterest) {
	std::string space = "         "; //10 spaces


	std::cout << std::fixed << std::setprecision(2) << space << t_year
		<< space << space << space << space << space 
		<< "$" << t_yearEndBalance <<
		space << space << space << space << space 
		<< "$" << t_yearEndInterest << "\n" << std::endl;


}
