#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class InvalidEmailException : public std::runtime_error {
public:
    explicit InvalidEmailException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

bool validarEmail(const std::string& email) {
    size_t arroba = email.find('@');
    size_t punto = email.rfind('.');
    return (arroba != std::string::npos && punto != std::string::npos && arroba < punto && arroba > 0);
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

            for (char c : entradaEdad) {
                if (!std::isdigit(c)) {
                    throw std::invalid_argument("La edad debe ser un numero entero valido sin letras.");
                }
            }

            edad = std::stoi(entradaEdad);
            if (edad < 0 || edad > 130) {
                throw std::out_of_range("La edad debe estar en un rango realista de 0 a 130 anios.");
            }

            edadValida = true;

        } catch (const std::exception& e) {
            std::cerr << "[Error de Edad]: " << e.what() << " Intente de nuevo.\n\n";
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