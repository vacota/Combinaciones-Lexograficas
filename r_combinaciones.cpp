#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// Proceso que genera combinaciones, crea el archivo .csv y asigna un contador de r-combinaciones de forma manual
void proceso_combinaciones(int n, int r, unsigned long long &contador);

// Función que imprime un conjunto generado
void procesar_conjunto(int arr[], int tam);

// Función factorial para el calculo del coeficiente binomial
long double factorial(int n);

// Funciñon que calcula las combinaciones de n en r
long double combinaciones(int n, int r);

using namespace std;
using namespace filesystem;

int main() {
    int n;
    int r;
    unsigned long long contador_combinaiones;

    cout << "Programa procesa las combinaciones de n en r del conjunto {1, 2, ..., n}, siendo n menor o igual a 1574." << endl;
    do {
        cout << "Dicte la cantidad de elementos que tendrá el conjunto \"n\": ";
        cin >> n;
    }while (n < 1 || n > 1574);
    do {
        cout << "Dicte el tamaño \"r\" que tendrán los subconjuntos con combinaciones: ";
        cin >> r;
    }while (r < 0 || r > n);

    cout << endl;
    cout << "Coeficiente binomial (valor teórico): " << combinaciones(n, r) << endl;
    cout << endl;
    cout << "Listado de combinaciones (exportadas a .csv): " << endl;

    proceso_combinaciones(n, r, contador_combinaiones);

    cout << "Valor del contador: " << contador_combinaiones <<endl;
    cout << "Valor del coeficiente biomial: " << combinaciones(n, r) << endl;

    // Condicional para probar que el valor teórico y el contador si coinciden
    if (combinaciones(n, r) == contador_combinaiones) {
        cout << "Son el mismo, el resultado fue correcto." << endl;
    }
    else {
        cout << "No son el mismo, el resultado fue incorrecto." << endl;
    }

    string cadena_n = to_string(n), cadena_r = to_string(r);
    string nombre_archivo = "\"combinaciones_n(" + cadena_n + ")_r(" + cadena_r + ")\"" ;

    path directorio_actual = current_path();
    string string_directorio = directorio_actual.string();
    cout << "La dirección en la que se puede encontrar el archivo .csv es: " << string_directorio << " y se llama " << nombre_archivo << endl;

    return 0;
}

void proceso_combinaciones(int n, int r, unsigned long long &contador) {
    int s[r];
    for (int i = 0; i < r; i++) {
        s[i] = i + 1;
    }

    string cadena_n = to_string(n), cadena_r = to_string(r);
    string nombre_archivo = "combinaciones_n(" + cadena_n + ")_r(" + cadena_r + ").csv" ;
    ofstream salida_combinaciones(nombre_archivo);
    salida_combinaciones << "Contador, Combinaciones," << endl << "1,";
    salida_combinaciones << "\"";
    for (int i = 0; i < r; i++) {
        salida_combinaciones << s[i];
        if (i != r - 1) {
            salida_combinaciones << ", ";
        }
    }
    salida_combinaciones << "\"," << endl;

    contador = 1;
    cout << contador << "- ";
    procesar_conjunto(s, r);

    while (true) {
        int m = r - 1;
        int val_max = n;

        while (m >= 0 && s[m] == val_max) {
            m--;
            val_max--;
        }
        if (m < 0) {
            break;
        }

        s[m]++;

        for (int i = m + 1; i < r; i++) {
            s[i] = s[i - 1] + 1;
        }

        contador++;
        salida_combinaciones << contador << ",";
        salida_combinaciones << "\"";
        for (int i = 0; i < r; i++) {
            salida_combinaciones << s[i];
            if (i != r - 1) {
                salida_combinaciones << ", ";
            }
        }
        salida_combinaciones << "\"," << endl;

        cout << contador << "- ";
        procesar_conjunto(s, r);
    }
}

void procesar_conjunto(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i];
        if (i != tam - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

long double combinaciones(int n, int r){
    int nr = n - r;
    long double fac = factorial(n) / (factorial(nr) * factorial(r));
    return fac;
}

long double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    long double fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    return fac;
}