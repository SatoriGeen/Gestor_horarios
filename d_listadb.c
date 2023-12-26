#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//funciones que faltan por adaptar
/*
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

void insertAtStartDL(DList *DLi, int newElement){
    NodeDL *new=(NodeDL *)malloc(sizeof(NodeDL));
    new->next=DLi->start;
    if (!is_empty(*DLi)){
        DLi->start->prev=new;
    }
    DLi->start=new;
    new->e=newElement;
    new->prev=NULL;
}

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