//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)


#ifndef UserInterfaceH 
#define UserInterfaceH

//---------------------------------------------------------------------------
//UserInterface: class declaration
//---------------------------------------------------------------------------

#include "constants.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class UserInterface {
public:
	void showByeScreen() const;

	int showMainMenuAndGetCommand() const;
	int showCardMenuAndGetCommand(const string& cardNum) const;
	int showAccountMenuAndGetCommand(const string& accNum) const;

	void showErrorInvalidCommand() const;
	void wait() const;
	void endProgram() const;
	const string readInCardToBeProcessed() const;
	void showValidateCardOnScreen(int validCode, const string& cardNum) const;
	void showCardAccounts(const string& cardNum, const string& cardSt) const;
	const string readInAccountToBeProcessed() const;
	void showValidateAccountOnScreen(int valid, const string& acctNum) const;

	static const string cardFilename(const string& cn);
	static const string accountFilename(const string& an);

	double readInWithdrawalAmount() const;
	double readInDepositAmount() const;

	int readInMiniStatmentAmount() const;

	void showProduceBalanceOnScreen(double bal) const;
	void showDepositOnScreen(bool auth, double deposit) const;
	void showWithdrawalOnScreen(bool auth, double withdrawal) const;
	void showStatementOnScreen(const string&) const;
	void showMiniStatementOnScreen(bool isEmpty,double total,string mad)const;
	void searchTransactions();
	void clearTransactionsToDate();
	void transferToAccount();


private:
	//support functions
	int readInCommand() const;
	double readInPositiveAmount() const;
	void outputHeader(const string&) const;
	string askForInput(const string&) const;
	void outputLine(const string&) const;
};

#endif
