#include <iostream>

#include "Polinomio.hpp"

using namespace std;


int main()
{
    Polinomio Q;
    Polinomio P;
    Polinomio R;

    int a(1), b(1), c;

    try
    {
        Q.EstablecerGrado(2);
        P.EstablecerGrado(5);

        cout << "\n\nPolinomio Q:" << endl;
        Q.CapturarPol();

        Q.ImprimirPol();

        cout << "\n\nPolinomio P:" << endl;
        P.CapturarPol();

        P.ImprimirPol();

        cout << "\n\nSuma: " << endl;

        //R = P.operator+(Q); //Llamada explicita
        R = P + Q; //Llamada implicita

        //suma entero
        c = a + b;
        cout << "suma entero: " << c << endl;

        P.ImprimirPol();
        cout << "\n-";
        Q.ImprimirPol();
        cout << "\n=";

        R.ImprimirPol();

    }
    catch (const char* error) {
        cerr << "Error: " << error << endl;
    }


    cout << endl;

    system("pause");
    return 0;

}


