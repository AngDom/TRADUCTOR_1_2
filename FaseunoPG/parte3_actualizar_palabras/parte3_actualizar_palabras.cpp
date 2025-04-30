#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

int main() {
    ifstream archivo("palabras.txt");
    ofstream temp("temp.txt");
    vector<Palabra> lista;
    string linea, buscar;

    if (!archivo || !temp) {
        cerr << "Error abriendo archivos.\n";
        return 1;
    }

    cout << "Ingrese la palabra que desea actualizar: ";
    getline(cin, buscar);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string palabra, traduccion, funcionalidad;
        getline(ss, palabra, '|');
        getline(ss, traduccion, '|');
        getline(ss, funcionalidad);

        if (palabra == buscar) {
            cout << "Nueva traduccion: ";
            getline(cin, traduccion);
            cout << "Nueva funcionalidad: ";
            getline(cin, funcionalidad);
        }

        temp << palabra << "|" << traduccion << "|" << funcionalidad << "\n";
    }

    archivo.close();
    temp.close();
    remove("palabras.txt");
    rename("temp.txt", "palabras.txt");

    cout << "Actualización completada.\n";
    return 0;
}
