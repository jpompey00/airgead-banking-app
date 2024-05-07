
#include "CLI.h"




void CLI::mainMenu()
{
	while (m_active == true) {

		startingInvestment();
		//checks if the exception set active to false to end the application
		if (!m_active) break; 
		system("pause");


		displayInitialData();
		system("pause");


		createChartHeader(true);
		m_airgeadBackend.printResult(m_airgeadBackend.getInitialInvestmentAmount(),
			m_airgeadBackend.getMonthlyDeposits(), m_airgeadBackend.getAnnualInterestPercent(),
			m_airgeadBackend.getNumberOfYears());

		system("pause");

		createChartHeader(false);
		m_airgeadBackend.printResult(m_airgeadBackend.getInitialInvestmentAmount(),
			0, m_airgeadBackend.getAnnualInterestPercent(),
			m_airgeadBackend.getNumberOfYears());
		

		//ends program
		m_active = false;
	}

	
}

//Prompts user for input used for the program. 
void CLI::startingInvestment() {
	
		try {
			long double input;
			std::cout << "Enter Initial Investment Amount: ";
			std::cin >> input;
			if (std::cin.fail()) {
				throw std::runtime_error("test");


			}
			else {
				m_airgeadBackend.setInitialInvestmentAmount(input);
				std::cout << "Enter Monthly Deposit: ";
				std::cin >> input;
				m_airgeadBackend.setMonthlyDeposits(input);
				std::cout << "Enter Annual Interest Percent: ";
				std::cin >> input;
				m_airgeadBackend.setAnnualInterestPercent(input);
				std::cout << "Enter Number of Years: ";
				std::cin >> input;
				m_airgeadBackend.setNumberOfYears(input);
			}


		}
		catch (std::runtime_error& excpt) {
			std::cout << "Please only enter a number" << std::endl;
	
			m_active = false;
		}

}

	

//displays a summary of the data that was inputted
void CLI::displayInitialData() {
	std::cout << "Initial Investment Amount: "<< m_airgeadBackend.getInitialInvestmentAmount() <<std::endl;
	std::cout << "Monthly Deposit: " << m_airgeadBackend.getMonthlyDeposits() << std::endl;
	std::cout << "Annual Interest Percent: " << m_airgeadBackend.getAnnualInterestPercent() << "%"<< std::endl;
	std::cout << "Number of Years: " << m_airgeadBackend.getNumberOfYears() << std::endl;
}

//creates the header for the chart based on if its including monthly deposits or not.
void CLI::createChartHeader(bool withMonthlyDeposits) {
	std::string headerMessage = "Balance and Interest Without Additional Monthly Deposits";
	m_space = "         "; //10 spaces
	
	if (withMonthlyDeposits) {
		headerMessage = "Balance and Interest With Additional Monthly Deposits";
	}
	else {
		headerMessage = "Balance and Interest Without Additional Monthly Deposits";
	}

	
	std::cout <<std::setfill(' ') << std::setw(30) << "          " <<
		headerMessage <<
		std::setw(30) << "          " << std::endl;


	
	std::cout << m_space << "Year";

	std::cout << m_space << m_space << m_space << m_space << "Year End Balance";

	std::cout << m_space << m_space << m_space << "Year End Earned Interest" << std::endl;

	std::cout << std::setfill('=') << std::setw(120) << "=" << std::endl;


}



