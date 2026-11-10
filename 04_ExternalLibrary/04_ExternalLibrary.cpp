#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    std::cout << "--- Manejo de Formato JSON con Libreria Externa ---\n\n";

    json configuracion;
    configuracion["app_nombre"] = "Sistema de Inventario UAG";
    configuracion["version"] = 3.0;
    configuracion["modulos_activos"] = {"Excepciones", "Archivos", "BaseDeDatos", "JSON"};
    configuracion["servidor"]["host"] = "localhost";
    configuracion["servidor"]["puerto"] = 8080;

    std::string jsonTexto = configuracion.dump(4);
    std::cout << "JSON Generado desde C++:\n" << jsonTexto << "\n\n";
    std::string entradaJson = R"({
        "usuario": "oscarmh0807",
        "rol": "Administrador",
        "sesion_activa": true
    })";

        try {
        json objetoParseado = json::parse(entradaJson);
        std::cout << "--- Datos extraidos del objeto parseado ---\n";
        std::cout << "Usuario: " << objetoParseado["usuario"].get<std::string>() << "\n";
        std::cout << "Rol: " << objetoParseado["rol"].get<std::string>() << "\n";
        std::cout << "Sesion Activa: " << (objetoParseado["sesion_activa"].get<bool>() ? "Si" : "No") << "\n";
    } catch (const json::parse_error& e) {
        std::cerr << "[Error JSON] Formato invalido: " << e.what() << "\n";
    } catch (const json::type_error& e) {
        std::cerr << "[Error JSON] Tipo de dato inesperado: " << e.what() << "\n";
    }
    
    return 0;
}