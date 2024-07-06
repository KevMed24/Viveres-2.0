#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerDatos(const char *filename, char nombresproduc[][3][30], double precio[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de datos.\n");
        return;
    }
    *n = 0;
    while ((*n < 10) && fscanf(file, "%s %s %s %lf", nombresproduc[*n][0], nombresproduc[*n][1], nombresproduc[*n][2], &precio[*n]) == 4) {
        (*n)++;
    }
    fclose(file);
}

void guardarDatos(const char *filename, char nombresproduc[][3][30], double precio[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %s %.2f\n", nombresproduc[i][0], nombresproduc[i][1], nombresproduc[i][2], precio[i]);
    }
    fclose(file);
}

void imprimirInventario(char nombresproduc[][3][30], double precio[], int n) {
    printf("Nombre\t\tCantidad\t\tFecha de Caducidad\t\tPrecio\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t\t%s\t\t\t%s\t\t%.2f\n", nombresproduc[i][0], nombresproduc[i][1], nombresproduc[i][2], precio[i]); 
    }
}

int buscarProductoXNombre(char nombresproduc[][3][30], char nombreABuscar[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombresproduc[i][0], nombreABuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void imprimirProductoXIndice(char nombreAbuscar[], char nombresproduc[][3][30], double precio[], int index) {
    if (index != -1) {
        printf("En el inventario del producto %s muestra:\n", nombreAbuscar);
        printf("Cantidad: %s\n", nombresproduc[index][1]);
        printf("Fecha de Caducidad: %s\n", nombresproduc[index][2]);
        printf("Precio: %.2f\n", precio[index]);  
    } else {
        printf("No existe el producto %s en el registro\n", nombreAbuscar);
    }
}

void editarProducto(char nombreAbuscar[], char nombresproduc[][3][30], double precio[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombresproduc[i][0], nombreAbuscar) == 0) {
            printf("Producto: %s\n", nombresproduc[i][0]);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%s", nombresproduc[i][1]); 
            printf("Ingrese la nueva fecha de caducidad del producto (YYYY-MM-DD): ");
            scanf("%s", nombresproduc[i][2]); 
            printf("Ingrese el nuevo precio del producto: "); 
            scanf("%lf", &precio[i]);  
            break;
        }
    }
}

void agregarProducto(char nombresproduc[][3][30], double precio[], int *n){
    if (*n >= 10) {
        printf("No se pueden agregar mas productos, el inventario esta lleno.\n");
        return;
    }
    printf("Ingrese el nombre del nuevo producto: ");
    scanf("%s", nombresproduc[*n][0]);
    printf("Ingrese la cantidad del nuevo producto: ");
    scanf("%s", nombresproduc[*n][1]); 
    printf("Ingrese la fecha de caducidad del nuevo producto (YYYY-MM-DD): ");
    scanf("%s", nombresproduc[*n][2]); 
    printf("Ingrese el precio del nuevo producto: ");
    scanf("%lf", &precio[*n]);
    (*n)++;
}

void eliminarProducto(char nombresproduc[][3][30], double precio[], int *n, char nombreABuscar[]) {
    int index = buscarProductoXNombre(nombresproduc, nombreABuscar, *n);
    if (index != -1) {
        for (int i = index; i < *n - 1; i++) {
            strcpy(nombresproduc[i][0], nombresproduc[i + 1][0]);
            strcpy(nombresproduc[i][1], nombresproduc[i + 1][1]);
            strcpy(nombresproduc[i][2], nombresproduc[i + 1][2]);
            precio[i] = precio[i + 1];
        }
        (*n)--;
        printf("Producto %s ha sido eliminado con exito.\n", nombreABuscar);
    } else {
        printf("No existe el producto %s en el inventario.\n", nombreABuscar);
    }
}
