// Banking.cpp : Defines the entry point for the application.

#include "Banking.h"

#include <iostream>
#include <iomanip>

using namespace std;

void showBalance(double balance) {

	cout << "your balance is: £" << setprecision(2) << fixed << balance << '\n';
}


double deposit() {

	double amount = 0;

	cout << "Enter amout: \n ";
	cin >> amount;

	if (amount > 0) {
		return amount;
	}
	else {
		cout << "Invalid amount: ";
		return 0;
	}
}


double withdraw(double balance) {

	double amount = 0;

	cout << "Enter amount to be withdrawn: \n";
	cin >> amount;

	if (amount > balance) {
		cout << "Warning! Insufficient funds!\n";
		return 0;
	}
	else if (amount < 0) {

		cout << "Warning! Invalid Amount!\n";
		return 0;
	}
	else {
		return amount;
	}
}


int main()
{
	double balance = 0;
	int choice = 0;

	do {
		cout << "************\n";
		cout << "Enter choice\n";
		cout << "************\n";
		cout << "1. Show balance\n";
		cout << "2. Deposit\n";
		cout << "3. Withdraw\n";
		cout << "4. Exit\n";
		cin >> choice;

		cin.clear();
		fflush(stdin);

		switch (choice) {
		case 1: showBalance(balance);
			break;
		case 2: balance += deposit();
			showBalance(balance);
			break;
		case 3: balance -= withdraw(balance);
			showBalance(balance);
			break;
		case 4: cout << "Come again!\n";
			break;
		default: cout << "Invalid choise\n";
			break;
		}
	} while (choice != 4);

	return 0;

}

