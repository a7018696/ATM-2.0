//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "TransactionList.h"

//---------------------------------------------------------------------------
//TransactionList: class implementation
//---------------------------------------------------------------------------

//____public member functions

//____constructors & destructors

//____other public member functions

void TransactionList::addNewTransaction(const Transaction& tr) {
    listOfTransactions_.addInFront(tr);
}
const Transaction TransactionList::newestTransaction() const {
    return (listOfTransactions_.first());
}
const TransactionList TransactionList::olderTransactions() const {
	TransactionList trlist(*this);
    trlist.deleteFirstTransaction();
    return trlist;
}
void TransactionList::deleteFirstTransaction() {
    listOfTransactions_.deleteFirst();
}
void TransactionList::deleteGivenTransaction(const Transaction& tr) {
    listOfTransactions_.deleteOne(tr);
}
int TransactionList::size() const {
    return (listOfTransactions_.length());
}

const string TransactionList::toFormattedString() const {
//return transaction list as a (formatted) string
	ostringstream os_transactionlist;
    TransactionList tempTrList(*this);
	while (! (tempTrList.size() == 0))
    {
		os_transactionlist << endl << tempTrList.newestTransaction().toFormattedString();
        tempTrList.deleteFirstTransaction();
    }
	return (os_transactionlist.str());
}

const string TransactionList::toFormattedString2(int size) const {
	//return transaction list as a (formatted) string
	ostringstream os_transactionlist;
	TransactionList tempTrList(*this);
	for(int i = 0; i < size; i++)
	{
		os_transactionlist << endl << tempTrList.newestTransaction().toFormattedString();
		tempTrList.deleteFirstTransaction();
	}
	return (os_transactionlist.str());
}

ostream& TransactionList::putDataInStream(ostream& os) const {
//put (unformatted) transaction list into an output stream
    TransactionList tempTrList(*this);
	while (! (tempTrList.size() == 0))
    {
		os << tempTrList.newestTransaction() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return os;
}
istream& TransactionList::getDataFromStream(istream& is) {
//read in (unformatted) transaction list from input stream
	Transaction aTransaction;
	is >> aTransaction;	//read first transaction
	while (is) 	//while not end of file
	{
		listOfTransactions_.addAtEnd(aTransaction);   //add transaction to list of transactions
		is >> aTransaction;	//read in next transaction
	}
	return is;
}




//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<(ostream& os, const TransactionList& aTransactionList) {
    return (aTransactionList.putDataInStream(os));
}
istream& operator>>(istream& is, TransactionList& aTransactionList) {
	return (aTransactionList.getDataFromStream(is));
}
