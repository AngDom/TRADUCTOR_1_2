// parte1_ingresar_palabras
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string palabra, traduccion, funcionalidad;
    ofstream archivo("palabras.txt", ios::app); 

    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    cout << "Ingrese Palabra: ";
    getline(cin, palabra);
    cout << "Ingrese Traduccion: ";
    getline(cin, traduccion);
    cout << "Ingrese Funcionalidad: ";
    getline(cin, funcionalidad);

    archivo << palabra << "|" << traduccion << "|" << funcionalidad << "\n";
    archivo.close();

    cout << "Palabra guardada correctamente.\n";
    system ("pause");
}

