#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sqlite3.h>

class FileOpenException : public std::runtime_error {
public:
    explicit FileOpenException(const std::string& msg) : std::runtime_error(msg) {}
};

class DatabaseException : public std::runtime_error {
public:
    explicit DatabaseException(const std::string& msg) : std::runtime_error(msg) {}
};

void leerArchivoConfiguracion(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        throw FileOpenException("No se pudo encontrar el archivo de configuracion en: '" + ruta + "'.");
    }
    std::cout << "[Exito] Archivo cargado correctamente.\n";
}

void conectarBaseDatosEstricta(const std::string& rutaBD) {
    sqlite3* db;
    int rc = sqlite3_open_v2(rutaBD.c_str(), &db, SQLITE_OPEN_READWRITE, nullptr);
    if (rc != SQLITE_OK) {
        std::string mensajeError = sqlite3_errmsg(db);
        sqlite3_close(db);
        throw DatabaseException("Fallo la conexion a la BD SQLite. Detalle: " + mensajeError);
    }
    sqlite3_close(db);
}

int main() {
    std::cout << "===== Sistema Robusto con Manejo Integrado de Errores =====\n\n";

    try {
        std::cout << "[Prueba 1] Intentando abrir archivo de texto inexistente...\n";
        leerArchivoConfiguracion("configuracion_faltante.txt");
    } catch (const FileOpenException& e) {
        std::cerr << "[Capturado - Excepcion de Archivo]: " << e.what() << "\n\n";
    }

    try {
        std::cout << "[Prueba 2] Intentando conectar a base de datos inexistente...\n";
        conectarBaseDatosEstricta("base_inexistente.db");
    } catch (const DatabaseException& e) {
        std::cerr << "[Capturado - Excepcion de Base de Datos]: " << e.what() << "\n\n";
    }

    std::cout << "[Exito] El programa completo su ejecucion de forma segura y controlada (sin crash).\n";
    return 0;
}