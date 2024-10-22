#include <stdio.h>
#include <string.h>
#include "inventario.h"

int obtenerNumeroProductos() {
    int n;
    do {
        printf("¿Cuantos productos va a ingresar? (Max %d): ", limite);
        scanf("%d", &n);
        if (n > limite || n <= 0) {
            printf("Numero invalido. Intente nuevamente.\n");
        }
    } while (n > limite || n <= 0);
    return n;
}

void ingresarProductos(char productos[][50], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        getchar();
        fgets(productos[i], 50, stdin);  

        int precioValido = 0; 

        while (precioValido == 0) {  
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);

           
            if (precios[i] < 0) {
                printf("El precio no puede ser negativo. Intente nuevamente.\n");
            } else {
                precioValido = 1;  
            }
        }
    }
}

void calcularEstadisticas(float precios[], int n, float resultados[]) {
    float total = 0, maximo = precios[0], minimo = precios[0];

    for (int i = 0; i < n; i++) {
        total += precios[i];
        if (precios[i] > maximo) {
            maximo = precios[i];
        }
        if (precios[i] < minimo) {
            minimo = precios[i];
        }
    }

    resultados[0] = total;
    resultados[1] = total / n;
    resultados[2] = maximo;
    resultados[3] = minimo;
}

void buscarProducto(char productos[][50], float precios[], int n) {
    char busqueda[50];
    int encontrado;

    do {
        encontrado = 0;
        printf("Ingrese el nombre del producto para saber su precio: ");
        getchar();  
        fgets(busqueda, 50, stdin);
        

        for (int i = 0; i < n; i++) {
            if (strcmp(productos[i], busqueda) == 0) {
                printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            char opcion;
            printf("Producto no encontrado. ¿Desea intentar nuevamente? (s/n): ");
            scanf(" %c", &opcion);
            if (opcion == 'n' || opcion == 'N') {
                break;
            }
        }
    } while (!encontrado);
}

void imprimirProductos(char productos[][50], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s .- %.2f\n", productos[i], precios[i]);
    }
}