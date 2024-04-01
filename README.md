perfect conjunctive normal form demo,    
perfect disjinctive normal form demo,    
generation truth table via math string: example of math string  >> "A*B*!D+A*B+A*!D",    
generation truth table via function answer vector f1=(1,0,0,1,0,1,0,1),    
support some logical symbols as *, +, !, ~(→)(implementation), =(↔), (,), >, <, /, - and more,    
Basic calulator for logic expressions,    
include math parser (from A*B*!D+A*B+A*!D to parsed string),    
calculate math string,    
includes many logical and math functions,    
Allows simple variables using single letters A-Z,    
// By Andrey Zorkin a.k.a @a1ndreay (a1handreay@gmail.com) 17:29 21/03/2024    

    //пример вызова функций
    int main()
    {
        map<char, vector<bool>> PropositionalChar; //таблица истинности 
        //string input; //A+C+(A~B)*!C
        //vector<char> PropositionalCharCollection;
        //int PropositionalCharRank;
        //helpAnnotation();

    try
    {
        /*
        unpack(input, PropositionalChar, PropositionalCharCollection, PropositionalCharRank); //вычленяем из строки все Пропозициональные символы и создаём таблицу истинности
        string convertedToReversePilish = RPN(input); //convert to reverse polish notation учитывая что знаки логические
        cout<<"[ReversePolishString       ]->"<<convertedToReversePilish<<endl;
        toNoramlForm(convertedToReversePilish); //в обратной польской записи меняем логические знаки на эквивалентные им слова and, or, equal и т.п.
        cout<<"[ReversePolishString.Normal]->"<<convertedToReversePilish<<endl;
        fillTable(convertedToReversePilish, PropositionalChar, PropositionalCharRank); //заполняем таблицу истинности
        string SKNFANSWER = makeSKNF(PropositionalChar, PropositionalCharCollection[0].size());
        cout<<endl<<SKNFANSWER<<endl;
        string DNFANSWER = makeSDNF(PropositionalChar, PropositionalCharCollection);
        cout << endl << DNFANSWER << endl;
        */
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
