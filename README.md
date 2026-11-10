# Practicas_P3

**Estudiante:** Oscar Miguel Huitrón Zenteno  
**Materia:** Programación Orientada a Objetos  
**Institución:** Universidad Autónoma de Guadalajara, Campus Tabasco  
**Maestro:** Manuel Balderas Victoria  
**Lenguaje:** C++ con xmake

## Descripción

Cinco ejercicios del tercer parcial sobre excepciones, archivos de texto, bases de datos SQLite, una librería externa y manejo integrado de errores.

## Estructura

| Carpeta | Contenido |
|---|---|
| `01_ExceptionValidation` | Validación de edad y correo con excepciones |
| `02_TextFile` | Guardar y leer una lista de tareas en un archivo de texto |
| `03_DataBase` | SQLite: tabla de productos, inserción y consulta |
| `04_ExternalLibrary` | nlohmann/json, incluida como `json.hpp` v3.12.0 |
| `05_ErrorIntegration` | Archivo y base de datos con excepciones propias |

Cada carpeta tiene su `.cpp`, su `xmake.lua` y su `.gitignore`.

## Cómo ejecutar

    cd 03_DataBase
    xmake
    xmake run

SQLite se descarga solo gracias a `add_requires("sqlite3")`.

## Declaración de uso de IA

Usé IA como apoyo puntual, según la rúbrica:

- Ejercicio 1 y 5: dudas de sintaxis al heredar de `std::runtime_error`.
- Ejercicio 3: orientación sobre callbacks de SQLite y configuración del `xmake.lua`.
- Ejercicio 4: identificar la librería nlohmann/json y configurar el `xmake.lua`.
- Ejercicio 5: banderas de `sqlite3_open_v2`.
- General: estructura de este README y la revisión de redacción del reporte.

El diseño de las soluciones, el código, la depuración y las pruebas fueron míos.