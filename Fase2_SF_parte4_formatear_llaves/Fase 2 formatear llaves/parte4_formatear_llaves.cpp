// parte4_formatear_llaves.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool esEstructuraControl(const string& linea) {
    vector<string> estructuras = {
        "if", "else", "for", "while", "switch", "do", "try", "catch"
    };
    for (string e : estructuras) {
        if (linea.find(e) != string::npos) return true;
    }
    return false;
}

int main() {
    ifstream archivo("texto_traducido.txt");
    ofstream nuevo("texto_final.txt");
    string linea, anterior;

    while (getline(archivo, linea)) {
        if (linea.find("{") != string::npos) {
            if (esEstructuraControl(anterior)) {
                nuevo << "[INICIO de " << anterior << "]\n";
            } else {
                nuevo << "{\n";
            }
        } else if (linea.find("}") != string::npos) {
            if (esEstructuraControl(anterior)) {
                nuevo << "[FIN de " << anterior << "]\n";
            } else {
                nuevo << "}\n";
            }
        } else {
            nuevo << linea << "\n";
            anterior = linea;
        }
    }

    archivo.close();
    nuevo.close();
    cout << "Archivo final formateado como texto_final.txt\n";
    return 0;
}
