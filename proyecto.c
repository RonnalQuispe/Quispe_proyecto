#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto
{
    char codigo[25];
    char nomproduc[50];
    char descproduc[50];
    int cantidad;
    float precioCompra;
};

void ingresarDatos(struct producto *productos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese los datos del producto %d:\n", i + 1);

        printf("Codigo del producto: ");
        gets(productos[i].codigo);
        fflush(stdin);

        printf("Nombre del producto: ");
        gets(productos[i].nomproduc);
        fflush(stdin);

        printf("Descripcion del producto: ");
        gets(productos[i].descproduc);
        fflush(stdin);

        printf("Precio de compra: ");
        scanf("%f", &(productos[i].precioCompra));
        fflush(stdin);

        printf("Cantidad: ");
        scanf("%d", &(productos[i].cantidad));
        fflush(stdin);
        printf("\n");
    }
}

void imprimirDatos(struct producto *productos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Datos del producto %d: COD.: %s - NOMBRE: %s - DESC.: %s - PRECIO: %.2f - CANTIDAD: %d\n", i + 1, productos[i].codigo, productos[i].nomproduc, productos[i].descproduc, productos[i].precioCompra, productos[i].cantidad);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int opcion;
    struct producto *productos = NULL; // Cambio: inicializar productos fuera del bucle para mantener la referencia entre iteraciones

    do
    {
        printf("\n");
        printf("..........MENU...........\n");
        printf("\n");
        printf("1. Ingresar los datos\n");
        printf("2. Mostrar el inventario\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
        case 1:
            printf("Ingrese la cantidad de productos que va a registrar: ");
            scanf("%d", &n);
            fflush(stdin);
            
            // Cambio: liberar la memoria si ya se había asignado antes
            free(productos);
            
            productos = malloc(n * sizeof(struct producto));
            ingresarDatos(productos, n);
            break;

        case 2:
            if (productos != NULL)
            {
                imprimirDatos(productos, n);
                printf("\n");
            }
            else
            {
                printf("Error: Debe ingresar los datos primero.\n");
            }
            break;

        case 3:
            printf("Programa cerrado, que tenga un buen dia. :3 <3\n");
            break;

        default:
            printf("Opcion inválida\n");
            break;
        }
    } while (opcion != 3);

    // Cambio: liberar la memoria al final del programa
    free(productos);

    return 0;
}
