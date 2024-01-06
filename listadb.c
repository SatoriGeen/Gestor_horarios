#include "d_listadb.h"
#include "d_listadb.c"
#include <stdio.h>
#include <string.h>

int iniciarSesion(UdList *UDLi, char nombreUsuario[], char contrasena[]);
void printListArmado(DListHorarioArmado* DLiArmado);
void armarHorario(DList* DLi, DListHorarioArmado* DLiArmado);
void createHorarioArmado(DListHorarioArmado* DLiArmado);
bool existeHorario(DListHorarioArmado* DLiArmado, const char* horaInicio, const char* horaFin);
void eliminarHorarioRep(DListHorarioArmado* DLiArmado);
void mostrarHorariosArmados(DListHorarioArmado* DLiArmado);

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
    int ape;

    UdList listaUsuarios;
    listaUsuarios.start = NULL;

    DListHorarioArmado horarioArmado;



    insertarUsuarios(&listaUsuarios, "sato", "pass1", "no se 1", "Admin");
    insertarUsuarios(&listaUsuarios, "sata", "pass2", "no se 2", "Alumno");
    insertarUsuarios(&listaUsuarios, "adata", "pass3", "no se 3", "Alumno");

    insertarHorario(&_2CV1_, "Algoritmos y Estructura de Datos", "15:00", "16:30", "2CV1", "Esquivel Centeno Jose Armando");
    insertarHorario(&_2CV1_, "Algebra Lineal", "16:30", "18:00", "2CV1", "Montiel Sanchez Angel Salvador");
    insertarHorario(&_2CV1_, "Calculo Aplicado", "18:30", "20:00", "2CV1", "Juarez Mendez Ana Belem");
    insertarHorario(&_2CV1_, "Mecanica y Electromagnetismo", "20:00", "21:30", "2CV1", "Nava Lara Joel");
    insertarHorario(&_2CV1_, "Ingenieria Etica y Sociedad", "15:30", "17:00", "2CV1", "Juarez Leon Carlos");

    insertarHorario(&_2CV2_, "Calculo Aplicado", "16:00", "17:30", "2CV2", "Zarate Cardenas Alejandro");
    insertarHorario(&_2CV2_, "Mecanica y Electromagnetismo", "17:30", "19:00", "2CV2", "Hernandez Garcia Rosa Alba");
    insertarHorario(&_2CV2_, "Fundamentos Economicos", "18:30", "20:00", "2CV2", "Estrada Elizalde Serafin");
    insertarHorario(&_2CV2_, "Algoritmos y Estructura de Datos", "20:00", "21:30", "2CV2", "Macias Perez Francisco Javier");
    insertarHorario(&_2CV2_, "Algebra Lineal", "15:30", "17:00", "2CV2", "Tirado Lule Judith Margarita");

    insertarHorario(&_2CV3_, "Fundamentos Economicos", "15:00", "16:30", "2CV3", "Flores Meraz Yesica Sonia");
    insertarHorario(&_2CV3_, "Algoritmos y Estructura de Datos", "16:30", "18:00", "2CV3", "Cruz Lazaro Ing Apolinar Francisco");
    insertarHorario(&_2CV3_, "Ingenieria Etica y Sociedad", "18:30", "20:00", "2CV3", "Villegas Navarrete Sonia");
    insertarHorario(&_2CV3_, "Calculo Aplicado", "20:00", "21:30", "2CV3", "Cruz Garcia Daniel");
    insertarHorario(&_2CV3_, "Mecanica y Electromagnetismo", "15:30", "17:00", "2CV3", "Leon Hernandez Miguel Abel");

    insertarHorario(&_2CV4_, "Algebra Lineal", "16:00", "17:30", "2CV4", "Levario Medina Sergio");
    insertarHorario(&_2CV4_, "Calculo Aplicado", "17:30", "19:00", "2CV4", "Gonzalez Albarran Gisela");
    insertarHorario(&_2CV4_, "Mecanica y Electromagnetismo", "18:30", "20:00", "2CV4", "Moscoso Malagon Yosafat");
    insertarHorario(&_2CV4_, "Fundamentos Economicos", "20:00", "21:30", "2CV4", "Ortuno Araujo Jesus");
    insertarHorario(&_2CV4_, "Ingenieria Etica y Sociedad", "15:30", "17:00", "2CV4", "Gonzalez Garcia Gustavo");



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

                            menuDeListas();
                            scanf("%d", &ape);
                            getchar();
                            printf("Clases actuales en grupo: \n");
                            printf("\n");
                            printf("\n");
                            printf("----------------------------------------------------------------------------------------------------------------------------------------------------");
                            imprimirHorario(listas[ape - 1]);
                            createHorarioArmado(&horarioArmado);


                            armarHorario(listas[ape - 1], &horarioArmado);

                            break;
                        case 2:
                            

                            printf("\nHorario armado:\n");
                            printListArmado(&horarioArmado);

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

