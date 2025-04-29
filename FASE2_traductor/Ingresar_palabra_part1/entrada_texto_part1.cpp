// parte1_entrada_texto.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("texto_original.txt");
    if (!archivo) {
        cerr << "No se pudo crear el archivo." << endl;
        return 1;
    }

    cout << "Ingrese su código C++ (escriba 'FIN' para terminar):\n";
    string linea;
    while (getline(cin, linea)) {
        if (linea == "FIN") break;
        archivo << linea << "\n";
    }

    archivo.close();
    cout << "Codigo guardado en texto_original.txt\n";
    system ("pause");
    
}

