#include <iostream>
#include <string>

using namespace std;


/* Gramatica
    A -> aBa
    B -> bAb
    B -> a
*/
    //Simbolos no terminales
    void A(const string&, int&);
    void B(const string&, int&);

void error(string m_error)
{
    cout << "Ha ocurrido un error: " << m_error << endl;
    exit(1);
}

void consume(char x, const string &str, int &idx)
{
    if(str[idx] == x)
    {
        idx++;
    }
    else
    {
        error("Intento de consumir el simbolo" + string(1, x) + " cuando en realidad hay " + string(1, str[idx]));
    }
}

void A(const string &str, int &idx)
{
    consume('a', str, idx);  B(str, idx); consume('a', str, idx); // A -> aBa
}

void B(const string &str, int &idx)
{
    switch(str[idx])
    {
        case 'b':
            consume('b', str, idx); A(str, idx); consume('b', str, idx); // B -> bAb
            break;
        case 'a':
            consume('a', str, idx);  // B -> a
            break;
        default:
            error("Intento de consumir B() pero no encontre ni b ni a");
    }
}


void checkGrammar(string str)
{
    int idx = 0;
    A(str, idx);
    cout << "La cadena " << str << " si pertenece a la gramatica" << endl;
}


int main () {

    while(true)
    {
        string s; cin>>s;
        checkGrammar(s);
    }

	return 0;
}