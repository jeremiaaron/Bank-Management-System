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
    cout << "6. Display log history of selected customer" << endl;
    cout << "0. Go back to main menu" << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

    if(menu == 1) {
        system("cls");
        accounts->displayAllAccounts(accounts);

        cout << "1. Go back to Administrators Menu" << endl;
        cout << "2. Go back to Main Menu" << endl;
        
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
        int bal;
        char option;

        do {
            system("cls");

            cout << "Enter customer's full name: ";
            getline(cin, name);

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
                adminMenu();

            cout << endl;
        } while(option == 'Y' || option == 'y');
    }

    else if(menu == 3) {

    }

    else if(menu == 4) {

    }

    else if(menu == 5) {

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
    cout << "2. Delete a customer account" << endl;
    cout << "3. Find a customer account" << endl;
    cout << "4. Display log history of selected customer" << endl;
    cout << "0. Go back to main menu" << endl;
    
    cout << "Enter your option: ";
    cin >> menu;
    getchar();

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