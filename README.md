# Practicas_P3

**Estudiante:** Oscar Miguel Huitrón Zenteno  
**Materia:** Programación Orientada a Objetos  
**Institución:** Universidad Autónoma de Guadalajara (UAG)  
**Maestro:** Manuel Balderas Victoria  
**Lenguaje:** C++  

---

## Descripción del Repositorio

Este repositorio contiene la solución a los 5 ejercicios prácticos correspondientes al **Tercer Parcial** (Unidad 4: Elementos Complementarios). El objetivo de estas prácticas es implementar conceptos clave de robustez y persistencia de software en C++, abordando temas como **validación de datos con excepciones personalizadas**, **manejo de archivos de texto**, **conexión e inserción en bases de datos relacionales (SQLite3)**, **integración de librerías externas (nlohmann/json)** y **gestión integrada de errores**.

---

## Estructura del Proyecto

Cada ejercicio se encuentra organizado dentro de su propia carpeta individual, conteniendo su respectivo archivo fuente (`.cpp`) y su configuración de compilación `xmake.lua`:

```text
Practicas_P3/
├── .gitignore               # Configuración para omitir ejecutables y temporales de xmake
├── README.md                # Documentación principal del proyecto
├── 01_ExceptionValidation/       # Ejercicio 1: Validación con excepciones
│   ├── 01_ExceptionValidation.cpp
│   └── xmake.lua
├── 02_TextFile/          # Ejercicio 2: Archivo de texto (lectura y escritura)
│   ├── 02_TextFile.cpp
│   └── xmake.lua
├── 03_DataBase/      # Ejercicio 3: Conexión a BD SQLite3 (tabla productos)
│   ├── 03_DataBase.cpp
│   └── xmake.lua
├── 04_ExternalLibrary/         # Ejercicio 4: Uso de librería externa
│   ├── 04_ExternalLibrary.cpp
│   ├── json.hpp
│   └── xmake.lua
└── 05_ErrorIntegration/       # Ejercicio 5: Integración con manejo de errores
    ├── 05_ErrorIntegration.cpp
    └── xmake.lua
```

---
## Resumen de Ejercicios
01 - ExceptionValidation (01_ExceptionValidation.cpp): Validación estricta de entradas de usuario (edad y correo electrónico) mediante excepciones personalizadas y ciclos de control while que previenen registros con datos erróneos o incompletos.

02 - TextFile (02_TextFile.cpp): Gestión de persistencia en disco guardando una lista de tareas en un archivo de texto con std::ofstream y recuperándolas ordenadamente mediante std::ifstream y std::getline.

03 - DataBase (03_DataBase.cpp): Conexión a una base de datos relacional SQLite3 (tienda.db), creación de tabla de productos e inserción/consulta de datos, utilizando SELECT COUNT(*) para evitar registros duplicados en ejecuciones sucesivas.

04 - ExternalLibrary (04_ExternalLibrary.cpp): Implementación de la librería header-only nlohmann/json (json.hpp) para la serialización y parseo de datos en formato JSON desde C++.

05 - ErrorIntegration (05_ErrorIntegration.cpp): Integración de manejo de excepciones personalizadas (FileOpenException y DatabaseException) con sqlite3_open_v2 para capturar fallos en archivos y conexiones sin que el programa colapse.

## Declaración del Uso de IA
De acuerdo con los lineamientos de la rúbrica de la materia, se declara el uso de Inteligencia Artificial durante el desarrollo de estas prácticas bajo el siguiente alcance:

Asistencia en la recomendación e identificación de la librería nlohmann/json (json.hpp) para el manejo sencillo de datos JSON en C++.

Orientación para la estructuración de los callbacks en SQLite3, consulta de banderas avanzadas de apertura como SQLITE_OPEN_READWRITE en sqlite3_open_v2 y resolución de dudas de sintaxis para la jerarquía de herencia de std::runtime_error.

Apoyo en la configuración del archivo xmake.lua (add_requires("sqlite3") y add_includedirs(".")) para la correcta inclusión de dependencias.

Creación y estructura del archivo README.

La lógica del diseño de las soluciones, la implementación del código fuente, el manejo de bucles de control, la depuración y las pruebas de ejecución fueron realizadas de manera autónoma.
---