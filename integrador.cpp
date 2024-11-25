#include "integrador.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstring>

// Definición de la clase ConsoleBox
void ConsoleBox::new_text() {
    // Implementación de la función (si es necesario)
}

void ConsoleBox::set_text(const std::string &text) {
    std::cout << text << std::endl;
}

// Implementación de la función load_script
void load_script(const char* filename, bool show_script)
{
    std::string script;  // Almacenará el contenido del archivo
    FILE* f = nullptr;

    try
    {
        // Comprobamos si el archivo existe primero (no abierto aún)
        if (fopen(filename, "rb") == nullptr) {
            throw std::runtime_error("El archivo no existe: " + std::string(filename));
        }

        // Intentamos abrir el archivo en modo binario
        f = fopen(filename, "rb");
        if (!f)
        {
            throw std::runtime_error("Error al abrir el archivo: " + std::string(filename));
        }

        // Leer el contenido del archivo en bloques de 4000 bytes
        int c;
        char buf[4001];  // Buffer para almacenar los bloques leídos
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            if (ferror(f)) {
                throw std::runtime_error("Error de lectura del archivo: " + std::string(filename));
            }

            buf[c] = 0;  // Aseguramos que la cadena esté terminada en null
            script.append(buf);  // Añadimos lo leído al contenido del script
        }

        fclose(f);  // Cerramos el archivo

        // Si show_script es verdadero, mostramos el contenido con colores
        if (show_script)
        {
            std::cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            std::cout << script << std::endl;
            std::cout << ColorConsole::reset;  // Resetear los colores después de imprimir
        }

        // Usamos el objeto consoleBox para mostrar el contenido
        ConsoleBox consoleBox;
        consoleBox.new_text();
        consoleBox.set_text(script);

    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        if (f) fclose(f);  // Nos aseguramos de cerrar el archivo en caso de error
    }
}

// Función que solicita al usuario el nombre del archivo y lo carga
void load_script()
{
    char filename[500];  // Arreglo para almacenar el nombre del archivo
    std::cout << "Introduce el nombre del archivo: ";
    std::scanf("%499s", filename);  // Leemos el nombre del archivo desde la entrada estándar

    // Llamamos a la función load_script con el nombre del archivo
    load_script(filename, true);
}
