#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int int_cantidad, int_consulta1, int_consulta2a, int_consulta2b;
    cin >> int_cantidad;
    cin.ignore();
    vector<int> vec_vector(int_cantidad);
    
    for (int i=0; i<int_cantidad; i++)
    {
        int int_temp;
        cin >> int_temp;
        vec_vector[i] = int_temp;
    }

    cin >> int_consulta1;
    int_consulta1--;
    cin >> int_consulta2a >> int_consulta2b;
    int_consulta2a--;
    int_consulta2b--;

    vec_vector.erase(vec_vector.begin()+int_consulta1);
    vec_vector.erase(vec_vector.begin()+int_consulta2a,vec_vector.begin()+int_consulta2b);
    cout << vec_vector.size() << endl;

    for (int i=0; i<vec_vector.size(); i++)
    {
        cout << vec_vector[i] << " ";
    }
    cout << endl;
    
    return 0;
}