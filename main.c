#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char nombresproduc[10][3][30] = {0};
    double precio[10] = {0};
    int n = 0;

    leerDatos("Datos.txt", nombresproduc, precio, &n);

    int opcion1, opcion2;
    char nombreAbuscar[30];

    do {
        printf("Seleccione una opcion:\n1. Imprimir Inventario\n2. Buscar Productos\n3. Editar Productos\n4. Agregar Producto\n5. Eliminar Producto\n>>");
        scanf("%d", &opcion1);
        switch (opcion1) {
            case 1:
                imprimirInventario(nombresproduc, precio, n);
                break;
            case 2:
                printf("Ingrese el producto que desea buscar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar); 
                int index = buscarProductoXNombre(nombresproduc, nombreAbuscar, n);
                imprimirProductoXIndice(nombreAbuscar, nombresproduc, precio, index);
                break;
            case 3:
                printf("Ingrese el nombre del producto que desea editar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar); 
                editarProducto(nombreAbuscar, nombresproduc, precio, n);
                guardarDatos("Datos.txt", nombresproduc, precio, n);
                break;
            case 4:
                agregarProducto(nombresproduc, precio, &n);
                guardarDatos("Datos.txt", nombresproduc, precio, n);
                break;
            case 5:
                printf("Ingrese el nombre del producto que desea eliminar: ");
                while (getchar() != '\n'); 
                scanf("%s", nombreAbuscar);
                eliminarProducto(nombresproduc, precio, &n, nombreAbuscar);
                guardarDatos("Datos.txt", nombresproduc, precio, n);
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
        printf("Desea elegir una nueva opcion: 1.Si / 2.No\n>>");
        scanf("%d", &opcion2);
    } while (opcion2 == 1);

    return 0;
}
