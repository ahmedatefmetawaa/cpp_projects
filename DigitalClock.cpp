#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{   
    int hours, minutes, seconds;
    cout << "Hours :";
    cin >> hours;
    cout << "Minutes :";
    cin >> minutes;
    cout << "Seconds :";
    cin >> seconds;

    while(1)
    {
        system("cls");
        if(seconds > 59)
        {
            minutes++;
            seconds=0;
        }
        if(minutes >59)
        {
            hours++;
            minutes=0;
        } 
        if(hours > 23)
        hours =0;
        
        cout << hours << ":" << minutes << ":" << seconds;
        seconds++;
        Sleep(900);

    }
    return 0;
}