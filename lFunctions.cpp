// perfect conjunctive normal form demo
// Basic calulator for logic expressions.
// includes many logical and math functions
// Allows simple variables using single letters A-Z
// By Andrey Zorkin a.k.a @a1ndreay (a1handreay@gmail.com) 17:29 21/03/2024

#include "lFunctions.h"

using namespace std;

//convert boolean value to string
//перевод булевой переменной в строковую
string btos(bool x)
{
    if (x)
        return "1";
    return "0";
}

//generation PCNF string via prepared truth table
//по заполненной таблице истинности генерируем СКНФ
string makeSKNF(map<char, vector<bool>> sourcePropositionalChar, vector<char> PropositionalCharCollection)
{
    int PropositionalCharRank = pow(2, PropositionalCharCollection.size());
    string currentAnswer;
    for (int i = 0; i < PropositionalCharRank; i++)
    {
        if (sourcePropositionalChar['#'][i] == NULL)
        {
            if (i > 0 && currentAnswer.length() > 0) currentAnswer += "∧";
            string tempResult = "(";
            for (int j = 0; j < PropositionalCharCollection.size(); j++)
            {
                if (sourcePropositionalChar[(char)(PropositionalCharCollection[j])][i] == NULL)
                {
                    tempResult += PropositionalCharCollection[j];
                }
                else
                {
                    tempResult += "!"; tempResult += PropositionalCharCollection[j];
                }
                if (j < PropositionalCharCollection.size() - 1)
                    tempResult += "v";
            }
            tempResult += ")";
            currentAnswer += tempResult;
        }
    }
    if (currentAnswer.size() == 0) { throw "FORM NOT EXIST!"; }
    return currentAnswer;
}
string makeSDNF(map<char, vector<bool>> sourcePropositionalChar, vector<char> PropositionalCharCollection)
{
    int PropositionalCharRank = pow(2, PropositionalCharCollection.size());
    string currentAnswer;
    for (int i = 0; i < PropositionalCharRank; i++)
    {
        if (sourcePropositionalChar['#'][i] != NULL)
        {
            if (i > 0 && currentAnswer.length() > 0) currentAnswer += "v";
            string tempResult = "(";
            for (int j = 0; j < PropositionalCharCollection.size(); j++)
            {
                if (sourcePropositionalChar[(char)(PropositionalCharCollection[j])][i] != NULL)
                {
                    tempResult += PropositionalCharCollection[j];
                }
                else
                {
                    tempResult += "!"; tempResult += PropositionalCharCollection[j];
                }
                if (j < PropositionalCharCollection.size() - 1)
                    tempResult += "∧";
            }
            tempResult += ")";
            currentAnswer += tempResult;
        }
    }
    if (currentAnswer.size() == 0) { throw "FORM NOT EXIST!"; }
    return currentAnswer;
}

//Replace string variable onto current boolean value
//для конкретной строки таблицы истинности меняем пропозиционные символы на соответствующее значение из ьаблицы истинности
string variableReplace(string convertedToReversePilishString, map<char, vector<bool>> sourcePropositionalChar, int iteration)
{
    for (string::iterator iter = convertedToReversePilishString.begin(); iter != convertedToReversePilishString.end(); ++iter)
    {
        if (sourcePropositionalChar[*iter].size() != 0) { convertedToReversePilishString.replace(iter, iter + 1, btos(sourcePropositionalChar[*iter][iteration])); }
    }
    return convertedToReversePilishString;
}

//Fill answer column
//заполняем столбец ответов таблицы истинности
void fillTable(string convertedToReversePilishString, map<char, vector<bool>>& sourcePropositionalChar, const int PropositionalCharRank)
{
    for (int i = 0; i < PropositionalCharRank; i++)
    {
        string tempStr = variableReplace(convertedToReversePilishString, sourcePropositionalChar, i);
        sourcePropositionalChar['#'].push_back(RpnCalc(tempStr + "print cr"));
        cout << tempStr << " | " << sourcePropositionalChar['#'][i]; //дополнительный вектор на ответы
    }
}

//Generate truth table taking into account the source string
//упаковывает таблицу истинности варьируя булевыми функциями
void unpack(string const sourceString, map<char, vector<bool>>& sourcePropositionalChar, vector<char>& PropositionalCharCollection, int& sourceTableRank)
{
    int sourcePropositionalCharSize = 0;
    map<char, int> ALPHABET = { {'A',1},{'B',1},{'C',1},{'D',1},{'E',1},{'F',1} };
    queue<char> currentPropQueue;
    for (string::const_iterator iter = sourceString.begin(); iter != sourceString.end(); iter++)
    {
        vector<bool> tempVector;
        if (ALPHABET[*iter] == 1) { sourcePropositionalCharSize++; currentPropQueue.push(*iter); ALPHABET[*iter]--; PropositionalCharCollection.push_back(*iter); }
    }
    queue<char> currentPropQueueCheking = currentPropQueue;

    int numRows = pow(2, sourcePropositionalCharSize);
    sourceTableRank = numRows;
    int step = numRows / 2;
    for (int i = 0; i < sourcePropositionalCharSize; i++)
    {
        char currentSymbol = currentPropQueue.front();
        for (int k = 0; k < numRows / (step * 2); k++)
        {
            for (int j = 0; j < (step); j++)
            {
                sourcePropositionalChar[currentSymbol].push_back(NULL);
            }
            for (int j = 0; j < (step); j++)
            {
                sourcePropositionalChar[currentSymbol].push_back(true);
            }
        }
        step /= 2;
        currentPropQueue.pop();
    }
}

//составим таблицу истинности по вектору ответов функции
void forceUnpack(vector<int> _functionValues, map<char, vector<bool>>& sourcePropositionalChar)
{
    char dictionary[] = { 'x','y','z','a','b','c' };
    int PropositionalCharRank = _functionValues.size();
    int sourcePropositionalCharSize = log2((double)PropositionalCharRank);
    int step = PropositionalCharRank / 2;
    for (int i = 0; i < sourcePropositionalCharSize; i++)
    {
        char currentSymbol = dictionary[i];
        for (int k = 0; k < PropositionalCharRank / (step * 2); k++)
        {
            for (int j = 0; j < (step); j++)
            {
                sourcePropositionalChar[currentSymbol].push_back(NULL);
            }
            for (int j = 0; j < (step); j++)
            {
                sourcePropositionalChar[currentSymbol].push_back(true);
            }
        }
        step /= 2;
    }
    for (int i = 0; i < PropositionalCharRank; i++)
    {
        sourcePropositionalChar['#'].push_back(_functionValues[i]);
        //cout << tempStr << " | " << sourcePropositionalChar['#'][i]; //дополнительный вектор на ответы
    }
}

void helpAnnotation()
{
    cout << "use ! + ~ * =    " << endl;
    cout << "example A*B*!D+A*B+A*!D " << endl;
    cout << "> ";
}