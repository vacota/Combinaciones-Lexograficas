# Combinaciones-Lexicograficas

### Descripción

Un programa el cual calcula las combinaciones de n en r, valores los cuales son proporcionados por el usuario de manera manual. Al capturarse el conjunto, no solo se calculan las combinaciones sino que también son ordenadas en orden lexicográfico para después ser mostradas en un archivo csv dado al usuario.

### Requisitos del sistema

- **GCC** (GNU Compiler Collection)
- Se necesita tener un compilador C++20. Las bibliotecas/librerías usadas ya están dentro del programa pues forman parte de la estandar, las cuales corren en Windows, Linux, etc por igual. El programa fue creado y corrido en el sistema operativo de Microsoft Windows 11. 

### Instrucciones de compilación y ejecución

**Desde la terminal:**
1. Clone el repositorio:
   ```sh
   git clone https://github.com/vacota/Combinaciones-Lexograficas.git
   ```
2. Entre al directorio del proyecto:
   ```sh
   cd Combinaciones-Lexograficas
   ```
3. Compile el código:
   ```sh
   g++ .cpp -o sorting_time -std=c++20
   ```
4. Ejecute el código
   ```sh
   ./
   ```

### Explicación del algoritmo

El algoritmo lo que hace es básicamente encontrar el valor que se encuentre más hacia la derecha y el cual cuente con la posibilidad de ser aumentado a uno mayor que él sin desbordarse o alterar la estructura del conjunto de tal manera que los demás permanezcan ordenados. Este valor descrito es el que se convierte en el pivote del algoritmo y el cual se encuentra con dos caminos: 1. ubicar el pivote y incrementar si es que puede ser incrementado, o 2. no ubicar dicho pivote por lo que por consecuencia se termina el proceso de búsqueda y va con lo siguiente. El algoritmo aparte de realizar esto, logra imitar de manera exitosa el proceso de calcular combinaciones pero obviamente con el poder de una computadora. Su complejidad de tiempo como es observada es O(C(n,r)) y es vacía de recursión en el proceso.

### Orden Lexicográfico

El orden lexicográfico aplicado en el caso de la combinatoria 

### Validación de entrada

Las validaciones de entrada usadas en el siguiente código son:

- **n debe ser un entero mayor o igual a 1 (n >= 1)**
- - **r debe ser un enetero mayor o igual a 0 (r >= 0)**
- **r no puede ser mayor que n (r <= n)**


### Verificación C(n,r)



### Autor(a)

Denzel Omar Rivera Urias
