#include <iostream> //basics bruh
#include <iomanip> //lets us play with cout
#include <fstream> //lets us save the usernames and passwords into a file
#include <string> //lets the username and password be any combination of letters and numbers
#include <Windows.h> //lets us move the console around
//---------------------------------------------
using namespace std;


//declaring our prototype functions
void cinCleaner();
void vaultBoyMenu();
void vaultBoyLogin();
void vaultBoyExit();
int displayMenu();
void createAccount();
void windowsSetup();
int loginInterface();
void AdminSide();
void UserSide();

bool login();

//---------------------------------------------
//declare booleans to let the program loop correctly
bool programIsRunning = true;
bool userIsLoggedIn;
bool RunNextProgramAdmin;
bool RunNextProgramUser;

bool isUserAdmin; //global bool that the login function has access too
				  //---------------------------------------------
string username; //global username string to store it to be used accross the program

				 //----------------------------------------------
				 /*This was a Intro to Programming project where we were introduced to file systems, the use of global variables were not yet restricted however I am aware
				 of the potential issues these cause. Throughout object oriented programming and Data structures no global variables are used and everything
				 is passed via pointers, references or inheritence.*/
				 //----------------------------------------------
				 // Main, gonna try to include the state machine
int main() {
	//we're creating the accountCodeFile & userAccount file here
	// Boolean to keep state machine running
	bool run = true;
	int mode = 0;
	int useradmin;
	windowsSetup();
	while (run == true) {
		// Switch statement.  This will determine the mode of the user.  It starts with mode 1, which is the login screen.
		switch (mode) {

			// Main Interface Mode
		case 0:
			vaultBoyMenu();
			mode = displayMenu();
			break;

			// Login Mode
		case 1:


			useradmin = loginInterface();
			// Sub-Mode Switch Statements for User and Admin functionalities
			switch (useradmin) {
				// Admin Branch of the Program
			case 1:

				AdminSide();

				break;
				//User Branch of the Program
			case 2:
				UserSide();
				break;
			}


			mode = 0;
			break;

			// Account Creation Mode
		case 2:
			createAccount();
			mode = 0;
			break;

			// Exit Mode
		case 3:
			cout << "You are exiting the Vault.  Thank you for using Brandon-Tech!" << endl;
			return 0;

		}
	}

}



