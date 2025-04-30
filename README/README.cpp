#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Crear un objeto de tipo ofstream para escribir en el archivo
    ofstream archivo("README.md");

    if (archivo.is_open()) {
        // Escribir el contenido del README
        archivo << " Traductor de C++ Basico\n\n";
        archivo << "  Objetivo\n";
        archivo << "Crear un programa en C++ que permita:\n";
        archivo << "- Agregar palabras claves con su traducción y funcionalidad (CRUD).\n";
        archivo << "- Traducir fragmentos de codigo C++ utilizando un diccionario definido.\n\n";

        archivo << " Tecnologias usadas\n";
        archivo << "- Lenguaje: **C++** (estandar C++11 o superior)\n";
        archivo << "- Librerias: `fstream`, `iostream`\n";
        archivo << "- IDE recomendado: **Dev-C++**, **Code::Blocks**, **Visual Studio Code**\n\n";

        archivo << "  Estructura del Proyecto\n";
        archivo << "```\n";
        archivo << "TraductorCpp/\n";
        archivo << "+-- crud_palabras.cpp\n";
        archivo << "+-- traductor_codigo.cpp\n";
        archivo << "+-- palabras.txt\n";
        archivo << "+-- ejemplos/\n";
        archivo << "   +-- ejemplo1.cpp\n";
        archivo << "   +-- ejemplo2.cpp\n";
        archivo << "   +-- ejemplo3.cpp\n";
        archivo << "+-- README.md\n";
        archivo << "+-- CONTRIBUTING.md\n";
        archivo << "```\n\n";

        archivo << " Como instalar y correr el proyecto\n\n";
        archivo << " 1. Clonar el repositorio\n";
        archivo << "```bash\n";
        archivo << "git clone https://github.com/TU_USUARIO/TraductorCpp.git\n";
        archivo << "cd TraductorCpp\n";
        archivo << "```\n\n";

        archivo << "2. Compilar los programas\n";
        archivo << "Compilar CRUD de palabras:\n";
        archivo << "```bash\n";
        archivo << "c++ crud_palabras.cpp -o crud_palabras\n";
        archivo << "```\n\n";
        archivo << "Compilar Traductor de codigo:\n";
        archivo << "```bash\n";
        archivo << "c++ traductor_codigo.cpp -o traductor_codigo\n";
        archivo << "```\n\n";

        archivo << "3. Ejecutar los programas\n";
        archivo << "Ejecutar CRUD:\n";
        archivo << "```bash\n";
        archivo << "./crud_palabras\n";
        archivo << "```\n\n";
        archivo << "Ejecutar Traductor:\n";
        archivo << "```bash\n";
        archivo << "./traductor_codigo\n";
        archivo << "```\n\n";

        archivo << "Como colaborar\n";
        archivo << "1. Haz un fork del repositorio.\n";
        archivo << "2. Crea una nueva rama para tus cambios.\n";
        archivo << "3. Realiza un Pull Request para revision.\n\n";

        archivo << "---\n";
        archivo << "Autor\n";
        archivo << "- [Angel Saul Rafael Dominguez]\n";

        archivo.close();
        cout << " README.md creado exitosamente." << endl;
    } else {
        cerr << " Error al crear el archivo README.md." << endl;
    }

	system ("pause");
}

