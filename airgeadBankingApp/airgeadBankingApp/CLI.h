#ifndef AIRGEADBANKINGAPP_CLI_H_
#define AIRGEADBANKINGAPP_CLI_H_

#include <iostream>
#include <string>
#include "airgeadBackend.h"


class CLI { //The CLI will not return any value.
private:
	AirgeadBackend m_airgeadBackend;

	bool m_active = true;
	std::string m_space;
	

public:
	void mainMenu();
	void displayInitialData();
	void startingInvestment();
	void createChartHeader(bool t_withMonthlyDeposits);
	
};

#endif AIRGEADBANKINGAPP_CLI_H_