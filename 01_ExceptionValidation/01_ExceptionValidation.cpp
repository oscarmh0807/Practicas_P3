#include <iostream>
#include <string>
#include <stdexcept>

class InvalidEmailException : public std::runtime_error {
public:
    explicit InvalidEmailException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

bool validarEmail(const std::string& email) {
    size_t arroba = email.find('@');
    if (arroba == std::string::npos || arroba == 0) return false;
    if (email.find('@', arroba + 1) != std::string::npos) return false;
    size_t punto = email.rfind('.');
    if (punto == std::string::npos || punto <= arroba + 1) return false;
    return punto + 2 < email.size();
}

int main() {
    std::string entradaEdad;
    std::string email;
    int edad = 0;
    bool edadValida = false;
    bool emailValido = false;

    std::cout << "===== Validacion de Datos con Excepciones =====\n\n";

    while (!edadValida) {
    try {
        std::cout << "Ingrese su edad: ";
        std::cin >> entradaEdad;

        size_t pos = 0;
        edad = std::stoi(entradaEdad, &pos);
        if (pos != entradaEdad.size()) {
            throw std::invalid_argument("caracteres no numericos");
        }
        if (edad < 0 || edad > 130) {
            throw std::out_of_range("fuera de rango");
        }
        edadValida = true;

    } catch (const std::invalid_argument&) {
        std::cerr << "[Error de Edad]: Debe ser un numero entero, sin letras ni simbolos. Intente de nuevo.\n\n";
    } catch (const std::out_of_range&) {
        std::cerr << "[Error de Edad]: Debe estar entre 0 y 130 anios. Intente de nuevo.\n\n";
    }
}

    while (!emailValido) {
        try {
            std::cout << "Ingrese su correo electronico: ";
            std::cin >> email;

            if (!validarEmail(email)) {
                throw InvalidEmailException("El correo debe contener un '@' y un '.' despues de la arroba.");
            }
            emailValido = true; 

        } catch (const InvalidEmailException& e) {
            std::cerr << "[Error de Email]: " << e.what() << " Intente de nuevo.\n\n";
        }
    }

    std::cout << "\n[Exito] Registro completado correctamente.\n";
    std::cout << "-> Edad registrada: " << edad << "\n";
    std::cout << "-> Email registrado: " << email << "\n";

    return 0;
}