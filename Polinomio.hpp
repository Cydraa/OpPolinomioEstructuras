#pragma once

#define MAX_GRADO 10

class Polinomio {
public:
    Polinomio operator+(Polinomio Q);
    Polinomio operator-(Polinomio Q);
    void ImprimirPol();
    void CapturarPol();
    void EstablecerGrado(int g);
private:
    int grado;
    double coeficientes[MAX_GRADO + 1];

};