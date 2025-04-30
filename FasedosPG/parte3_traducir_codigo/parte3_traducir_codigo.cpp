// parte3_traducir_codigo.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

extern map<string, string> cargarDiccionario();

int main() {
    map<string, string> diccionario = cargarDiccionario();
    ifstream entrada("texto_original.txt");
    ofstream salida("texto_traducido.txt");

    string linea;
    while (getline(entrada, linea)) {
        istringstream iss(linea);
        string palabra;
        while (iss >> palabra) {
            if (diccionario.find(palabra) != diccionario.end()) {
                salida << diccionario[palabra] << " ";
            } else {
                salida << palabra << " ";
            }
        }
        salida << "\n";
    }

    entrada.close();
    salida.close();
    cout << "Traduccion guardada en texto_traducido.txt\n";
    return 0;
}
