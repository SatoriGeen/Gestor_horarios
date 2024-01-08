#include "d_listadb.h"
#include "d_listadb.c"
#include <stdio.h>
#include <string.h>

int main(){
    
    DList _2CV1_, _2CV2_, _2CV3_, _2CV4_, _2CV5_;
    create(&_2CV1_);
    create(&_2CV2_);
    create(&_2CV3_);
    create(&_2CV4_);
    create(&_2CV5_);
    DList *listas[] = {&_2CV1_, &_2CV2_, &_2CV3_, &_2CV4_, &_2CV5_};
    
    int opcion, opi, opio, ape;

    UdList listaUsuarios;
    listaUsuarios.start = NULL;

    DListHorarioArmado horarioArmado;
    createHorarioArmado(&horarioArmado);

    insertarUsuarios(&listaUsuarios, "sato", "pass1", "no se 1", "Admin");
    insertarUsuarios(&listaUsuarios, "sata", "pass2", "no se 2", "Alumno");
    insertarUsuarios(&listaUsuarios, "adata", "pass3", "no se 3", "Alumno");

    insertarHorario(&_2CV1_, "Algoritmos y Estructura de Datos", "15:00", "16:30", "2CV1", "Esquivel Centeno Jose Armando");
    insertarHorario(&_2CV1_, "Algebra Lineal", "16:30", "18:00", "2CV1", "Montiel Sanchez Angel Salvador");
    insertarHorario(&_2CV1_, "Calculo Aplicado", "18:30", "20:00", "2CV1", "Juarez Mendez Ana Belem");
    insertarHorario(&_2CV1_, "Mecanica y Electromagnetismo", "20:00", "21:30", "2CV1", "Nava Lara Joel");

    insertarHorario(&_2CV2_, "Calculo Aplicado", "16:30", "18:00", "2CV2", "Zarate Cardenas Alejandro");
    insertarHorario(&_2CV2_, "Fundamentos Economicos", "18:30", "20:00", "2CV2", "Estrada Elizalde Serafin");
    insertarHorario(&_2CV2_, "Algoritmos y Estructura de Datos", "20:00", "21:30", "2CV2", "Macias Perez Francisco Javier");
    insertarHorario(&_2CV2_, "Algebra Lineal", "15:00", "16:30", "2CV2", "Tirado Lule Judith Margarita");

    insertarHorario(&_2CV3_, "Fundamentos Economicos", "15:00", "16:30", "2CV3", "Flores Meraz Yesica Sonia");
    insertarHorario(&_2CV3_, "Algoritmos y Estructura de Datos", "16:30", "18:00", "2CV3", "Cruz Lazaro Ing Apolinar Francisco");
    insertarHorario(&_2CV3_, "Ingenieria Etica y Sociedad", "18:30", "20:00", "2CV3", "Villegas Navarrete Sonia");
    insertarHorario(&_2CV3_, "Calculo Aplicado", "20:00", "21:30", "2CV3", "Cruz Garcia Daniel");

    insertarHorario(&_2CV4_, "Algebra Lineal", "16:30", "18:00", "2CV4", "Levario Medina Sergio");
    insertarHorario(&_2CV4_, "Calculo Aplicado", "15:00", "16:30", "2CV4", "Gonzalez Albarran Gisela");
    insertarHorario(&_2CV4_, "Mecanica y Electromagnetismo", "18:30", "20:00", "2CV4", "Moscoso Malagon Yosafat");
    insertarHorario(&_2CV4_, "Fundamentos Economicos", "20:00", "21:30", "2CV4", "Ortuno Araujo Jesus");

    insertarHorario(&_2CV5_, "Calculo Aplicado", "16:30", "18:00", "2CV2", "Zarate Cardenas Alejandro");
    insertarHorario(&_2CV5_, "Fundamentos Economicos", "18:30", "20:00", "2CV2", "Levario Medina Sergio");
    insertarHorario(&_2CV5_, "Algoritmos y Estructura de Datos", "20:00", "21:30", "2CV2", "Roa Mendez Saul");
    insertarHorario(&_2CV5_, "Algebra Lineal", "15:00", "16:30", "2CV2", "Estrada Elizalde Serafin");

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
                    printf("1. Agregar grupo al horario\n");
                    printf("2. Imprimir horario\n");
                    printf("3. Eliminar grupo\n");
                    printf("4. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);

                    switch (opcion) {
                        case 1:

                            menuDeListas();

                            scanf("%d", &ape);
                            getchar();

                            printf("Clases actuales en grupo: \n");
                        
                            armarHorario(listas[ape - 1], &horarioArmado);

                            break;
                        case 2:
                            
                            printf("\nHorario armado:\n");
                            printf("\n");
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------------");
                            printListArmado(&horarioArmado);
                            printf("\n");

                            break;
                        case 3:
                             eliminarHorarioRep(&horarioArmado);
                            break;
                        case 4:
                            printf("Hasta la proxima :D\n");
                            break;
                        default:
                            printf("Opcion no valida.\n");
                    }
                } while (opcion != 4);

        }
    } else {
        printf("\nUsuario o contrasena incorrectas\n");
    }

    return 0;
}