void vaultBoyMenu() {
	//Vaultboy Ascii Art -------------------------------------------------------	
	cout << "..............................................................................." << endl;
	cout << "....WELCOME...................................pGPQGp..........................." << endl;
	cout << "......TO............................p....pGPPGO..(QPsPPG......................." << endl;
	cout << ".....THE..........................pOGppdO)......))PQQQQQPp....................." << endl;
	cout << ".......VAULT......................Q....)QdGGQpGGGGQPQQPQPPPQ..................." << endl;
	cout << "..................................QQ..QS).........sPGODDSQPsQ)................." << endl;
	cout << ".................................(Q.SQdG........Pb).....pGPQQQ................." << endl;
	cout << "..................................(G..............(....QbQQQQQ................." << endl;
	cout << "..................................Q..(QO..(C..(GQQ.....qQQbpQb................." << endl;
	cout << ".........pdSp....................(b...)..pO......).....SQbbQG.................." << endl;
	cout << ".......()...(b...................SO.....SQ.............Sp.QG..................." << endl;
	cout << ".......Q....S....................Sp......).....QQ.........(Q..................." << endl;
	cout << ".......Q....Q....................(Q.QQDPGPPGO)QpSG........pG..................." << endl;
	cout << ".......QQ)...bQ...................SQ...PGGGGGO........QQGO)...................." << endl;
	cout << "..(GO)))).PGp))SQ..................SQ....PG.........QQQ........................" << endl;
	cout << "..SQ.........Q..(QQQpQp)..........).QQQQ..........dGQbs)Qbp...................." << endl;
	cout << "...QOD))DDGGQG...GQQPssssPPPPsssssssQQQ.PGpQpQ)...QG....QQQQQGp................" << endl;
	cout << "..(Q.........Sp.Qs(QQQQQQQQQQQQQQQQQQQQ...(GGGGGGOs...QGQQQQQQQQGp............." << endl;
	cout << "....SO)DDPGGQQ..S.(QQQQQQQQQQQQQQQQQQQsGp..........QpGQQQQQQQQQQQQPQQ.........." << endl;
	cout << "....QQ......pG.p)QQQQQQQQQQQppppQQQQQQQQb......pGGQQQQQQQQQQQQQQQQQQQGQ........" << endl;
	cout << ".....(GbQQQQpdCQQQQQQQQQQQQGGGO(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQGp......" << endl;
	cout << "..............))DDDD)))))......(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQQQb....." << endl;
	cout << "...............................(QQQQQQQb......QQQQQQQQQQQQGGQQQQQQQQQQQQQQQp..." << endl;
	cout << "................................QQQQQQQb.....(QQQQQQQQQQQQQQQO.DGGQQQQQQQQQC..." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQG..(QQQQQQQQQQG...." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQO.pQQQQQQQQQQG....." << endl;
	cout << "................................(GQQQQSO.....(QQQQQQQQQQQQQQ.pQQQQQQQQQQG......" << endl;
	cout << ".................................Q.)PGQb.....(QQQQQQQQQQQGQQpQQQQQQQQQQG......." << endl;
	cout << ".................................Q............PGGGGGOD.s..SQGGQQQQQQQQC........" << endl;
	cout << ".................................(p.......................(Q..sPGGQQG.........." << endl;
	cout << ".................................(QGqQ)................)QpQQ.....pODQ.........." << endl;
	cout << "..................................QpQs(QGGGGGppSGGGGGGQQQQQQQ....PQ.QC........." << endl;
	cout << "..................................QQQQQQQQQQQQQQQQQQQQQQQQQQQQbeeqqdC.........." << endl;
	cout << "..................................SQQQQQQQQQQQQQQQQQQQQQQQQQQQQ................" << endl;
	cout << ".....................................PSQQQQQQQQQQQQQQQQQQQQGGGO................" << endl;
	cout << "...........................................)DDPGGGOOD)........................." << endl;
	//End Ascii Text Graphic -----------------------------------------------------
}
void vaultBoyExit() {
	//Vaultboy Ascii Art -------------------------------------------------------
	cout << "..............................................................................." << endl;
	cout << "....THANK YOU.................................pGPQGp..........................." << endl;
	cout << "......FOR USING.....................p....pGPPGO..(QPsPPG......................." << endl;
	cout << ".....THE..........................pOGppdO)......))PQQQQQPp....................." << endl;
	cout << ".......VAULT......................Q....)QdGGQpGGGGQPQQPQPPPQ..................." << endl;
	cout << "..................................QQ..QS).........sPGODDSQPsQ)................." << endl;
	cout << ".................................(Q.SQdG........Pb).....pGPQQQ................." << endl;
	cout << "..................................(G..............(....QbQQQQQ................." << endl;
	cout << "..................................Q..(QO..(C..(GQQ.....qQQbpQb................." << endl;
	cout << ".........pdSp....................(b...)..pO......).....SQbbQG.................." << endl;
	cout << ".......()...(b...................SO.....SQ.............Sp.QG..................." << endl;
	cout << ".......Q....S....................Sp......).....QQ.........(Q..................." << endl;
	cout << ".......Q....Q....................(Q.QQDPGPPGO)QpSG........pG..................." << endl;
	cout << ".......QQ)...bQ...................SQ...PGGGGGO........QQGO)...................." << endl;
	cout << "..(GO)))).PGp))SQ..................SQ....PG.........QQQ........................" << endl;
	cout << "..SQ.........Q..(QQQpQp)..........).QQQQ..........dGQbs)Qbp...................." << endl;
	cout << "...QOD))DDGGQG...GQQPssssPPPPsssssssQQQ.PGpQpQ)...QG....QQQQQGp................" << endl;
	cout << "..(Q.........Sp.Qs(QQQQQQQQQQQQQQQQQQQQ...(GGGGGGOs...QGQQQQQQQQGp............." << endl;
	cout << "....SO)DDPGGQQ..S.(QQQQQQQQQQQQQQQQQQQsGp..........QpGQQQQQQQQQQQQPQQ.........." << endl;
	cout << "....QQ......pG.p)QQQQQQQQQQQppppQQQQQQQQb......pGGQQQQQQQQQQQQQQQQQQQGQ........" << endl;
	cout << ".....(GbQQQQpdCQQQQQQQQQQQQGGGO(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQGp......" << endl;
	cout << "..............))DDDD)))))......(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQQQb....." << endl;
	cout << "...............................(QQQQQQQb......QQQQQQQQQQQQGGQQQQQQQQQQQQQQQp..." << endl;
	cout << "................................QQQQQQQb.....(QQQQQQQQQQQQQQQO.DGGQQQQQQQQQC..." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQG..(QQQQQQQQQQG...." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQO.pQQQQQQQQQQG....." << endl;
	cout << "................................(GQQQQSO.....(QQQQQQQQQQQQQQ.pQQQQQQQQQQG......" << endl;
	cout << ".................................Q.)PGQb.....(QQQQQQQQQQQGQQpQQQQQQQQQQG......." << endl;
	cout << ".................................Q............PGGGGGOD.s..SQGGQQQQQQQQC........" << endl;
	cout << ".................................(p.......................(Q..sPGGQQG.........." << endl;
	cout << ".................................(QGqQ)................)QpQQ.....pODQ.........." << endl;
	cout << "..................................QpQs(QGGGGGppSGGGGGGQQQQQQQ....PQ.QC........." << endl;
	cout << "..................................QQQQQQQQQQQQQQQQQQQQQQQQQQQQbeeqqdC.........." << endl;
	cout << "..................................SQQQQQQQQQQQQQQQQQQQQQQQQQQQQ................" << endl;
	cout << ".....................................PSQQQQQQQQQQQQQQQQQQQQGGGO................" << endl;
	cout << "...........................................)DDPGGGOOD)........................." << endl;
	//End Ascii Text Graphic -----------------------------------------------------
}

//-----------------------------------------------------

void vaultBoyLogin() {
	//Vaultboy Ascii Art -------------------------------------------------------
	cout << "..............................................................................." << endl;
	cout << "....SUCCESSFUL!...............................pGPQGp..........................." << endl;
	cout << "......YOU..ARE......................p....pGPPGO..(QPsPPG......................." << endl;
	cout << ".....LOGGING......................pOGppdO)......))PQQQQQPp....................." << endl;
	cout << ".......INTO..THE..................Q....)QdGGQpGGGGQPQQPQPPPQ..................." << endl;
	cout << "..........VAULT...................QQ..QS).........sPGODDSQPsQ)................." << endl;
	cout << ".................................(Q.SQdG........Pb).....pGPQQQ................." << endl;
	cout << "..................................(G..............(....QbQQQQQ................." << endl;
	cout << "..................................Q..(QO..(C..(GQQ.....qQQbpQb................." << endl;
	cout << ".........pdSp....................(b...)..pO......).....SQbbQG.................." << endl;
	cout << ".......()...(b...................SO.....SQ.............Sp.QG..................." << endl;
	cout << ".......Q....S....................Sp......).....QQ.........(Q..................." << endl;
	cout << ".......Q....Q....................(Q.QQDPGPPGO)QpSG........pG..................." << endl;
	cout << ".......QQ)...bQ...................SQ...PGGGGGO........QQGO)...................." << endl;
	cout << "..(GO)))).PGp))SQ..................SQ....PG.........QQQ........................" << endl;
	cout << "..SQ.........Q..(QQQpQp)..........).QQQQ..........dGQbs)Qbp...................." << endl;
	cout << "...QOD))DDGGQG...GQQPssssPPPPsssssssQQQ.PGpQpQ)...QG....QQQQQGp................" << endl;
	cout << "..(Q.........Sp.Qs(QQQQQQQQQQQQQQQQQQQQ...(GGGGGGOs...QGQQQQQQQQGp............." << endl;
	cout << "....SO)DDPGGQQ..S.(QQQQQQQQQQQQQQQQQQQsGp..........QpGQQQQQQQQQQQQPQQ.........." << endl;
	cout << "....QQ......pG.p)QQQQQQQQQQQppppQQQQQQQQb......pGGQQQQQQQQQQQQQQQQQQQGQ........" << endl;
	cout << ".....(GbQQQQpdCQQQQQQQQQQQQGGGO(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQGp......" << endl;
	cout << "..............))DDDD)))))......(QQQQQQQQ......QQQQQQQQQQQQQQQQQQQQQQQQQQQb....." << endl;
	cout << "...............................(QQQQQQQb......QQQQQQQQQQQQGGQQQQQQQQQQQQQQQp..." << endl;
	cout << "................................QQQQQQQb.....(QQQQQQQQQQQQQQQO.DGGQQQQQQQQQC..." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQG..(QQQQQQQQQQG...." << endl;
	cout << "................................QQQQQQQO.....(QQQQQQQQQQQQQQO.pQQQQQQQQQQG....." << endl;
	cout << "................................(GQQQQSO.....(QQQQQQQQQQQQQQ.pQQQQQQQQQQG......" << endl;
	cout << ".................................Q.)PGQb.....(QQQQQQQQQQQGQQpQQQQQQQQQQG......." << endl;
	cout << ".................................Q............PGGGGGOD.s..SQGGQQQQQQQQC........" << endl;
	cout << ".................................(p.......................(Q..sPGGQQG.........." << endl;
	cout << ".................................(QGqQ)................)QpQQ.....pODQ.........." << endl;
	cout << "..................................QpQs(QGGGGGppSGGGGGGQQQQQQQ....PQ.QC........." << endl;
	cout << "..................................QQQQQQQQQQQQQQQQQQQQQQQQQQQQbeeqqdC.........." << endl;
	cout << "..................................SQQQQQQQQQQQQQQQQQQQQQQQQQQQQ................" << endl;
	cout << ".....................................PSQQQQQQQQQQQQQQQQQQQQGGGO................" << endl;
	cout << "...........................................)DDPGGGOOD)........................." << endl;
	//End Ascii ext Graphic -----------------------------------------------------

}

void cinCleaner() {
	//cleans out cin stream
	cin.clear();
	cin.ignore(1000, '\n');
}


//-----------------------------------------------------

int displayMenu() {
	int returnValue;
	bool repeat = true;;
	//basic menu to display the options to the user
	cout << endl << "WELCOME TO THE VAULT!" << endl;
	cout << "Please make a selection based upon what you wish to do..." << endl << endl;
	cout << "1 - Log In" << endl;
	cout << "2 - Create an Account" << endl;
	cout << "3 - Exit the Vault" << endl << endl;

	cout << "Please enter 1, 2 or 3: ";
	cin >> returnValue;
	do {
		if (returnValue > 0 && returnValue < 4) {
			repeat = false;
			cout << "Yes you have entered " << returnValue << endl << endl;
			return returnValue;
		}
		else {
			cout << "I'm sorry, but your input is invalid.  Please try again!" << endl;
			cout << "1 - Log In" << endl;
			cout << "2 - Create an Account" << endl;
			cout << "3 - Exit the Vault" << endl << endl;
			cin >> returnValue;
		}
	} while (repeat = true);

	//-----------------------------------------------------
}

//-----------------------------------------------------

//user wants to login
bool login() {

	//setting the file streams
	fstream accountsFile;
	//-----------------------------------------------------

	//setting local variables
	string userAccountsStream; //lets use stream the userAccounts file for matches
	string tempUsername, tempPassword, tempAccount; //initializes all the users temporary inputs

	bool userEnteringUsername;
	bool userEnteringPassword;
	bool checkingUserType;

	bool usernameMatch = false;
	bool passwordMatch = false;
	//-----------------------------------------------------

	//open the userAccounts file
	accountsFile.open("userAccounts.txt", ios::in);
	if (!accountsFile) {
		cout << endl << "You must first create an account" << endl;
		userEnteringUsername = false;
		return false;
	}
	//-----------------------------------------------------

	cout << "Logging in I see..." << endl;
	userEnteringUsername = true;

	while (userEnteringUsername == true) {
		cinCleaner();
		cout << "Please enter your username: ";
		cin >> tempUsername; //user enters his/her username

							 //checking the cin stream
		while (!cin) { //cleans up cin stream if something bad enters into it
			cinCleaner();
			cout << "Your input was invalid, please try again: ";
			cin >> tempUsername;
		}
		//-----------------------------------------------------

		//checking if the username is correct
		while (usernameMatch == false) {
			getline(accountsFile, userAccountsStream);
			if (tempUsername == userAccountsStream) {
				usernameMatch = true;
				userEnteringUsername = false;
				userEnteringPassword = true;
			}
			else if (accountsFile.eof()) {
				cout << "Your username is incorrect!" << endl;
				userEnteringUsername = false;
				return false;
				break;
			}
		}
		//-----------------------------------------------------
	}
	while (userEnteringPassword == true) {
		cinCleaner();
		cout << "Please enter your password: ";
		cin >> tempPassword; //user enters his/her password

							 //checking the cin stream
		while (!cin) { //cleans up cin stream if something bad enters into it
			cinCleaner();
			cout << "Your input was invalid, please try again: ";
			cin >> tempPassword;
		}
		//-----------------------------------------------------
		tempPassword = tempUsername + tempPassword;
		//checking if the username is correct
		while (passwordMatch == false) {
			getline(accountsFile, userAccountsStream);
			if (tempPassword == userAccountsStream) {
				checkingUserType = true;
				passwordMatch = true;
				userEnteringPassword = false;
			}
			else if (accountsFile.eof()) {
				cout << "Your password is incorrect!" << endl;
				userEnteringPassword = false;
				return false;
				break;
			}
		}
		//-----------------------------------------------------
	}
	//here we are checking for admin or user
	tempAccount = tempPassword + "admin";
	while (checkingUserType == true) { //here we will set our global isUserAdmin bool to true or false
		getline(accountsFile, userAccountsStream);
		if (tempAccount == userAccountsStream) {
			isUserAdmin = true;
			checkingUserType = false;
			username = tempUsername;
			return true;
			break;
		}
		else if (accountsFile.eof()) {
			isUserAdmin = false;
			checkingUserType = false;
			username = tempUsername;
			return true;
			break;
		}
	}
	//-----------------------------------------------------
}

//the User wants to create and account
void createAccount() {
	//declare local streams
	fstream accountCodeFile;
	accountCodeFile.open("accountCodes.txt", ios::out);
	accountCodeFile << "vaultBoy";
	accountCodeFile.close();

	ofstream userAccountsFile;
	userAccountsFile.open("userAccounts.txt", ios::app);
	userAccountsFile.close();
	//done creating the necesary file
	fstream accountsFile; //file to save the accounts too

						  //declare local variables
	int userSelection;

	bool isUserAdmin;
	bool userCreation;
	bool passCreation;

	string correctAccountCode; //storing the correct code from the file
	string tempAccountCode; //user account code entrance
	string tempUsername, tempPassword; //user login info
	string usernameCheck;
	//-----------------------------------------------------

	//read accountCodeFile into correctAccountCode string
	accountCodeFile.open("accountCodes.txt", ios::in);
	accountCodeFile >> correctAccountCode;
	accountCodeFile.close();
	//-----------------------------------------------------
	//Admin Code Menu
	cout << "The Vault systems administrator is wondering if you have an admin code..." << endl << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl << endl;
	cout << "Please enter 1 or 2: ";
	cin >> userSelection;
	//-----------------------------------------------------

	//checking the cin stream
	while (!cin) { //cleans up cin stream if something bad enters into it
		cinCleaner();
		cout << "Your selection was invalid, please try again: ";
		cin >> userSelection;
	}
	while (userSelection < 1 || userSelection > 2) { //cleans up cin stream if the user makes an invalid selection
		cinCleaner();
		cout << "Your selection was invalid, please try again: ";
		cin >> userSelection;
	}
	//-----------------------------------------------------

	switch (userSelection) {
	case 1: {

		userCreation = true; //lets us run the username creation while statement
		cout << endl << "Please enter your admin account code: ";
		cin >> tempAccountCode; //user inputs their account code
								//checking the cin stream
		while (!cin) { //cleans up cin stream if something bad enters into it
			cinCleaner();
			cout << "Your input was invalid, please try again: ";
			cin >> tempAccountCode;
		}
		//-----------------------------------------------------
		if (tempAccountCode == correctAccountCode) { //checks to see if the codes match

			isUserAdmin = true; //tells us its an admin account

			while (userCreation == true) {
				//defining a local bool
				bool usernameCorrect = false;
				//-----------------------------------------------------

				//prompts for the username
				cinCleaner();
				cout << "Please enter your desired username(username is one word, anything past a space will not be read): ";
				cin >> tempUsername; //user enters their desired username

									 //checking the cin stream
				while (!cin) { //cleans up cin stream if something bad enters into it
					cinCleaner();
					cout << "Your input was invalid, please try again: ";
					cin >> tempUsername;
				}
				while (tempUsername == "") { //cleans up cin stream if the user makes an invalid selection
					cinCleaner();
					cout << "You have entered nothing, please try again: ";
					cin >> tempUsername;
				}
				//-----------------------------------------------------
				//lets check if that username exists
				accountsFile.open("userAccounts.txt", ios::in);
				while (usernameCorrect == false) {
					getline(accountsFile, usernameCheck);
					if (usernameCheck == tempUsername) {
						cout << "Sorry! This username is already registered" << endl;
						break;
					}
					else if (accountsFile.eof()) {
						usernameCorrect = true; //ends the username check loop
						userCreation = false; //the username was valid, this is to end the loop
						passCreation = true; //continue onto the password creation
					}
				}
				//-----------------------------------------------------
				accountsFile.close();
			}
			//-----------------------------------------------------

			//reads username to file
			accountsFile.open("userAccounts.txt", ios::app); //reopens file to be modified via append
			accountsFile << endl << tempUsername;
			accountsFile.close();
			//-----------------------------------------------------


			//prompts for the password
			cinCleaner();
			cout << "Please enter your desired password(password is one word, anything past a space will not be read): ";
			cin >> tempPassword; //user enters their desired password

								 //checking the cin stream
			while (!cin) { //cleans up cin stream if something bad enters into it
				cinCleaner();
				cout << "Your input was invalid, please try again: ";
				cin >> tempPassword;
			}
			while (tempUsername == "") { //cleans up cin stream if the user makes an invalid selection
				cinCleaner();
				cout << "You have entered nothing, please try again: ";
				cin >> tempPassword;
			}

			//-----------------------------------------------------
			//reads username to file
			accountsFile.open("userAccounts.txt", ios::app);
			accountsFile << endl << tempUsername + tempPassword; //reads the username specific password into the file
			accountsFile << endl << tempUsername + tempPassword + "admin";//tells us that the specific username and password is associated to an admin account
			accountsFile.close();
			//-----------------------------------------------------
		}
		else { //if codes don't match boot the user back to the menu
			isUserAdmin = false;
			cout << "Your code was incorrect, returning you to the main menu.." << endl;
			system("pause");
		}
		break;
	}
	case 2: {

		userCreation = true;
		isUserAdmin = false; //tells us its an admin account

		while (userCreation == true) {
			//defining a local bool
			bool usernameCorrect = false;
			//-----------------------------------------------------

			//prompts for the username
			cinCleaner();
			cout << "Please enter your desired username(username is one word, anything past a space will not be read): ";
			cin >> tempUsername; //user enters their desired username

								 //checking the cin stream
			while (!cin) { //cleans up cin stream if something bad enters into it
				cinCleaner();
				cout << "Your input was invalid, please try again: ";
				cin >> tempUsername;
			}
			while (tempUsername == "") { //cleans up cin stream if the user makes an invalid selection
				cinCleaner();
				cout << "You have entered nothing, please try again: ";
				cin >> tempUsername;
			}
			//-----------------------------------------------------
			//lets check if that username exists
			accountsFile.open("userAccounts.txt", ios::in);
			while (usernameCorrect == false) {
				getline(accountsFile, usernameCheck);
				if (usernameCheck == tempUsername) {
					cout << "Sorry! This username is already registered" << endl;
					break;
				}
				else if (accountsFile.eof()) {
					usernameCorrect = true; //ends the username check loop
					userCreation = false; //the username was valid, this is to end the loop
					passCreation = true; //continue onto the password creation
				}
			}
			//-----------------------------------------------------
			accountsFile.close();
		}
		//-----------------------------------------------------

		//reads username to file
		accountsFile.open("userAccounts.txt", ios::app); //reopens file to be modified via append
		accountsFile << endl << tempUsername;
		accountsFile.close();
		//-----------------------------------------------------


		//prompts for the password
		cinCleaner();
		cout << "Please enter your desired password(password is one word, anything past a space will not be read): ";
		cin >> tempPassword; //user enters their desired password

							 //checking the cin stream
		while (!cin) { //cleans up cin stream if something bad enters into it
			cinCleaner();
			cout << "Your input was invalid, please try again: ";
			cin >> tempPassword;
		}
		while (tempUsername == "") { //cleans up cin stream if the user makes an invalid selection
			cinCleaner();
			cout << "You have entered nothing, please try again: ";
			cin >> tempPassword;
		}

		//-----------------------------------------------------
		//reads username to file
		accountsFile.open("userAccounts.txt", ios::app);
		accountsFile << endl << tempUsername + tempPassword; //reads the username specific password into the file
		accountsFile << endl << tempUsername + tempPassword + "user";//tells us that the specific username and password is associated to an user account
		accountsFile.close();
		//-----------------------------------------------------
		break;
	}

	}
}

void windowsSetup() {
	//This lines up the console properly
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 800, TRUE); // 700 width, 800 height
														//End the console manipulations ---------------------------------------------
}

int loginInterface() {

	userIsLoggedIn = login(); //sets the return value of the login function to userIsLoggedIn
	if (userIsLoggedIn == true) {
		if (isUserAdmin == true) { //checks global admin variable
			RunNextProgramAdmin = true;
			cout << "congrats you're an admin!" << endl;
			system("pause");
			return 1;


		}
		else if (isUserAdmin == false) { //checks global admin variable
			RunNextProgramUser = true;
			cout << "congrats you're an User!" << endl;
			return 2;
			system("pause");

		}
	}
	else if (userIsLoggedIn == false) { //prompt the unsuccesful login
		cout << "Your login attempt was unsuccessful... Returning you to the Vault's main menu" << endl << endl;
		system("pause");
		//break;
	}
}

void AdminSide() {

	bool isrunning = true;
	while (isrunning == true) {
		fstream surveyFile;
		fstream surveyListFile;
		fstream surveyResults;
		fstream surveyResultsList;

		int userChoice;

		cout << endl << endl << "----------------------------" << endl << endl;
		cout << "Thank you for chosing Brandon-Tech's VaultBoy, we value your continued support in using our product!" << endl;
		cout << "This is your Admin menu, please make a selection!" << endl;
		cout << "1. Create a Survery" << endl;
		cout << "2. Review survey results" << endl;
		cout << "3. Log out and return to Main Menu" << endl << endl;

		cout << "Please enter your choice (1, 2 or 3): ";
		cin >> userChoice;
		while (!cin) {
			cin.clear();
			/*Professor Garcia helped me troubleshoot with the line below.*/
			cin.ignore(1000, '\n');
			cout << endl << "You entered and invalid character into your choice(Numbers Only)" << endl;//renter a valid input
			cout << "Please enter your choice: ";
			cin >> userChoice;
		}

		switch (userChoice) {
		case 1: {

			string tempFileName;
			string tempQuestion;

			int tempQuestionAmount;
			int questionCounter = 1;

			cout << endl << "Let's create a survery! First you'll have to name it." << endl;
			cout << "Please enter your survery name: ";
			cin >> tempFileName;
			while (!cin) {
				cin.clear();
				/*Professor Garcia helped me troubleshoot with the line below.*/
				cin.ignore(1000, '\n');
				cout << endl << "You entered and invalid character into your filename" << endl;//renter a valid input
				cout << "Please enter your filename: ";
				cin >> tempFileName;
			}

			surveyListFile.open("possibleSurveys.txt", ios::app);
			surveyListFile << tempFileName << endl;
			surveyListFile.close();

			tempFileName += ".txt";

			surveyFile.open(tempFileName.c_str(), ios::out);


			cout << "The Uber Survery 7500 lets you choose how many questions you want!(We limit you to 10 for the sake of time)" << endl << "Enter the number of questions you want your survey to be: ";
			cin >> tempQuestionAmount;
			while (!cin) {
				cin.clear();
				/*Professor Garcia helped me troubleshoot with the line below.*/
				cin.ignore(1000, '\n');
				cout << endl << "You entered and invalid character into your amount(Numbers Only)" << endl;//renter a valid input
				cout << "Please enter the number of questions you'd like: ";
				cin >> tempQuestionAmount;
			} if (tempQuestionAmount <= 0) {
				cout << "You have entered an invalid number! You cannot have 0 or a negative number of questions!" << endl;
				cout << "Please re-enter the number of questions you'd like (1-10): ";
				cin >> tempQuestionAmount;
				while (!cin) {
					cin.clear();
					/*Professor Garcia helped me troubleshoot with the line below.*/
					cin.ignore(1000, '\n');
					cout << endl << "You entered and invalid character into your amount(Numbers Only)" << endl;//renter a valid input
					cout << "Please enter the number of questions you'd like: ";
					cin >> tempQuestionAmount;
				}
				cout << endl << endl;
			}
			else if (tempQuestionAmount > 10) {
				cout << "You have entered an invalid number! You cannot have more than 10 questions!" << endl;
				cout << "Please re-enter the number of questions you'd like (1-10): ";
				cin >> tempQuestionAmount;
				while (!cin) {
					cin.clear();
					/*Professor Garcia helped me troubleshoot with the line below.*/
					cin.ignore(1000, '\n');
					cout << endl << "You entered and invalid character into your amount(Numbers Only)" << endl;//renter a valid input
					cout << "Please enter the number of questions you'd like: ";
					cin >> tempQuestionAmount;
				}
				cout << endl << endl;
			}

			while (questionCounter <= tempQuestionAmount) {
				cin.ignore(1000, '\n');
				cout << "Let's create question " << questionCounter << "!" << endl << "Enter your question here: ";
				getline(cin, tempQuestion);

				surveyFile << "Question " << questionCounter << ": " << tempQuestion << endl;
				cout << "Question :" << questionCounter << " saved!";
				questionCounter++;
			}
			surveyFile.close();
			cout << "Your survery has been saved!" << endl << endl;
			break;
		} case 2: {
			surveyResultsList.open("surveyResultsList.txt");

			string savedSurveyResultsList;
			string tempFileChoice;

			string savedResults;
			string savedResults2;

			cout << "Let's take a look at your survey results!" << endl;
			cout << "Here are the completed surveys: " << endl;
			while (surveyResultsList >> savedSurveyResultsList) {
				cout << savedSurveyResultsList << endl;
			}

			cout << endl << "Please enter which Result File you want to choose exactly how it's shown: ";
			cin >> tempFileChoice;

			tempFileChoice += ".txt";

			surveyResults.open(tempFileChoice.c_str());

			cout << "Here are the results for " << tempFileChoice << "!" << endl;
			while (surveyResults >> savedResults) {
				getline(surveyResults, savedResults2);
				cout << savedResults << savedResults2 << endl;
			}
			cout << endl << "Here are your results!" << endl;
			system("pause");
			break;
		} case 3: {
			cout << "Logging you out!" << endl;
			cout << "Log out successful!" << endl;
			isrunning = false;
			/*return 1;*/

			/*onMainMenu = true;
			isAdmin = false;*/
			break;
		} default: {
			cout << endl << endl << "Your input was invalid, please try again: ";
			cin >> userChoice;
			while (!cin) {
				cin.clear();
				/*Professor Garcia helped me troubleshoot with the line below.*/
				cin.ignore(1000, '\n');
				cout << endl << "You entered and invalid character into your choice(Numbers Only)" << endl;//renter a valid input
				cout << "Please enter your choice: ";
				cin >> userChoice;
			}
			break;
		}
		}
	}
}

void UserSide() {
	bool isRunning = true;
	while (isRunning == true) {
		int userChoice;

		bool userTakingSurvey;

		fstream surveyFile;
		fstream surveyListFile;
		fstream surveyResults;
		fstream surveyResultsLister;

		cin.ignore(1000, '\n');

		cout << endl << endl << "----------------------------" << endl << endl;
		cout << "Thank you for chosing the Brandon-Tech VaultBoy, we value your continued support in using our product!" << endl;
		cout << "This is your User menu, please make a selection!" << endl;
		cout << "1. Take a Survey" << endl;
		cout << "2. Log out and return to Main Menu" << endl << endl;

		cout << "Please enter your choice (1 or 2): ";
		cin >> userChoice;
		while (!cin) {
			cin.clear();
			/*Professor Garcia helped me troubleshoot with the line below.*/
			cin.ignore(1000, '\n');
			cout << endl << "You entered and invalid character into your choice(Numbers Only)" << endl;//renter a valid input
			cout << "Please enter your choice: ";
			cin >> userChoice;
		}

		switch (userChoice) {
		case 1: { //user wants to take a survery
			userTakingSurvey = true;
			while (userTakingSurvey == true) {
				bool userFileChecked = false;
				bool userContinueToSurvey;

				string surveyOptions;

				string tempFileChoice;
				string tempSurveyFileAddress;
				string tempResultsFileAddress;
				string savedFileNames;

				string tempQuestion;
				string tempQuestion2;

				string tempAnswer;


				surveyListFile.open("possibleSurveys.txt");

				cout << "Awesome! First lets pick which survery you want to take!" << endl;
				while (surveyListFile >> surveyOptions) {
					cout << surveyOptions << endl;
				}

				surveyListFile.close();
				cout << endl << endl << "Please type in the name of the survery you want to access as it appears on the output!" << endl;
				cout << "Enter your choice: ";
				cin >> tempFileChoice;
				while (!cin) {
					cin.clear();
					/*Professor Garcia helped me troubleshoot with the line below.*/
					cin.ignore(1000, '\n');
					cout << endl << "You entered and invalid character into your choice" << endl;//renter a valid input
					cout << "Please enter your choice: ";
					cin >> tempFileChoice;
				}
				surveyListFile.open("possibleSurveys.txt");

				while (userFileChecked == false) {
					surveyListFile >> savedFileNames;
					if (savedFileNames == tempFileChoice) {
						userFileChecked = true;
						userContinueToSurvey = true;
						surveyListFile.close();
					}
					else if (savedFileNames == "" || tempFileChoice == "\n") {
						userContinueToSurvey = false;
						userFileChecked = true;
						surveyListFile.close();
					}
				}
				if (userContinueToSurvey == true) {
					cout << endl << endl << "Let's being the " << tempFileChoice << " Survey!";
					tempSurveyFileAddress = tempFileChoice + ".txt";
					surveyFile.open(tempSurveyFileAddress.c_str(), ios::in);

					tempResultsFileAddress = username + tempFileChoice; //leaves the naming convention the same to be written to my lister for the admin to view

					surveyResultsLister.open("surveyResultsList.txt", ios::app);
					surveyResultsLister << tempResultsFileAddress << endl;
					surveyResultsLister.close();

					tempResultsFileAddress += ".txt"; //adds the .txt to the end of the filename string to open it.

					surveyResults.open(tempResultsFileAddress.c_str(), ios::out); //opens the result output file to be saved

					int questionCounter = 1;

					while (surveyFile >> tempQuestion) {
						if (tempQuestion == "Question") {
							cin.ignore(1000, '\n');
							getline(surveyFile, tempQuestion2);
							cout << tempQuestion << tempQuestion2 << endl;
							surveyResults << tempQuestion << tempQuestion2 << endl;
							cout << "Your Response: ";
							getline(cin, tempAnswer);
							surveyResults << "Question " << questionCounter << " answer: " << tempAnswer << endl;
							cout << "Answer saved!" << endl << endl;
							questionCounter++;
						}
						else if (tempQuestion == "") {
							cout << "The Survey is completed! Thank you for participating!";
							userTakingSurvey = false;
							break;
						}
					}

					surveyFile.close();
					surveyResults.close();
					cout << "The Survey is completed! Thank you for participating!";
					userTakingSurvey = false;
				}
				else if (userContinueToSurvey == false) {
					cout << "The file you chose was invalid, returning you to the previous menu!" << endl << endl;
				}
			}

			break;
		} case 2: { //user wants to log out
			cout << "Logging you out!" << endl;
			isRunning = false;
			/*return 1;*/
			/*isUser = false;
			onMainMenu = true*/;
			cout << "Log out successful!" << endl;
			break;
		} default: {
			cout << endl << endl << "Your input was invalid, please try again: ";
			cin >> userChoice;
			while (!cin) {
				cin.clear();
				/*Professor Garcia helped me troubleshoot with the line below.*/
				cin.ignore(1000, '\n');
				cout << endl << "You entered and invalid character into your choice(Numbers Only)" << endl;//renter a valid input
				cout << "Please enter your choice: ";
				cin >> userChoice;
			}
		}
		}
	}
}