#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream> 

using namespace std;

int main()
{
    int int_lineas, int_consultas; 
    string str_temp;
    vector<string> vec_codigo, vec_consultas; //Vectores para almacenar las líneas del código y las consultas
    cin >> int_lineas >> int_consultas; // Ingreso de número de líneas del código y cantidad de consultas
    cin.ignore(); // Ignora un salto perdido siempre que se ingresa algo con cin
    for (int i=0; i<int_lineas; i++) //Itera la cantidad líneas de código que ingresamos en línea 16
    {
        getline(cin, str_temp); //Captura en la variable str_temp la línea de código de la iteración actual
        vec_codigo.push_back(str_temp); //Inserta en el vector vec_codigo lo capturado en anteriormente
    }
    for (int i=0; i<int_consultas; i++) //Itera la cantidad de consultas que ingresamos en línea 16
    {
        getline(cin, str_temp); //Captura en la variable str_temp la consulta de la iteración actual
        vec_consultas.push_back(str_temp); //Inserta en el vector vec_consultas lo capturado anteriormente
    }
    map<string, string> map_par; //Instancia un mapa de dos string llamado map_par para insertar las parejas para consultarlas
    vector<string> vec_etiqueta; //Instancia un vector vec_etiqueta para almacenar las etiquetas
    for (int i=0;i<int_lineas;i++) //Itera cuantas líneas de código haya
    {
        str_temp=vec_codigo[i]; //Asigna a str_temp la línea de código de la respectiva iteración
        str_temp.erase(remove(str_temp.begin(), str_temp.end(), '\"'),str_temp.end()); //Elimina las comillas de la línea de código de la respectiva iteración
        str_temp.erase(remove(str_temp.begin(), str_temp.end(), '>'),str_temp.end()); //Elimina los signos > de la línea de código
        if (str_temp.substr(0,2)=="</") //Ingresa si hay </ en la cadena para cerrar un nivel de etiqueta
        {
            vec_etiqueta.pop_back(); //Destruye el último elemento del vector vec_etiqueta
        }
        else //Ingresa si no hay </ y procede a operar etiquetas
        {
            stringstream ss_str; //Instancia un stringstream ss_str para particionar los términos de la línea de código
            ss_str.str(); //Limpia con nada a ss_str
            ss_str<<str_temp; //Inserta la línea de código anteriormente limpiada de " y de >
            string str_t1,str_p1,str_v1; //Instancia variables para ingresar separadamente los términos de la línea de código
            char cha_c1; //Instancia una variable caracter para capturar los < y los = que existan en el stringstream ss_str
            ss_str>>cha_c1>>str_t1>>str_p1>>cha_c1>>str_v1; //Acomoda todos los terminos
            // cha_c1 = <
            // str_t1 = tag1, es decir limpia < para dejar tag1 limpio
            // str_p1 = value o name, es decir el nombre de la etiqueta
            // cha_c1 = "=", es decir, limpia el =
            // str_v1 = Ghanedra, es decir el valor de la etiqueta anterior
            string str_temp1=""; //Instancia otra variable string de ayuda para ......
            if (vec_etiqueta.size()>0) //Ingresa si el tamaño del vector vec_etiqueta es mayor a 0
            {
                str_temp1=*vec_etiqueta.rbegin(); //Asigna a str_temp1 la dirección inicial del vector vec_etiqueta
                str_temp1=str_temp1+"."+str_t1; //Asigna el valor de str_t1 a sí mismo junto con la etiqueta dentro de str_t1 actual
            }
            else //Ingresa si el tamaño del vector vec_etiqueta no es mayor a 0
            {
                str_temp1=str_t1; //Asigna a str_temp1 el valor de str_t1 que es el número de la etiqueta ej: tag1
            }
            vec_etiqueta.push_back(str_temp1); // Añade al vector vec_etiqueta el valor actual de str_temp1 ej: tag1
            map_par[*vec_etiqueta.rbegin()+"~"+str_p1]=str_v1; // Formatea tag(etiqueta)+"~"+value/name | valor ej: "tag1~value":"Ghanendra" m<string,string>
            while(ss_str) //Mientras ss_str esté recorriendo
            {
                ss_str >> str_p1 >> cha_c1 >> str_v1; // Asigna tipo = valor a ss_str
            }
        }
    }
    for(int i=0; i<int_consultas; i++) //Itera cuantas consultas existan
    {
        if(map_par.find(vec_consultas[i]) == map_par.end()) //Busca las líneas de cada consulta dentro del mapa map_par
        {
            cout << "Not Found!\n"; //Si no se encuentra
        }
        else
        {
            cout << map_par[vec_consultas[i]] << endl; //Si se encuentra imprime el segundo del mapa es decir str_v1
        }
    }
    return 0;
}
