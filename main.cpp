#include <iostream>
#include "AVLTree.h"
using namespace std;

int main();

Node* accounts = NULL;

int mainMenu() {
    int menu;
    cout << "======================================" << endl;
    cout << "\tBANK MANAGEMENT SYSTEM\t\t" << endl;
    cout << "======================================" << endl << endl;
    cout << "1. Administrators menu" << endl;
    cout << "2. Customers menu" << endl;
    cout << "0. Exit main menu" << endl << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

    system("cls");

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

		cout << "========================================" << endl;;
        cout << "|	1. Go back to Administrator's Menu	|" << endl;
        cout << "|	2. Go back to Main Menu          	|" << endl;
        cout << "========================================" << endl;;
        
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
        string nik;
        string gender;
        int num, accNum;
        int pin;
        float bal;
        char option;

        do {
            system("cls");

            cout << "Enter customer's full name (Enter "back" to menu): ";
            getline(cin, name);
            
            if(name == "back")
            	adminMenu();

            cout << "Enter customer's NIK: ";
            cin >> nik; getchar();

            cout << "Enter customer's gender (F/M): ";
            cin >> gender; getchar();

            accNum = accounts->getLastNum(accounts);
            if(accNum == 0)
                accNum = 12410000;
            num = accNum + 1;

            cout << "The customer's account number is " << num << endl;

            cout << "Enter customer's account PIN: ";
            cin >> pin; getchar();
            
            cout << "Enter the amount of initial deposit: ";
            cin >> bal; getchar();
            
            accounts = accounts->createAccount(accounts, pin, num, name, nik, gender, bal);

            cout << "Do you want to create another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
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

    else if(menu == 3) {
		string name;
        string nik;
        string gender;
        int num;
        int pin;
        float bal;
        char option;
        
        do {
            system("cls");

			do
			{
				cout << "Enter the Account's No. to be modified (1 to menu): ";
				cin >> num;
				
				if(num == 1)
					adminMenu();
				
				if(accounts->findAccount(accounts, num))
					continue;
				else
					num = 0;
					cout << "Account does not exist" << endl;
			} while(num < 12410000 || num > 12419999);
			
			system("cls");

			cout << "==================================" << endl;;
			cout << "|\tEnter New Account Info Below\t|" << endl;;
			cout << "==================================" << endl;;
			
            cout << "Enter new Account's name: ";
            getline(cin, name);

            cout << "Enter new Account's NIK: ";
            cin >> nik; getchar();

            cout << "Enter new Account's gender (F/M): ";
            cin >> gender; getchar();

            cout << "The customer's account number is " << num << endl;

            cout << "Enter customer's account PIN: ";
            cin >> pin; getchar();
            
            cout << "Enter the amount of initial deposit: ";
            cin >> bal; getchar();
            
            accounts->modifyInfo(accounts, pin, num, name, nik, gender, bal);

            cout << "Do you want to modify another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
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
    	
    	system("cls");
    	
    	int num;
    	char option;
    	
		do
		{
			do
			{
				cout << "Enter the Account's No. to be deleted (1 to menu): ";
				cin >> num;
				
				if(num == 1)
					adminMenu();
				
				if(accounts->findAccount(accounts, num))
					continue;
				else
					num = 0;
					cout << "Account does not exist" << endl;
			} while(num < 12410000 || num > 12419999);
			
			accounts = accounts->deleteAccount(accounts, num);
			
			cout << "Account has been successfully delete!" << endl;
			
			cout << "Do you want to delete another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
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
    	
    	system("cls");
    	
    	int num;
    	char option;
    	
		do
		{
			do
			{
				cout << "Enter the Account's No. to be displayed (1 to menu): ";
				cin >> num;
				
				if(num == 1)
					adminMenu();
				
				if(findAccount(accounts, num))
					continue;
				else
					num = 0;
					cout << "Account does not exist" << endl;
			} while(num < 12410000 || num > 12419999);
			
			accounts->showAccountInfo(accounts, num);
			
			cout << "Do you want to view another account? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Administrator's Menu	|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
        		int option;
        		
        		cout << "Enter your option: ";
        		cin >> option;
        		
        		if(option == 1)
            		adminMenu();
        		if(option == 2)
            		main();
			}

            cout << endl;
		} while(option == 'Y' || option == 'y');*/
    }

    else if(menu == 6) {
		
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
    	
		int num;
    	
    	cout << "Enter your Bank Account No. (1 to menu): ";
    	cin >> num;
    	
    	if(num == 1)
    		customerMenu();
    	
    	system("cls");
        
        accounts->showAccountInfo(accounts, num);

		cout << "========================================" << endl;;
        cout << "|	1. Go back to Customer's' Menu		|" << endl;
        cout << "|	2. Go back to Main Menu          	|" << endl;
        cout << "========================================" << endl;;
        
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
    	int num;
    	float dep;
    	
		do
		{
			do
			{
				cout << "Enter your Bank Account No. (1 to menu): ";
				cin >> num;
				
				if(num == 1)
					customerMenu();
				
				cout << "Enter your PIN : ";
				cin >> pin;
				
				system("cls");

			} while(!accounts->pinValidator(accounts, num, pin));
			
			
			cout << "Enter amount of deposit: ";
			cin << dep;
			
			accounts->depositFunds(accounts, num, dep);
			
			cout << "Deposit Success" << endl;
			
			cout << "Do you want to deposit again? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Customer's Menu		|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
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

    else if(menu == 3) {
    	
    	system("cls");
    	
    	int pin;
    	int num;
    	float wit;
    	
		do
		{
			do
			{
				cout << "Enter your Bank Account No. (1 to menu): ";
				cin >> num;
				
				if(num == 1)
					customerMenu();
				
				cout << "Enter your PIN : ";
				cin >> pin;
				
				system("cls");

			} while(!accounts->pinValidator(accounts, num, pin));
			
			do
			{
				cout << "Enter amount to withdraw: ";
				cin << wit;
				
				system("cls");
				
			}(!accounts->withdrawFunds(accounts, num, wit);)
			
			cout << "Withdraw Success" << endl;
			
			cout << "Do you want to deposit again? (Y/N): ";
            cin >> option; getchar();

            if(option == 'N' || option == 'n')
            {
            	system("cls");
            	
            	cout << "========================================" << endl;;
        		cout << "|	1. Go back to Customer's Menu		|" << endl;
        		cout << "|	2. Go back to Main Menu          	|" << endl;
        		cout << "========================================" << endl;;
        
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
		
    }

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
