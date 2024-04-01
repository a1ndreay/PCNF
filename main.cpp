// perfect conjunctive normal form demo
// Basic calulator for logic expressions.
// includes many logical and math functions
// Allows simple variables using single letters A-Z
// By Andrey Zorkin a.k.a @a1ndreay (a1handreay@gmail.com) 17:29 21/03/2024

#include "lFunctions.h"

using namespace std;

int main()
{
    map<char, vector<bool>> PropositionalChar; //таблица истинности 
    try
    {
        forceUnpack(vector<int> {1, 0, 0, 1, 0, 1, 0, 1}, PropositionalChar);
        string DNFANSWER = makeSDNF(PropositionalChar, vector<char> {'x','y','z'});
        cout << "SDNF = " << endl << DNFANSWER << endl;
        string SKNFANSWER = makeSKNF(PropositionalChar, vector<char> {'x', 'y', 'z'});
        cout << "SKNF = " << endl << SKNFANSWER << endl;
    }
    catch(const char* error_message)
    {
        cout <<'\n' << error_message << '\n';
    }
    getch();
    
    return 0;
}