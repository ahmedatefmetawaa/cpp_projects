#include <iostream>
using namespace std;

void ShowMenu()
{
    cout << "************menue***************" << endl;
    cout << "1. Balance" << endl;
    cout << "2. Deposite" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
}

int main()
{
    int choice , balance = 1000 , a , b;
    while(choice != 4)
    {
        ShowMenu();
        cout << "enter your choice ";
        cin >> choice;
        switch (choice)
        {
            case 1: 
            cout << "your balance :" << balance << endl;
            break;

            case 2: 
            cout << "enter Deposite :";
            cin >> a;
            balance+=a;
            cout << "your balance :" << balance << endl;
            break;

            case 3: 
            cout << "enter Withdraw :";
            cin >> b;
            if (b > balance)
            cout << "there is no money enough";
            else
            {
            balance-=b;
            cout << "your balance :" << balance << endl;
            }
            break;

            default : cout << "false choice" << endl;
            break;
        }
    }
    return 0;
}