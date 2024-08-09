# ft_printf

## Descripción

El proyecto **libftprintf.a** tiene como propósito desarrollar una versión personalizada de la función `printf()` en C. Esta librería se convierte en una herramienta esencial para cualquier programador que busque entender a fondo la salida formateada de texto y cómo manejar diferentes tipos de datos en C. Al crear tu propia implementación de `printf()`, tendrás el control total sobre cómo se presenta la información.

## Funcionalidades

- **Implementación de conversiones esenciales**: La función `ft_printf()` replica las conversiones más utilizadas del `printf()` original, como la impresión de caracteres, cadenas, números y más.
- **Soporte para múltiple tipos de datos**: `ft_printf()` maneja correctamente enteros, caracteres, punteros y números hexadecimales, asegurando que la salida formateada sea precisa.
- **Compatibilidad con la libft**: Puedes utilizar las funciones de la libft para facilitar el desarrollo, aprovechando todas las utilidades previamente creadas.

## Uso

### Función Principal

- **Nombre de la función**: `ft_printf`
- **Prototipo**: `int ft_printf(const char *format, ...);`
- **Parámetros**:
  - `format`: Cadena de formato que especifica cómo se deben formatear e imprimir los argumentos posteriores.
- **Valor de retorno**:
  - Devuelve el número total de caracteres impresos, o un valor negativo si ocurre un error.

### Conversiones Implementadas

- **%c**: Imprime un solo carácter.
- **%s**: Imprime una cadena de texto.
- **%p**: Imprime un puntero en formato hexadecimal.
- **%d / %i**: Imprime un número decimal con signo.
- **%u**: Imprime un número decimal sin signo.
- **%x / %X**: Imprime un número hexadecimal en minúsculas o mayúsculas, respectivamente.
- **%%**: Imprime un símbolo de porcentaje literal.

## Compilación

Para compilar la librería y generar el archivo `libftprintf.a`, utiliza el siguiente comando en el directorio raíz del proyecto:

```make```
Esto generará el archivo `libftprintf.a`, que se puede enlazar con tus proyectos en C.

### Comandos del Makefile

- **all**: Compila y genera la librería.
- **clean**: Elimina los archivos objeto (.o).
- **fclean**: Elimina los archivos objeto y la librería generada.
- **re**: Limpia y recompila todo desde cero.

### Archivos

- **Parte obligatoria**:
  - `ft_printf.c`: Contiene la implementación principal de `ft_printf()`.
  - `ft_printf.h`: Define el prototipo de la función y las macros necesarias.
  - `Makefile`: Automatiza la compilación y creación de la librería.

### Notas Relevantes

- La función `ft_printf()` está diseñada para manejar eficientemente la memoria, evitando fugas y asegurando que cada conversión se realice correctamente.
- El archivo generado `libftprintf.a` estará disponible en la raíz del repositorio, listo para ser integrado en cualquier proyecto en C.
