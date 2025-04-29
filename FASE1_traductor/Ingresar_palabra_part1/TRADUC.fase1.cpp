#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Estructura para almacenar la palabra, traduccion y funcionalidad
struct Palabra {
    string palabra;
    string traduccion;
    string funcionalidad;
};

// Funcion para cargar las palabras del archivo
vector<Palabra> cargarPalabras(const string& nombreArchivo) {
    vector<Palabra> lista;
    ifstream archivo(nombreArchivo.c_str()); // Solucion .c_str()
    if (!archivo.is_open()) {
        return lista; // Si no existe el archivo, retorna lista vacia
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Palabra p;
        getline(ss, p.palabra, ',');
        getline(ss, p.traduccion, ',');
        getline(ss, p.funcionalidad, ',');
        lista.push_back(p);
    }
    archivo.close();
    return lista;
}

// Funcion para guardar todas las palabras en el archivo
void guardarPalabras(const vector<Palabra>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str()); // Solucion .c_str()
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para guardar." << endl;
        return;
    }

    for (size_t i = 0; i < lista.size(); i++) { // Cambiado range-based for
        archivo << lista[i].palabra << "," << lista[i].traduccion << "," << lista[i].funcionalidad << endl;
    }
    archivo.close();
}

// Funcion para crear/agregar una nueva palabra
void agregarPalabra(vector<Palabra>& lista) {
    Palabra nueva;
    cout << "Ingrese Palabra: ";
    cin >> nueva.palabra;
    cin.ignore();
    cout << "Ingrese Traduccion: ";
    getline(cin, nueva.traduccion);
    cout << "Ingrese Funcionalidad: ";
    getline(cin, nueva.funcionalidad);
    lista.push_back(nueva);
}

// Funcion para mostrar todas las palabras
void mostrarPalabras(const vector<Palabra>& lista) {
    for (size_t i = 0; i < lista.size(); i++) { // Cambiado range-based for
        cout << i + 1 << ". " << lista[i].palabra << " - " << lista[i].traduccion
             << " - " << lista[i].funcionalidad << endl;
    }
}

// Funcion para actualizar una palabra existente
void actualizarPalabra(vector<Palabra>& lista) {
    mostrarPalabras(lista);
    int indice;
    cout << "Seleccione el numero de la palabra a actualizar: ";
    cin >> indice;
    if (indice < 1 || indice > (int)lista.size()) {
        cout << "indice invalido." << endl;
        return;
    }
    cin.ignore();
    cout << "Nueva traduccion: ";
    getline(cin, lista[indice - 1].traduccion);
    cout << "Nueva funcionalidad: ";
    getline(cin, lista[indice - 1].funcionalidad);
}

// Funcion para eliminar una palabra
void eliminarPalabra(vector<Palabra>& lista) {
    mostrarPalabras(lista);
    int indice;
    cout << "Seleccione el numero de la palabra a eliminar: ";
    cin >> indice;
    if (indice < 1 || indice > (int)lista.size()) {
        cout << "indice invalido." << endl;
        return;
    }
    lista.erase(lista.begin() + (indice - 1));
}

int main() {
    const string archivo = "palabras.txt";
    vector<Palabra> palabras = cargarPalabras(archivo);

    int opcion;
    do {
        cout << "\n--- Palabras C++ ---\n";
        cout << "1. Agregar Palabra\n";
        cout << "2. Mostrar Palabras\n";
        cout << "3. Actualizar Palabra\n";
        cout << "4. Eliminar Palabra\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPalabra(palabras);
                guardarPalabras(palabras, archivo);
                break;
            case 2:
                mostrarPalabras(palabras);
                break;
            case 3:
                actualizarPalabra(palabras);
                guardarPalabras(palabras, archivo);
                break;
            case 4:
                eliminarPalabra(palabras);
                guardarPalabras(palabras, archivo);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 5);

    system ("pause");
}

