#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int int_numero; //Para determinar la cantidad de números y consultas
    int int_menor; //Para determinar el menor
    int int_temp; //Para ingresar datos temporales en los iteradores
    vector<int> vec_numeros; //Para almacenar el vector de números
    vector<int>::iterator ite_menor; //Para iterar buscando el menor número

    cin >> int_numero; //Ingresa cantidad de números
    for (int i=0;i<int_numero; i++)
    {
        cin >> int_temp; //Ingresa número del arreglo
        vec_numeros.push_back(int_temp); //Alimenta el arreglo con el número ingresado
    }

    cin >> int_numero; //Ingresa candidad de consultas
    for (int i=0;i<int_numero;i++)
    {
        cin >> int_temp; //Ingresa número de la consulta
        ite_menor = lower_bound (vec_numeros.begin(), vec_numeros.end(), int_temp); //Encuentra el valor más cercano por encima del número de la consulta
        
        if(vec_numeros[ite_menor - vec_numeros.begin()] == int_temp) //Si el número de la consulta se encuentra en el arreglo
        {
            cout << "Yes " << (ite_menor - vec_numeros.begin()+1) << endl; //Imprime el número más cercano por encima, en este caso él mismo y arregla a (1based)
        }
        else
        {
            cout << "No " << (ite_menor - vec_numeros.begin()+1) << endl; //Imprime el número más cercano por encima, en este caso el que de lugar en el arreglo y arregla a (1based<)
        }
    }
    return 0;
}