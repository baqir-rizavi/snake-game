#include <iostream>
#include <cstring>
#include "game.h"
#include "point.h"
using namespace std;
int main()
{
    cout << "before game starts\nset background color\n\n"
        << "0 = Black       8 = Gray\n"
        << "1 = Blue        9 = Light Blue\n"
        << "2 = Green       A = Light Green\n"
        << "3 = Aqua        B = Light Aqua\n"
        << "4 = Red         C = Light Red\n"
        << "5 = Purple      D = Light Purple\n"
        << "6 = Yellow      E = Light Yellow\n"
        << "7 = White       F = Bright White\n";
    char option[] = "0";
    cin >> option;
    cout << "\nALSO\nset \"GAME\" color\n\n"
        << "0 = Black       8 = Gray\n"
        << "1 = Blue        9 = Light Blue\n"
        << "2 = Green       A = Light Green\n"
        << "3 = Aqua        B = Light Aqua\n"
        << "4 = Red         C = Light Red\n"
        << "5 = Purple      D = Light Purple\n"
        << "6 = Yellow      E = Light Yellow\n"
        << "7 = White       F = Bright White\n";
    char option1[] = "2";
    cin >> option1;
    char str[10] = "Color ";
    strcat(str, option);
    strcat(str, option1);
    cout << str;
	system(str);
	game game1;
	game1.run(); 
}