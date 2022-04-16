#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int int_cantidad;
    int int_temp;
    vector<int> vec_numeros;
    cin >> int_cantidad;
    cin.ignore();
    for (int i=0; i<int_cantidad; i++)
    {
        cin >> int_temp;
        vec_numeros.push_back(int_temp);
    }
    sort(vec_numeros.begin(),vec_numeros.end());
    for (int i=0; i<int_cantidad; i++)
    {
        cout << vec_numeros[i] << endl;
    }
    return 0;
}
