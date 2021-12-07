#include <iostream>
#include "AVLTree.h"
#include "TransacHistory.h"
using namespace std;

int main();

bool validateString(string s) {
	for(const char c : s) {
		if(!isalpha(c) && !isspace(c))
			return false;
	}

	return true;
}

void resetLine() {
	printf("\x1b[A");
	printf("\33[2K");
}

Node* accounts = NULL;
Queue* transaction_History = new Queue(1000);

int mainMenu() {
    int menu;
    
    system("cls");
    
    cout << "======================================" << endl;
    cout << "\tBANK MANAGEMENT SYSTEM\t\t" << endl;
    cout << "======================================" << endl << endl;
    cout << "1. Administrators menu" << endl;
    cout << "2. Customers menu" << endl;
    cout << "0. Exit main menu" << endl << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

    return menu;
}

void adminMenu() {
    system("cls");

    int menu;
    cout << "======================================" << endl;
    cout << "\tADMINISTRATORS MENU\t\t" << endl;
    cout << "======================================" << endl << endl;
    cout << "1. Display list of all customer accounts" << endl;
    cout << "2. Create new customer account" << endl;
    cout << "3. Modify a customer account" << endl;
    cout << "4. Delete a customer account" << endl;
    cout << "5. Find a customer account" << endl;
    cout << "6. Display transaction history of selected customer" << endl;
    cout << "0. Go back to main menu" << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

    if(menu == 1) {
    	
        system("cls");
        
        accounts->displayAllAccounts(accounts);

		cout << "=================================================" << endl;;
        cout << "|	1. Go back to Administrator's Menu	|" << endl;
        cout << "|	2. Go back to Main Menu          	|" << endl;
        cout << "=================================================" << endl;;
        
        int option;
        
        cout << "Enter your option: ";
        cin >> option;
        
        if(option == 1)
            adminMenu();
        if(option == 2)
            main();
    }

    else if(menu == 2) {
        string name;
        long long nik;
        char gender;
        int num, accNum, n = 0;
        int pin;
        float bal;
        char option;

        do {

        	do
			{
            	system("cls");

				cout << "Enter customer's full name (Enter \"back\" to menu): ";
            	getline(cin, name);
            	
				if(name == "back")
            		adminMenu();

			} while(!validateString(name));

			do
			{
				cout << "Enter customer's NIK (16 digits): ";
            	cin >> nik; getchar();

				if(nik < 1000000000000000 || nik > 9999993112999999)
					resetLine();

			} while(nik < 1000000000000000 || nik > 9999993112999999);

			do
			{
				cout << "Enter customer's gender (F/M): ";
            	cin >> gender; getchar();
            	
            	if(gender != 'F' && gender != 'M')
					resetLine();

			} while(gender != 'F' && gender != 'M');


            accNum = accounts->getLastNum(accounts);
            if(accNum == 0)
                accNum = 12410000;
            num = accNum + 1;

            cout << "The customer's account number is " << num << endl;

			do
			{
				cout << "Enter customer's account PIN (6 digits): ";
            	cin >> pin; getchar();

				if(pin < 100000 || pin > 999999)
					resetLine();

			} while(pin < 100000 || pin > 999999);
            
            do
            {
            	cout << "Enter the amount of initial deposit (min. 50000): ";
            	cin >> bal; getchar();

				if(bal < 50000)
					resetLine();

			} while(bal < 50000);

            
            accounts = accounts->createAccount(accounts, pin, num, name, nik, gender, bal);

            cout << "Do you want to create another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");

            	cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		adminMenu();
        		if(option == 2)
            		main();
			}

        } while(option == 'Y' || option == 'y');
    }

    else if(menu == 3) {
		string name;
        long long nik;
        char gender;
        int pin;
        int bal;
        char option;
        
        do {
			int num = -1;

			do
			{
            	system("cls");

				if(num == 0)
					cout << "Account does not exist" << endl;

				cout << "Enter the Account No. to be modified (1241xxxx) (1 to menu): ";
				cin >> num; getchar();
				
				if(num == 1)
					adminMenu();
				
				else if(num < 12410000 || num > 12419999)
					resetLine();

				else {
					if(accounts->findAccount(accounts, num))
						continue;

					else
						num = 0;
				}

			} while(num < 12410000 || num > 12419999);

			cout << "=========================================" << endl;
			cout << "|\tEnter New Account Info Below\t|" << endl;
			cout << "=========================================" << endl;
			
			do {
				cout << "Enter new Account's name: ";
				getline(cin, name);

				if(!validateString(name))
					resetLine();

			} while(!validateString(name));

			do {
				cout << "Enter new Account's NIK (16 digits): ";
				cin >> nik; getchar();

				if(nik < 1000000000000000 || nik > 9999999999999999)
					resetLine();

			} while(nik < 1000000000000000 || nik > 9999999999999999);

			do {
				cout << "Enter new Account's gender (F/M): ";
				cin >> gender; getchar();

				if(gender != 'F' && gender != 'M')
					resetLine();

			} while(gender != 'F' && gender != 'M');

			do {
				cout << "Enter new customer's account PIN (6 digits): ";
				cin >> pin; getchar();

				if(pin < 100000 || pin > 999999)
					resetLine();

			} while(pin < 100000 || pin > 999999);
            
			do {
				cout << "Enter new amount of balance: ";
				cin >> bal; getchar();

				if(bal < 0)
					resetLine();

			} while(bal < 0);
            
            accounts->modifyInfo(accounts, pin, num, name, nik, gender, bal);

            cout << "Do you want to modify another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		adminMenu();
        		if(option == 2)
            		main();
			}
			
            cout << endl;
        } while(option == 'Y' || option == 'y');
    }

    else if(menu == 4) {

    	char option;
    	
		do
		{
    		int num = -1;

			do
			{
				system("cls");

				if(num == 0)
					cout << "Account does not exist" << endl;

				cout << "Enter the Account No. to be deleted (1241xxxx) (1 to menu): ";
				cin >> num; getchar();
				if(num == 1)
					adminMenu();
				
				else if(num < 12410000 || num > 12419999)
					resetLine();

				else
					if(accounts->findAccount(accounts, num))
						continue;

					else {
						num = 0;
				}

			} while(num < 12410000 || num > 12419999);
			
			accounts = accounts->deleteAccount(accounts, num);
			
			cout << "Account has been successfully deleted!" << endl;
			
			cout << "Do you want to delete another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		adminMenu();
        		if(option == 2)
            		main();
			}

            cout << endl;
		} while(option == 'Y' || option == 'y');
    }

    else if(menu == 5) {
    	
    	int num;
    	char option;
		
		do
		{
			int n = 0;

			system("cls");

			do
			{
				if(n == -1) {
					system("cls");
					cout << "Account does not exist" << endl;
				}

				cout << "Enter the Account No. to be displayed (1241xxxx) (1 to menu): ";
				cin >> num; getchar();
				
				if(num == 1)
					adminMenu();
				
				else if(num < 12410000 || num > 12419999) {
					if(n == -1) {
						system("cls");
						n = 0;
					}
					else
						resetLine();
				}
			
				else if(accounts->findAccount(accounts, num) == false)
					n = -1;
	
			} while(accounts->findAccount(accounts, num) == false);
			
			n = accounts->showAccountInfo(accounts, num);
			
			cout << "Do you want to view another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		adminMenu();
        		if(option == 2)
            		main();
			}

            cout << endl;
		} while(option == 'Y' || option == 'y');
	}

	  else if(menu == 6) {
				
		char answer;
		
		transaction_History->showHistory(transaction_History);
		
		cout << "Do you want to delete the whole history (Y/N)? ";
	    cin >> answer;
	        
        if(tolower(answer) == 'y')
        {
        	transaction_History->dequeue_All(transaction_History);
        	if(!transaction_History->isEmpty(transaction_History));
        		cout << "Transaction history has been cleared";
        		adminMenu();
		}
		else if(tolower(answer) == 'n')
		{
			adminMenu();
		}
	}

    else if(menu == 0)
       	main();

    system("cls");
}

