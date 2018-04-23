//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#ifndef BankAccountH
#define BankAccountH

//---------------------------------------------------------------------------
//BankAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
#include "TransactionList.h"

#include <fstream>
#include <cassert>
using namespace std;


class BankAccount {
public:
    //constructors & destructor
	BankAccount();
    ~BankAccount();

	//getter (assessor) functions
    const string getAccountNumber() const;
    const Date getCreationDate() const;
	double getBalance() const;
    const TransactionList getTransactions() const;
    bool	isEmptyTransactionList() const;

	//other operations
	const string prepareFormattedStatement() const;
    void recordDeposit(double amount);
	double maxBorrowable() const;
	bool canWithdraw(double amount) const;
    void recordWithdrawal(double amount);
	double getTotalTransactions(double amount);
	

	void readInBankAccountFromFile(const string& fileName);
	void storeBankAccountInFile(const string& fileName) const;
	//functions to put data into and get data from streams
	ostream& putDataInStream(ostream& os) const;
	ostream& putAccountDetailsInStream(ostream& os) const;
	istream& getDataFromStream(istream& is);
	istream& getAccountDataFromStream(istream& is);

	const string prepareFormattedAccountDetails() const;
	const string prepareFormattedTransactionList() const;
	const string produceNMostRecentTransactions(int recentTrans) const;

	static const string getAccountType(const string& filename);
	static const string getAccountType(char n);
	
private:
    //data items
    string accountNumber_;
    Date   creationDate_;
	double balance_;
    TransactionList transactions_;
	int amount_;
 
	//support functions
	void updateBalance(double amount);
	ostream& putTransactionInStream(ostream& os) const;
	istream& getTransactionsDataFromStream(istream& is);
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream&, const BankAccount&);	//output operator
istream& operator>>(istream&, BankAccount&);	    //input operator

#endif
