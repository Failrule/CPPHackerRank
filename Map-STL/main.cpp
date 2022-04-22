#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    int int_consultas;
    int int_tipo;
    int int_marca;
    int int_temp;
    string str_estudiante;
    map<string, int> map_hojas_respuestas;
    map<string, int>::iterator ite_hojas_respuestas;
    cin >> int_consultas;
    
    for (int i=0; i<int_consultas; i++)
    {
        cin >> int_tipo;
        if (int_tipo == 1)
        {
            cin >> str_estudiante >> int_marca;
            ite_hojas_respuestas=map_hojas_respuestas.find(str_estudiante);
            if (ite_hojas_respuestas != map_hojas_respuestas.end())
            {
                int_temp = ite_hojas_respuestas->second;
                int_temp = int_temp + int_marca;
                map_hojas_respuestas.erase(str_estudiante);
                map_hojas_respuestas.insert(make_pair(str_estudiante,int_temp));
            }
            else
            {
                map_hojas_respuestas.insert(make_pair(str_estudiante,int_marca));
            }
        }
        else if (int_tipo == 2)
        {
            cin >> str_estudiante;
            map_hojas_respuestas.erase(str_estudiante);
        }
        else if (int_tipo == 3)
        {
            cin >> str_estudiante;
            ite_hojas_respuestas=map_hojas_respuestas.find(str_estudiante);
            if (ite_hojas_respuestas != map_hojas_respuestas.end())
            {
                cout << ite_hojas_respuestas->second << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << "Nope" << endl;
        }
    }
    return 0;
}


