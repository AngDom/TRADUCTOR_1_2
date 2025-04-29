#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

// Funcion para cargar el diccionario de palabras desde el archivo
map<string, string> cargarDiccionario(const string& nombreArchivo) {
    map<string, string> diccionario;
    ifstream archivo(nombreArchivo.c_str()); // Solucion .c_str()
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de palabras." << endl;
        return diccionario;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string palabra, traduccion, funcionalidad;
        getline(ss, palabra, ',');
        getline(ss, traduccion, ',');
        getline(ss, funcionalidad, ',');
        diccionario[palabra] = traduccion;
    }
    archivo.close();
    return diccionario;
}

// Funcion para traducir el texto ingresado por el usuario
void traducirCodigo(map<string, string>& diccionario) {
    cout << "Ingrese su codigo C++ (finalice con una linea que contenga solo 'EOF'):" << endl;
    string linea;
    string resultado = "";
    bool dentroFuncion = false; // Asumimos que no estamos dentro de una funcion al inicio

    while (getline(cin, linea)) {
        if (linea == "EOF") {
            break;
        }

        istringstream ss(linea);
        string palabra;
        string lineaTraducida = "";

        while (ss >> palabra) {
            // Manejo especial de llaves
            if (palabra == "{") {
                if (!dentroFuncion) {
                    lineaTraducida += "{ // inicio ";
                } else {
                    lineaTraducida += "{ ";
                }
            }
            else if (palabra == "}") {
                if (!dentroFuncion) {
                    lineaTraducida += "} // fin ";
                } else {
                    lineaTraducida += "} ";
                }
            }
            else {
                // Eliminamos caracteres como ';' ',' en la palabra para buscar en el diccionario
                string limpio = palabra;
                if (!limpio.empty()) {
                    char ultimo = limpio[limpio.length() - 1];
                    if (ultimo == ';' || ultimo == ',') {
                        limpio = limpio.substr(0, limpio.length() - 1);
                    }
                }

                // Buscamos si existe traduccion
                if (diccionario.find(limpio) != diccionario.end()) {
                    lineaTraducida += diccionario[limpio] + " ";
                }
                else {
                    lineaTraducida += palabra + " ";
                }
            }
        }

        resultado += lineaTraducida + "\n";
    }

    // Mostrar el resultado final traducido
    cout << "\n--- Codigo Traducido ---\n";
    cout << resultado << endl;
}

int main() {
    const string archivo = "palabras.txt";
    map<string, string> diccionario = cargarDiccionario(archivo);

    if (diccionario.empty()) {
        cout << "El diccionario esta vacio. No se puede traducir." << endl;
        return 1;
    }

    traducirCodigo(diccionario);

    system ("pause");
}

