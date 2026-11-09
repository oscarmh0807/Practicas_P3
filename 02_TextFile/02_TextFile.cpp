#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void guardarTareas(const std::string& nombreArchivo, const std::vector<std::string>& tareas) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para escritura.\n";
        return;
    }

    for (const auto& tarea : tareas) {
        archivo << tarea << "\n";
    }
    archivo.close();
    std::cout << "[Exito] tareas guardadas correctamente en '" << nombreArchivo << "'.\n";
}

void leerTareas(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para lectura.\n";
        return;
    }

    std::string linea;
    std::cout << "\n--- Lectura de Tareas desde '" << nombreArchivo << "' ---\n";
    int contador = 1;
    while (std::getline(archivo, linea)) {
        std::cout << contador++ << ". " << linea << "\n";
    }
    archivo.close();
}

int main() {
    const std::string rutaArchivo = "tareas.txt";
    std::vector<std::string> listaTareas = {
        "Configurar entorno de desarrollo SQLite3",
        "Implementar excepciones personalizadas en C++",
        "Disenar tabla de productos para el examen practico",
        "Revisar serializacion de archivos de texto",
        "Documentar commits descriptivos en Git",
        "Realizar documentacion de Practicas 3er parcial"
    };

    guardarTareas(rutaArchivo, listaTareas);

    leerTareas(rutaArchivo);

    return 0;
}