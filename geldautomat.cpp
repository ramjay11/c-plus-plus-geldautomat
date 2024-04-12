#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;


void zeigeDasMenu() {
    cout << "******Menu******" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "****************" << endl;
}

int main() {
    // check balance, deposit, withdraw, menu
    int options;
    double balance = 1000;

    do {
        zeigeDasMenu();
        cout << "Options :";
        cin >> options;

        // Check if the input is valid
        if (cin.fail() || (options != 1 && options != 2 && options != 3 && options != 4)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid options entered!");
        }
        system("cls");

        switch (options) {
            case 1: cout << "Balance is: " << balance << " $" << endl; break;
            case 2: cout << "Deposit amount: ";
                    double deposit;
                    cin >> deposit;
                    balance += deposit;
                    break;
            case 3: cout << "Withdraw amount: ";
                    double withdraw;
                    cin >> withdraw;
                    if (deposit <= balance)
                        balance -= withdraw;
                    else 
                        cout << "Not enough funds" << endl;    
                    break;
        }
    } while (options != 4);
    
    system("pause > 0");
}