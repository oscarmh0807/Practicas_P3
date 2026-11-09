#include <iostream>
#include <sqlite3.h>
#include <string>

static int callbackConteo(void* data, int argc, char** argv, char** azColName) {
    int* contador = static_cast<int*>(data);
    if (argc > 0 && argv[0]) {
        *contador = std::stoi(argv[0]);
    }
    return 0;
}

static int callbackConsulta(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::cout << "\n";
    return 0;
}

int main() {
    sqlite3* db;
    char* zErrMsg = nullptr;

    int rc = sqlite3_open("tienda.db", &db);
    if (rc) {
        std::cerr << "Error al abrir BD: " << sqlite3_errmsg(db) << "\n";
        return 1;
    }
    std::cout << "[Exito] Conexion establecida con SQLite ('tienda.db').\n";

    const char* sqlCrearTabla = 
        "CREATE TABLE IF NOT EXISTS productos ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre TEXT NOT NULL, "
        "precio REAL NOT NULL);";

    rc = sqlite3_exec(db, sqlCrearTabla, nullptr, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al crear tabla: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }

    int totalRegistros = 0;
    std::string sqlVerificar = "SELECT COUNT(*) FROM productos;";
    sqlite3_exec(db, sqlVerificar.c_str(), callbackConteo, &totalRegistros, &zErrMsg);

    if (totalRegistros == 0) {
        const char* sqlInsertar = 
            "INSERT INTO productos (nombre, precio) VALUES ('Laptop OMEN', 18500.50);"
            "INSERT INTO productos (nombre, precio) VALUES ('Mouse Inalambrico', 450.00);";

        rc = sqlite3_exec(db, sqlInsertar, nullptr, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "Error en insercion: " << zErrMsg << "\n";
            sqlite3_free(zErrMsg);
        } else {
            std::cout << "[Exito] Registros insertados por primera vez.\n";
        }
    } else {
        std::cout << "[Aviso] La base de datos ya contenia registros (" << totalRegistros << ")."
         " Se omite la insercion para evitar duplicados.\n";
    }

    std::cout << "\n--- Consulta de Productos en la BD ---\n";
    const char* sqlConsulta = "SELECT * FROM productos;";
    rc = sqlite3_exec(db, sqlConsulta, callbackConsulta, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error en consulta: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}