#include "d_listadb.h"
#include "d_listadb.c"
#include <stdio.h>
#include <string.h>

int iniciarSesion(UdList *UDLi, char nombreUsuario[], char contrasena[]);

int main(){
    
    DList _2CV1_, _2CV2_, _2CV3_, _2CV4_;
    create(&_2CV1_);
    create(&_2CV2_);
    create(&_2CV3_);
    create(&_2CV4_);
    DList *listas[] = {&_2CV1_, &_2CV2_, &_2CV3_, &_2CV4_};
    
    int opcion;
    int opi;
    int opio;

    UdList listaUsuarios;
    listaUsuarios.start = NULL;

    insertarUsuarios(&listaUsuarios, "sato", "pass1", "no se 1", "Admin");
    insertarUsuarios(&listaUsuarios, "sata", "pass2", "no se 2", "Alumno");
    insertarUsuarios(&listaUsuarios, "adata", "pass3", "no se 3", "Alumno");

    char nombreUsuario[15];
    char contrasena[50];

    printf("Ingrese el nombre de usuario: ");
    fgets(nombreUsuario, sizeof(nombreUsuario), stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = '\0';

    printf("Ingrese la contrasena: ");
    fgets(contrasena, sizeof(contrasena), stdin);
    contrasena[strcspn(contrasena, "\n")] = '\0';

    int val = iniciarSesion(&listaUsuarios, nombreUsuario, contrasena);

    if (val) {
        UsuarioDL *aux = listaUsuarios.start;
        while (aux != NULL && strcmp(aux->nombreUsuario, nombreUsuario) != 0) {
            aux = aux->next;
        }

        switch (strcmp(aux->rolUsuario, "Admin")) {
            case 0:

                do {
                printf("\n1. Agregar un horario\n");
                printf("2. Modificar un horario\n");
                printf("3. Eliminar un horario\n");
                printf("4. Consultar horarios\n");
                printf("5. Insertar Usuarios\n");
                printf("6. Salir\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:

                        menuDeListas();

                        scanf("%d", &opcion);
                        getchar();

                        manejarInsercionEnHorario(listas[opcion - 1], opcion);

                        break;
                    case 2:

                        menuDeListas();

                        scanf("%d", &opi);
                        getchar(); 

                        printf("elige clase a editar \n");

                        imprimirCLases(listas[opi - 1]);
                        manejarEdicionEnGrupo(listas[opi - 1], opi);

                        break;
                    case 3:

                        menuDeListas();

                        scanf("%d", &opio);
                        getchar(); 

                        printf("elige clase a editar \n");
                        imprimirCLases(listas[opio - 1]);

                        manejarReduccionEnGrupo(listas[opio - 1], opio);

                        break;
                    case 4:

                        menuDeListas();

                        scanf("%d", &opio);
                        getchar(); 

                        printf("Clases actuales en grupo: \n");
                        imprimirCLases(listas[opio - 1]);

                        break;
                    case 5:

                        manejarInsercionDeUsuarios(&listaUsuarios);

                        break;
                    case 6:
                        getchar();
                        printf("Hasta la proxima :D\n");
                        break;
                    default:
                        printf("Opcion no valida.\n");
                }
            } while (opcion != 6);

                break;
            default:

                do {
                    printf("\nMenu de Alumno\n");
                    printf("1. Armar horario de clases\n");
                    printf("2. Imprimir horario\n");
                    printf("3. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);

                    switch (opcion) {
                        case 1:

                            break;
                        case 2:
                            
                            break;
                        case 3:
                            printf("Hasta la proxima :D\n");
                            break;
                        default:
                            printf("Opcion no valida.\n");
                    }
                } while (opcion != 3);

        }
    } else {
        printf("\nUsuario o contrasena incorrectas\n");
    }

    return 0;
}