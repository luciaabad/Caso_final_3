# Caso_final_3
https://github.com/luciaabad/Caso_final_3.git

En el archivo integrador.cpphacemos los siguiente:

el código proporcionado tiene como objetivo leer el contenido de un archivo y mostrarlo en la consola, con la opción de aplicar colores al texto dependiendo de un parámetro. Además, maneja errores durante el proceso de lectura y apertura del archivo. 

La clase ConsoleBox
La clase ConsoleBox tiene dos métodos:
* new_text(): Este método está vacío en el fragmento de código proporcionado, lo que sugiere que está destinado a realizar alguna acción en el futuro, como la preparación de un área de texto para mostrar datos.
* set_text(const std::string &text): Este método recibe un parámetro de tipo std::string y lo imprime en la consola. 

La función load_script(const char* filename, bool show_script)
Esta es la función principal encargada de cargar y mostrar el contenido de un archivo. Toma dos parámetros:
* filename: El nombre del archivo que se va a leer.
* show_script: Un valor booleano que determina si el contenido del archivo debe mostrarse con colores en la consola.
La función comienza intentando abrir el archivo en modo binario. Si no se puede abrir o el archivo no existe, lanza una excepción (std::runtime_error) con un mensaje que indica el problema. En caso de que el archivo se abra correctamente, se lee en bloques de hasta 4000 bytes y se almacena el contenido en una cadena llamada script. Durante la lectura, se asegura de que cada bloque de datos se termine correctamente con el carácter nulo (\0), necesario para tratar el contenido como una cadena en C.
Una vez que se ha leído todo el archivo, se cierra el archivo y, si el parámetro show_script es verdadero, el contenido del archivo se imprime en la consola utilizando colores. El código para esto hace uso de la clase ColorConsole, que probablemente cambie el color del texto y el fondo (aunque su implementación no está incluida en el fragmento proporcionado). Finalmente, el contenido leído se pasa a un objeto de la clase ConsoleBox mediante el método set_text, que lo muestra en la consola.
Si ocurre cualquier error durante la apertura, lectura o impresión del archivo, se captura la excepción y se imprime un mensaje de error detallado.

La función load_script() sin parámetros
Esta función es una versión simplificada de la anterior, que solicita al usuario el nombre del archivo. Utiliza std::scanf para leer el nombre del archivo desde la entrada estándar y luego llama a la función load_script con el nombre del archivo ingresado y un valor de true para mostrar el contenido con colores.

Manejo de errores
Utilizamos excepciones (std::runtime_error) para capturar problemas como la inexistencia del archivo, errores al abrirlo o al leerlo. Además, garantiza que el archivo se cierre adecuadamente si se produce un error antes de que se termine de leer.

En el archivo integrador.h se definen dos estructuras y funciones relacionadas con la gestión de texto en la consola:

ColorConsole: Contiene secuencias de escape ANSI para cambiar el color del texto y el fondo en la consola (azul para el texto, blanco para el fondo) y para resetear los colores.
ConsoleBox: Tiene dos métodos (new_text y set_text) que probablemente se usan para manejar y mostrar texto en bloques dentro de la consola.
Funciones load_script: Permiten cargar un script desde un archivo. Una variante recibe el nombre del archivo, y la otra solicita al usuario el nombre del archivo a cargar.
El código está orientado a dar formato visual a la salida en la consola y gestionar el contenido de archivos de forma interactiva.

Y por úlrimo en el archivo main.cpp solo se llama a la función.



