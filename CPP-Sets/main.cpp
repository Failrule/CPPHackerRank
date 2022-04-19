#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int int_consultas;
    int int_tipo;
    int int_numero;
    int int_temp;
    set<int> set_numeros;

    cin >> int_consultas;

    for (int i=0;i<int_consultas;i++)
    {
        cin >> int_tipo >> int_numero;
        if (int_tipo==1)
        {
            set_numeros.insert(int_numero);
        }
        else if (int_tipo==2)
        {
            set_numeros.erase(int_numero);
        }
        else
        {
            set<int>::iterator set_iterador=set_numeros.find(int_numero);
            if (set_iterador!=set_numeros.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
