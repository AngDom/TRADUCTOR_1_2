// parte2_cargar_diccionario.cpp
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

map<string, string> cargarDiccionario() {
    map<string, string> diccionario;
    ifstream archivo("palabras.txt");
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string palabra, traduccion, desc;
        getline(ss, palabra, '|');
        getline(ss, traduccion, '|');
        diccionario[palabra] = traduccion;
    }

    return diccionario;
}
