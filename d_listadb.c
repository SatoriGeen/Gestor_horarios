#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void create(DList *DLi){
    DLi->start=NULL;
}

int is_empty(DList DLi){
    if (DLi.start==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertarHorario(DList *DLi, char nombreClase[50], char horaInicio[10], char horaFin[10], char grupo[10], char profesor[50]){
    
    NodeDL *new=(NodeDL *)malloc(sizeof(NodeDL));

    new->next=DLi->start;
    
    if (!is_empty(*DLi)){
        DLi->start->prev=new;
    }

    DLi->start=new;
    //asignacion de elementos a la cadena
    strncpy(new->nombreClase, nombreClase, sizeof(new->nombreClase) - 1);
    strncpy(new->horaInicio, horaInicio, sizeof(new->horaInicio) - 1);
    strncpy(new->horaFin, horaFin, sizeof(new->horaFin) - 1);
    strncpy(new->grupo, grupo, sizeof(new->grupo) - 1);
    strncpy(new->profesor, profesor, sizeof(new->profesor) - 1);
    //asignacion de caracter nulo al final de cada cadena para evitar problemas en el bufer
    new->nombreClase[sizeof(new->nombreClase) - 1] = '\0';
    new->horaInicio[sizeof(new->horaInicio) - 1] = '\0';
    new->horaFin[sizeof(new->horaFin) - 1] = '\0';
    new->grupo[sizeof(new->grupo) - 1] = '\0';
    new->profesor[sizeof(new->profesor) - 1] = '\0';

    new->prev=NULL;

}

void imprimirHorario(DList *Dli){
    NodeDL *aux = Dli->start;
    if (is_empty(*Dli)){

        printf("Grupo vacio");

    }
    else{
        while (aux!=NULL)
        {

            printf("\n");
            printf("Clase: %s\n", aux->nombreClase);
            printf("Hora inicio: %s\n", aux->horaInicio);
            printf("Hora fin: %s\n", aux->horaFin);
            printf("Grupo: %s\n", aux->grupo);
            printf("Profesor %s\n", aux->profesor);
            printf("\n");
            aux=aux->next;

        }   

    } 

}

void mostrarGrupos(){
    printf("Lista de grupos existentes: \n");
    printf("1. 2CV1\n");
    printf("2. 2CV2\n");
    printf("3. 2CV3\n");
    printf("4. 2CV4\n");
}

void menuAdmin(){
    int eleccion;
    int opcion;
    do
    {
        printf("\n---BIENVENIDO---\n");
        printf("1. Agregar usuario nuevo\n");
        printf("2. Editar horarios\n");
        printf("3. Salir\n");
        printf("Por favor digite el numero de accion deseada:");
        scanf("%d", &eleccion);
        
        switch (eleccion)
        {
        case 1:
            /*funcion para agregar usuario*/
            break;
        case 2:
            do {
                printf("1. Agregar un horario\n");
                printf("2. Modificar un horario\n");
                printf("3. Eliminar un horario\n");
                printf("4. Consultar horarios\n");
                printf("5. Salir\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
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
                        printf("bye bye\n");
                        break;
                    default:
                        printf("Opcion no válida.\n");
                }
            } while (opcion != 5);
            break;
        default:
            break;
        }
    } while (eleccion!=3);
    
}

/*
void insertAtEndDL(DList *Dli, int newElement){
    NodeDL *new=(NodeDL*)malloc(sizeof(NodeDL));
    new->next=NULL;
    new->e=newElement;
    if (is_empty(*Dli)){
        Dli->start=new;
        new->prev=NULL;
    }
    else{
        NodeDL *aux;
        aux=Dli->start;
        while (aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=new;
        new->prev=aux;
    }
}

void insertAfterNodeDL(DList *DLi, int newElement, NodeDL *a){
    if (a->next==NULL){
        insertAtEndDL(DLi, newElement);
    }
    else{
        NodeDL *new=(NodeDL*)malloc(sizeof(NodeDL));
        new->prev=a->prev;
        new->next=a->next;
        a->next->prev=new;
        a->next=new;
        new->e=newElement;
    }
*/











//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// FUNCIONES PROPUESTAS POR ALEXIS
/*
void modificarHorario(ListaDoble *DLi, char nombreClase[50], char nuevoNombre[50], char nuevaHoraInicio[10], char nuevaHoraFin[10], char nuevoGrupo[5], char nuevoProfesor[50]) {
    NodeDL *current = DLi->start;

    while (current != NULL) {
        if (strcmp(current->e.nombreClase, nombreClase) == 0) {
            strcpy(current->e.nombreClase, nuevoNombre);
            strcpy(current->e.horaInicio, nuevaHoraInicio);
            strcpy(current->e.horaFin, nuevaHoraFin);
            strcpy(current->e.grupo, nuevoGrupo);
            strcpy(current->e.profesor, nuevoProfesor);

            printf("Horario modificado.\n");
            return;
        }

        current = current->next;
    }

    printf("No se encontro el horario con el nombre de clase\n");
}

void eliminarHorario(ListaDoble *DLi, char nombreClase[50]) {
    NodeDL *current = DLi->start;

    while (current != NULL) {
        if (strcmp(current->e.nombreClase, nombreClase) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                DLi->start = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Horario eliminado\n");
            return;
        }

        current = current->next;
    }

    printf("No se encontro el horario con el nombre de clase\n");
}
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
*/