#include <iostream>
#include <iomanip>
#include <vector>
#include "investcalc.h"


using namespace std;
// displays menu and prints input prompts
int investcalc::DisplayMenu() {
	//header formatting
	cout << setw(33) << setfill('*') << "*" << endl;
	cout << setw(10) << setfill('*') << "*" << " Data Input " << setw(11) << setfill('*') << "*" << endl;

	//prompts user and calls getMoneyInput 
	cout << setw(28) << setfill(' ') << left << "Initial investment amount:";
	InitialInvestment = getDollarInput();
	cout << "$" << fixed << setprecision(2) << InitialInvestment << endl;//prints allowed user input
	
	//prompts user and calls getMoneyInput 
	cout << setw(28) << setfill(' ') << left << "Monthly deposit:";
	MonthlyDeposit = getDollarInput();
	cout << "$" << fixed << setprecision(2) << MonthlyDeposit << endl;//prints allowed user input

	//prompts user and calls getNumInput
	cout << setw(28) << setfill(' ') << left << "Annual interest:";
	Interest = getNumInput();
	cout << "%" << Interest << endl; //prints allowed user input
	
	//prompts user and calls getNumInput
	cout << setw(28) << setfill(' ') << left << "Number of years:";
	NumYears = getNumInput();
	cout << NumYears << endl; //prints allowed user input
	
	//prompts user with Press any key to continue...
	system("pause");
	return 0;

}
//prints final chart of calculations
void investcalc::projectScreen() {
	// header formatting
	cout << "    Balance and Interest with Additional Monthly Deposits" << endl;
	cout << setw(62) << setfill('=') << "=" << endl;
	cout << "  Year\t" << "   Year End Balance\t" << "   Year end Earned Interest" << endl;
	cout << setw(62) << setfill('-') << "-" << endl;

	// calls InterestCalc to get calulate final numbers with monthly deposits
	InterestCalc(this->InitialInvestment, this->MonthlyDeposit, this->Interest, this->NumYears);

	cout << endl;
	cout << endl;

	// header formatting
	cout << "   Balance and Interest without Additional Monthly Deposits" << endl;
	cout << setw(62) << setfill('=') << "=" << endl;
	cout << "  Year\t" << "   Year End Balance\t" << "   Year end Earned Interest" << endl;
	cout << setw(62) << setfill('-') << "-" << endl;

	// calls InterestCalc to get calulate final numbers without monthly deposits
	InterestCalc(this->InitialInvestment, 0, this->Interest, this->NumYears);



}
//calculates money at every year
void investcalc::InterestCalc(double InitialInvestment, double MonthlyDeposit, int Interest, int NumYears) {
	// required variables for calculations
	int i;
	int j;
	int k;
	double InvestmentAmount = InitialInvestment;
	const int MonthperYear = 12;
	double interestTotal = 0;
	double interestAmount = Interest;
	double compoundInterest;
	vector<double> interests; 

	//loops for each year
	for (i = 1; i <= NumYears; i++) {

		//loops for each month
		for (j = 1; j <= MonthperYear; j++) {

			InvestmentAmount = (InvestmentAmount + MonthlyDeposit);
			compoundInterest = InvestmentAmount * ((interestAmount / 100) / MonthperYear);
			InvestmentAmount = InvestmentAmount + compoundInterest;
			interests.push_back(compoundInterest);
		}
		
		for (k = 0; k < interests.size(); k++) {

			interestTotal = interests.at(k) + interestTotal;
		}
		//prints and formats amounts final calculations for each year
		cout << "     " << i << "\t\t     $" << InvestmentAmount << "\t\t\t     $" << interestTotal << endl;;

		interestTotal = 0;
		compoundInterest = 0;
		interests.resize(0);
	}
}
//verifys input is valid for doubles
double investcalc::getDollarInput() {
	// required variable and gets user input
	double userInput;
	cin >> userInput;
	
	//loops while input is not a positive number or is text
	while (!cin.good() || userInput < 0) { 
		cout << endl;
		
		//if input is not a positive number or is text
		if (!cin.good() || userInput < 0) {
			cout << "Please enter a positive number: " << endl;
		}
		//clears the input to accept new input.
		cin.clear();
		cin.ignore(LC_MAX, '\n');
		// reads new input from user
		cin >> userInput;
	}
	return userInput;
}
//verifys input is valid for ints
int investcalc::getNumInput() {
	// required variable and gets user input
	int userInput;
	cin >> userInput;
	
	//loops while input is not a positive number
	while (!cin.good() || userInput < 0) { 
		cout << endl;
		
		//if input is not a positive number
		if (!cin.good() || userInput < 0) {
			cout << "Please enter a positive number: " << endl;
		}
		//clears the input to accept new input.
		cin.clear();
		cin.ignore(LC_MAX, '\n');
		// reads new input from user
		cin >> userInput;
	}
	return userInput;
}
investcalc::investcalc() {

}
