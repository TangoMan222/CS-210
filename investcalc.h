#pragma once
#ifndef DRIVER_H_
#define DRIVER_H_

class investcalc {
public:
	// getters
	investcalc();
	int DisplayMenu();
	void projectScreen();
	double getDollarInput();
	int getNumInput();
	void InterestCalc(double InitialInvestment, double MonthlyDeposit, int Interest, int NumYears);

private:
	// variables
	double InitialInvestment;
	double MonthlyDeposit;
	int Interest;
	int NumYears;

};

#endif