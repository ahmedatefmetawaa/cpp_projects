#include <iostream>
#include <windows.h>
using namespace std;

void Drow();
void Replace();
char CheckWinner();

char matrix[3][3] = {'1' , '2' , '3',
                     '4' , '5' , '6',
                     '7' , '8' , '9'};
char player = 'x';

int main()
{
    while(CheckWinner() == '*')
    {
    Drow();
    Replace();
    CheckWinner();
    }
    Drow();
    if (CheckWinner() == 'x')
    cout << "player x is the winner" << endl;
    else if (CheckWinner() == 'o')
    cout << "player o is the winner" << endl;
    else if (CheckWinner() == '=')
    cout << "no winner" << endl;
    return 0;
}

void Drow()
{
   system("cls");
   cout << "--------- \n";
   for (int r=0; r<3; r++)
   {
    cout << "| ";
    for (int c=0; c<3; c++)
    {
        cout << matrix[r][c] <<" ";
    }
    cout << "| ";
    cout << endl;
   }
   cout << "--------- \n";                      
}

void Replace()
{
    char pos;
    cout << "enter your position ("<< player<<") :";
    cin >> pos;
    for (int r=0; r<3; r++)
   {
    for (int c=0; c<3; c++)
    {
        if(matrix[r][c] == pos)
        {
            matrix[r][c] = player;
        }
    }
   }
    if(player == 'x')
    {
        player = 'o';
    }
    else
        player = 'x';    
}

char CheckWinner()
{
    int x =0, o = 0, counter = 0;
    /*a row winner*/
    for (int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(matrix[r][c] == 'x')
            x++;
            else if (matrix[r][c] == 'y')
            o++;
            if (x == 3)
            return 'x';
            if (o == 3)
            return 'o';
        }
        x=0;o=0;
    }

    /*a column winner*/
    for (int c=0; c<3; c++)
    {
        for(int r=0; r<3; r++)
        {
            if(matrix[r][c] == 'x')
            x++;
            else if (matrix[r][c] == 'y')
            o++;
            if (x == 3)
            return 'x';
            if (o == 3)
            return 'o';
        }
         x=0;o=0;
    }

    /*a back slash winner*/
    if(matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x')
    return 'x';
    if(matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o')
    return 'o';
    /*a slash winner*/
    if(matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x')
    return 'x';
    if(matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o')
    return 'o';

    /*an equal case*/
    for (int r=0; r<3; r++)
   {
    for (int c=0; c<3; c++)
        {
            if(matrix[r][c] != 'x' && matrix[r][c] != 'o')
            counter++;
        }
    }
    if(counter == 0)
    return '=';

    return '*';
}