void armarHorario(DList* DLi, DListHorarioArmado* DLiArmado) {
    NodeDL* aux = DLi->start;
    int contador = 0;
    int seleccion;

    printf("Selecciona los horarios que deseas agregar al horario armado:\n");

    while (aux != NULL && contador < 4) {

        printf("\n");
        printf("\t| Clase: %s\t\t", aux->nombreClase);
        printf("| Hora inicio: %s\t", aux->horaInicio);
        printf("| Hora fin: %s\t", aux->horaFin);
        printf("| Grupo: %s\t", aux->grupo);
        printf("| Profesor: %s |\n", aux->profesor);
        printf("\n");

        printf("Teclea 1 para seleccionar este horario, 0 para pasar al siguiente: ");
        scanf("%d", &seleccion);

        if (seleccion == 1) {

            if (!existeHorario(DLiArmado, aux->horaInicio, aux->horaFin)) {

                NodeHorarioArmado* newArmado = (NodeHorarioArmado*)malloc(sizeof(NodeHorarioArmado));
                newArmado->next = DLiArmado->startArmado;

                if (DLiArmado->startArmado != NULL) {
                    DLiArmado->startArmado->prev = newArmado;
                }

                DLiArmado->startArmado = newArmado;

                strncpy(newArmado->nombreClase, aux->nombreClase, sizeof(newArmado->nombreClase) - 1);
                strncpy(newArmado->horaInicio, aux->horaInicio, sizeof(newArmado->horaInicio) - 1);
                strncpy(newArmado->horaFin, aux->horaFin, sizeof(newArmado->horaFin) - 1);
                strncpy(newArmado->grupo, aux->grupo, sizeof(newArmado->grupo) - 1);
                strncpy(newArmado->profesor, aux->profesor, sizeof(newArmado->profesor) - 1);

                newArmado->nombreClase[sizeof(newArmado->nombreClase) - 1] = '\0';
                newArmado->horaInicio[sizeof(newArmado->horaInicio) - 1] = '\0';
                newArmado->horaFin[sizeof(newArmado->horaFin) - 1] = '\0';
                newArmado->grupo[sizeof(newArmado->grupo) - 1] = '\0';
                newArmado->profesor[sizeof(newArmado->profesor) - 1] = '\0';

                newArmado->prev = NULL;

                contador++;
            } else {
                printf("No se puede ingresar este horario, ya existe un horario con las mismas horas de inicio y fin. Elige otro por favor.\n");
            }
        }

        aux = aux->next;
    }
}


void printListArmado(DListHorarioArmado* DLiArmado) {
    NodeHorarioArmado* aux = DLiArmado->startArmado;

    while (aux != NULL) {
        printf("\n");
        printf("\t| Clase: %s\t\t", aux->nombreClase);
        printf("| Hora inicio: %s\t", aux->horaInicio);
        printf("| Hora fin: %s\t", aux->horaFin);
        printf("| Grupo: %s\t", aux->grupo);
        printf("| Profesor: %s |\n", aux->profesor);
        printf("\n");

        aux = aux->next;
    }
}

void createHorarioArmado(DListHorarioArmado* DLiArmado) {
    DLiArmado->startArmado = NULL;
}

bool existeHorario(DListHorarioArmado* DLiArmado, const char* horaInicio, const char* horaFin) {
    NodeHorarioArmado* aux = DLiArmado->startArmado;

    while (aux != NULL) {
        if (strcmp(aux->horaInicio, horaInicio) == 0 && strcmp(aux->horaFin, horaFin) == 0) {
            return true;
        }
        aux = aux->next;
    }

    return false;
}

void eliminarHorarioRep(DListHorarioArmado* DLiArmado) {

    printListArmado(DLiArmado);

    if (DLiArmado->startArmado == NULL) {
        printf("No hay horarios armados para eliminar.\n");
        return;
    }

    int seleccion;
    printf("Seleccione el numero del horario que desea eliminar (ingrese 0 para cancelar): ");
    scanf("%d", &seleccion);

    if (seleccion == 0) {
        printf("Operacion cancelada.\n");
        return;
    }

    NodeHorarioArmado* actual = DLiArmado->startArmado;
    int contador = 1;

    while (actual != NULL && contador < seleccion) {
        actual = actual->next;
        contador++;
    }

    if (actual != NULL) {

        if (actual->prev != NULL) {
            actual->prev->next = actual->next;
        } 
        else {
            DLiArmado->startArmado = actual->next;
        }
        if (actual->next != NULL) {
            actual->next->prev = actual->prev;
        }

        free(actual);
        printf("Horario eliminado.\n");
    } else {
        printf("No se encontro horario.\n");
    }
}
