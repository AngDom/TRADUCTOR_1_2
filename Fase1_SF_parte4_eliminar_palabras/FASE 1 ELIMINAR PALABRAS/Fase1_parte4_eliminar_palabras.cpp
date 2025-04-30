// parte4_eliminar_palabras.cpp
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream archivo("palabras.txt");
    ofstream temp("temp.txt");
    string linea, palabraEliminar;

    if (!archivo || !temp) {
        cerr << "Error abriendo archivos.\n";
        return 1;
    }

    cout << "Ingrese la palabra que desea eliminar: ";
    getline(cin, palabraEliminar);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string palabra;
        getline(ss, palabra, '|');

        if (palabra != palabraEliminar) {
            temp << linea << "\n";
        }
    }

    archivo.close();
    temp.close();
    remove("palabras.txt");
    rename("temp.txt", "palabras.txt");

    cout << "Palabra eliminada correctamente.\n";
    return 0;
}