int customerMenu() {
	
    system("cls");

    int menu;
    cout << "======================================" << endl;
    cout << "\tCUSTOMERS MENU\t\t" << endl;
    cout << "======================================" << endl << endl;
    cout << "1. Check your account info" << endl;
    cout << "2. Deposit funds" << endl;
    cout << "3. Withdraw funds" << endl;
    cout << "4. Display transaction history of selected customer" << endl;
    cout << "0. Go back to main menu" << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

    system("cls");
    
    if(menu == 1) {
    	
    	system("cls");
    	
		int n, num;
    	
		do
		{
			cout << "Enter the Account No. to be displayed (1241xxxx) (1 to menu): ";
			cin >> num; getchar();
			
			if(num == 1)
				customerMenu();
			
			else if(num < 12410000 || num > 12419999)
				resetLine();

			else {
				if(accounts->findAccount(accounts, num) == false)
					n = -1;

				else n = 1;
			}

		} while(n == -1);
    	
    	n = accounts->showAccountInfo(accounts, num);

		cout << "=================================================" << endl;;
        cout << "|	1. Go back to Customer's Menu		|" << endl;
        cout << "|	2. Go back to Main Menu          	|" << endl;
        cout << "=================================================" << endl;;
        
        int option;
        
        cout << "Enter your option: ";
        cin >> option;
        
        if(option == 1)
            customerMenu();
        if(option == 2)
            main();
    }

    else if(menu == 2) {
    	
    	system("cls");
    	
    	int pin;
    	int n, num;
    	int dep;
    	char option;

		do
		{
    		int valid = -2;
			
			do
			{
				system("cls");

				if(valid == -1)
					cout << "Account does not exist" << endl;
				
				else if(valid == 0)
					cout << "Wrong PIN" << endl;

				cout << "Enter your Bank Account No. (1241xxxx) (1 to menu): ";
				cin >> num; getchar();
				
				if(num == 1)
					customerMenu();

				cout << "Enter your PIN : ";
				cin >> pin; getchar();

				valid = accounts->pinValidator(accounts, num, pin);

			} while(valid == 0 || valid == -1);
			
			do {
				cout << "Enter amount of deposit: ";
				cin >> dep; getchar();

				if(dep < 0)
					resetLine();

			} while(dep < 0);
			
			accounts->depositFunds(accounts, num, dep);
			
			transaction_History->enqueueDeposit(transaction_History, num, dep);
			
			cout << "Do you want to deposit again? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Customer's Menu		|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		customerMenu();
        		if(option == 2)
            		main();
			}

            cout << endl;
		} while(option == 'Y' || option == 'y');
    }

    else if(menu == 3) {
    	
    	system("cls");
    	
    	int pin;
    	int num;
    	int wit;
    	char option;

		do
		{
			int valid = -2;
			int withdrawn = -2;

			do
			{
				system("cls");

				if(valid == -1)
					cout << "Account does not exist" << endl;

				else if(valid == 0)
					cout << "Wrong PIN" << endl;

				cout << "Enter your Bank Account No. (1241xxxx) (1 to menu): ";
				cin >> num; getchar();
				
				if(num == 1)
					customerMenu();

				cout << "Enter your PIN : ";
				cin >> pin; getchar();

				valid = accounts->pinValidator(accounts, num, pin);

			} while(valid == 0 || valid == -1);
			
			do
			{
				if(withdrawn == 0)
					cout << "Not enough balance" << endl;

				cout << "Enter amount to withdraw (min. 50000): ";
				cin >> wit; getchar();
				
				if(wit < 50000)
					resetLine();

				int withdrawn = accounts->withdrawFunds(accounts, num, wit);

			} while(withdrawn == 0 || wit < 50000);
			
			transaction_History->enqueueWithdrawal(transaction_History, num, wit);
			
			cout << "Do you want to withdraw again? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "=================================================" << endl;;
        		cout << "|	1. Go back to Customer's Menu		|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "=================================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		customerMenu();
        		if(option == 2)
            		main();
			}

            cout << endl;
		} while(option == 'Y' || option == 'y');
    }

    else if(menu == 4) {
			
		char answer;
		
		transaction_History->showHistory(transaction_History);
		
		cout << "Do you want to delete the whole history (Y/N)? ";
        cin >> answer;
            
        if(tolower(answer) == 'y')
        {
        	transaction_History->dequeue_All(transaction_History);
        	if(!transaction_History->isEmpty(transaction_History));
        		cout << "Transaction history has been cleared";
        		customerMenu();
		}
		else if(tolower(answer) == 'n')
		{
			customerMenu();
		}
	}
    else if(menu == 0)
       	main();

    system("cls");
    	
    return menu;
}

int main() {
	
    int menu = mainMenu();

    system("cls");

    while(menu != 0) {

        if(menu == 1) {
            adminMenu();
        }

        else if(menu == 2) {
            customerMenu();
        }

        system("cls");

        menu = mainMenu();
    }

    exit(0);

    return 0;
}
