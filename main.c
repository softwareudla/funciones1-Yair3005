#include <stdio.h>
#include "inventario.h"

int main() {
    char productos[limite][50];
    float precios[limite];
    int n;
    float resultados[4]; // Guarda total, promedio, max y min

    n = obtenerNumeroProductos();
    ingresarProductos(productos, precios, n);
    imprimirProductos(productos, precios, n);
    calcularEstadisticas(precios, n, resultados);

    printf("El valor total del inventario es: %.2f\n", resultados[0]);
    printf("El promedio del inventario es: %.2f\n", resultados[1]);
    printf("Producto mas caro: %.2f\n", resultados[2]);
    printf("Producto mas barato: %.2f\n", resultados[3]);

    buscarProducto(productos, precios, n);

    return 0;
}
