//Pascale Vacher - February 18
//OOP Assignment Task 1c - Semester 2
//Group Number:
//Team: (indicate member names, students numbers and courses)

#include "UserInterface.h" 

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

void UserInterface::wait() const
{
	cout << "\n";
	outputLine("Press RETURN to go back to menu...");
	char ch;
	cin.get(ch);
	cin.get(ch);
}
void UserInterface::endProgram() const
{
	cout << "\n";
	outputLine("Press RETURN to end program...");
	char ch;
	cin.get(ch);
	cin.get(ch);
}
int UserInterface::showMainMenuAndGetCommand() const
{
	system("cls");
	cout << "\n\n";
	outputHeader("WELCOME TO THE ATM");
	outputLine(" 0                            Leave ATM ");
	outputLine(" 1                      Enter your card ");
	outputLine("----------------------------------------");
	return (readInCommand());
}

int UserInterface::showAccountMenuAndGetCommand(const string& accNum) const
{
	outputHeader("ACCOUNT " + accNum + " MENU");
	outputLine(" 0                    Back to card menu ");
	outputLine(" 1                      Display balance ");
	outputLine(" 2                Withdraw from account ");
	outputLine(" 3                 Deposit into account ");
	outputLine(" 4                       Show statement ");
	outputLine(" 5                    Show all deposits  // TO BE IMPLEMENTED FOR Task 1c Preparation");
	outputLine(" 6                  Show mini statement  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 7                  Search Transactions  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 8    Clear all transactions up to date  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine(" 9          Transfer to another account  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine("----------------------------------------");
	return (readInCommand());
}

const string UserInterface::readInCardToBeProcessed() const {
	return askForInput("ENTER YOUR CARD NUMBER");
}

void UserInterface::showValidateCardOnScreen(int validCode, const string& cardNumber) const
{
	switch (validCode)
	{
	case VALID_CARD: {
		// Card exists and is accessible (and is not already open: TO BE IMPLEMENTED)
	} break;
	case UNKNOWN_CARD: {
		outputLine("ERROR: CARD " + cardNumber + " DOES NOT EXIST");
	} break;
	case EMPTY_CARD: {
		outputLine("ERROR: CARD " + cardNumber + " DOES NOT LINK TO ANY ACCOUNTS");
	} break;
	}
}

int UserInterface::showCardMenuAndGetCommand(const string& cardNumber) const
{
	outputHeader("CARD " + cardNumber + " MENU");
	outputLine(" 0           Stop banking & remove card ");
	outputLine(" 1            Manage individual account ");
	outputLine(" 2           Show total funds available  // TO BE IMPLEMENTED FOR Task 1c");
	outputLine("----------------------------------------");
	return (readInCommand());
}

void UserInterface::showCardAccounts(const string& cardNumber, const string& cardDetails) const
{
	outputHeader("CARD " + cardNumber + " ACCOUNTS");
	cout << cardDetails;
	outputLine("----------------------------------------\n");
}

const string UserInterface::readInAccountToBeProcessed() const {
	return askForInput("SELECT ACCOUNT TO MANAGE");
}

void UserInterface::showValidateAccountOnScreen(int validCode, const string& accNum) const
{
	switch (validCode)
	{
	case VALID_ACCOUNT:
	{
		// Account exists and is accessible with that card (and not already open: TO BE IMPLEMENTED)
	} break;
	case INVALID_ACCOUNT_TYPE:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " IS NOT A RECOGNISED TYPE OF ACCOUNT!");
	} break;
	case UNKNOWN_ACCOUNT:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " DOES NOT EXIST!");
	} break;
	case UNACCESSIBLE_ACCOUNT:
	{
		outputLine("ERROR: ACCOUNT " + accNum + " IS NOT ACCESSIBLE WITH THIS CARD!");
	} break;
	}
}

