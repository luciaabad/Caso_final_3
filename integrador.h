#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include <string>

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";  // Color azul para el texto
    static constexpr auto bg_white = "\033[47m"; // Fondo blanco
    static constexpr auto reset = "\033[0m";     // Para resetear los colores
};

struct ConsoleBox
{
    void new_text();
    void set_text(const std::string &text);
};

// Función para cargar el script desde un archivo y mostrarlo si es necesario
void load_script(const char* filename, bool show_script = false);

// Función que pide el nombre del archivo al usuario y lo carga
void load_script();

#endif // INTEGRADOR_H

