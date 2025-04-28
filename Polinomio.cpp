#include <iostream>
#include "Polinomio.hpp"
#include "CapturaSegura.hpp"

using namespace std;

void Polinomio::ImprimirPol()
{
    /*cout << "grado: " << grado << endl;*/

    for (int i = 0; i <= grado; ++i)
    {
        cout << coeficientes[i];
        if (i != grado)
        {
            if (coeficientes[i + 1] >= 0) cout << "x^" << grado - i << " +";
            else if (coeficientes[i + 1] < 0) cout << "x^" << grado - i << " ";
        }
    }
}

void Polinomio::CapturarPol()
{
    char solicitud[30];

    sprintf_s(solicitud, "p_pol[%d]: ", grado);

    do {
        CapturaSegura(coeficientes[0], solicitud);
    } while (coeficientes[0] == 0);

    if (grado != 0)
    {
        int i;
        for (i = 1; i < grado + 1; ++i) {
            sprintf_s(solicitud, "p_pol[%d]: ", grado - i);
            CapturaSegura(coeficientes[i], solicitud);
        }
    }
}


Polinomio Polinomio::operator+(Polinomio Q)
{
    int mayor, menor, aux2;
    Polinomio R;

    if (grado > Q.grado) {
        mayor = grado;
        menor = Q.grado;
    }
    else {
        mayor = Q.grado;
        menor = grado;
    }

    R.grado = mayor;

    for (int i = 0; i <= menor; i++) {
        R.coeficientes[R.grado - i] = coeficientes[grado - i] + Q.coeficientes[Q.grado - i];
    }

    aux2 = mayor - menor;

    for (int i = 0; i < aux2; i++) {
        if (grado > Q.grado) {
            R.coeficientes[i] = coeficientes[i];
        }
        else {
            R.coeficientes[i] = Q.coeficientes[i];
        }
    }

    return R;
}

void Polinomio::EstablecerGrado(int g)
{
    if (g <= 0) throw "Argumento invalido";

    grado = g;
}