//static 
const string UserInterface::cardFilename(const string& cn) {
	//read in card name & produce cashcard filename
	return FILEPATH + "card_" + cn + ".txt";	//read in card name & produce cashcard filename
}
//static
const string UserInterface::accountFilename(const string& an) {
	return FILEPATH + "account_" + an + ".txt";
}

//input functions

double UserInterface::readInWithdrawalAmount() const {
	//ask for the amount to withdraw
	outputLine("AMOUNT TO WITHDRAW: \234");
	return (readInPositiveAmount());
}
double UserInterface::readInDepositAmount() const {
	//ask for the amount to deposit
	outputLine("AMOUNT TO DEPOSIT: \234");
	return (readInPositiveAmount());
}

int UserInterface::readInMiniStatmentAmount() const
{
	//ask for the amount of transactions to return
	outputLine("number of required transactions? ");
	return (readInPositiveAmount());
}


//output functions

void UserInterface::showProduceBalanceOnScreen(double balance) const
{
	cout << "\n      THE CURRENT BALANCE IS: " << fixed << setprecision(2) << setfill(' ') << "\234" << setw(12) << balance;
}

void UserInterface::showWithdrawalOnScreen(bool trAuthorised, double withdrawnAmount) const
{
	if (trAuthorised)
	{
		cout << "\n      TRANSACTION AUTHORISED. \234" << setw(0) << withdrawnAmount << " WITHDRAWN FROM ACCOUNT";
	}
	else
	{
		outputLine("TRANSACTION IMPOSSIBLE!"); // not enough money
	}
}

void UserInterface::showDepositOnScreen(bool trAuthorised, double depositAmount) const
{
	if (trAuthorised)
	{
		cout << "\n      TRANSACTION AUTHORISED. \234" << setw(0) << depositAmount << " DEPOSITED INTO ACCOUNT";
	}
	else
	{
		outputLine("TRANSACTION IMPOSSIBLE!"); // too much to deposit
	}
}


void UserInterface::showStatementOnScreen(const string& statement) const {
	outputHeader("PREPARING STATEMENT...");
	cout << statement;
	outputLine("----------------------------------------\n");
}

void UserInterface::showMiniStatementOnScreen(bool isEmpty, double total, string mad) const
{

	if (isEmpty)

	{
		outputHeader("No TRANSACTIONS");

	}

	else


	{

		cout << total << mad;
		outputLine("----------------------------------------\n");

	}

}

void UserInterface::searchTransactions()
{
}

void UserInterface::clearTransactionsToDate()
{
}

void UserInterface::transferToAccount()
{
}

//---------------------------------------------------------------------------
// private support member functions
//---------------------------------------------------------------------------

void UserInterface::showByeScreen() const
{
	outputLine("");
	outputHeader("THANK YOU FOR USING THE ATM");
	endProgram();
}

int UserInterface::readInCommand() const
{
	cout << "\n";
	outputLine("ENTER YOUR COMMAND: ");
	int com;
	cin >> com;
	return com;
}

void UserInterface::showErrorInvalidCommand() const
{
	outputLine("INVALID COMMAND CHOICE, TRY AGAIN");
}

double UserInterface::readInPositiveAmount() const
{
	double amount;
	cin >> amount;

	while (amount <= 0.0)
	{
		outputLine("AMOUNT SHOULD BE A POSITIVE AMOUNT, TRY AGAIN: ");
		cin >> amount;
	}

	return amount;
}

void UserInterface::outputHeader(const string& header) const
{
	// calculate lengths so we can centre the header
	const int length = header.size();
	const int borderWidth = 40;
	const int leftSpacePad = 6;
	const int paddingRequired = ((borderWidth - length) / 2) + leftSpacePad;

	outputLine("========================================");
	cout << "\n" << setfill(' ') << setw(paddingRequired) << ' ' << header;
	outputLine("========================================");
}

string UserInterface::askForInput(const string& promptForUser) const
{
	outputLine(promptForUser + ": ");
	string userInput;
	cin >> userInput;
	return userInput;
}

void UserInterface::outputLine(const string& text) const
{
	cout << "\n      " << text;
}