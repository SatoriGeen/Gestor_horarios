#include "d_listadb.h"
#include "d_listadb.c"
#include <stdio.h>


int main(){
    typedef struct {
    char nombreusuario[50];
    char contrasena[50];
    char nombreCompleto[100];
    char tipoUsuario[20]; // Puede ser "Admin" o "Alumno"
} Usuario;

typedef struct {
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[5];
    char profesor[50];
} HorarioClase;

    void menuAdmin(ListaDoble horarios[]) {
    int grupo;
    do {
        printf("\nMenú de Administrador\n");
        printf("1. Agregar un horario\n");
        printf("2. Modificar un horario\n");
        printf("3. Eliminar un horario\n");
        printf("4. Consultar horarios\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &grupo);

        switch (grupo) {
            case 1:
                // este para agregar un horario
                break;
            case 2:
                // este para modificar un horario
                break;
            case 3:
                // este para eliminar un horario
                break;
            case 4:
                // este para consultar horarios
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (grupo != 5);
}

void menuAlumno(ListaDoble horarios[]) {
    int opcion;
    do {
        printf("\nMenú de Alumno\n");
        printf("1. Armar horario de clases\n");
        printf("2. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // usar para armar horario de clases
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 2);
}
}