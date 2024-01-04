#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void create(DList *DLi){
    DLi->start=NULL;
}

void createU(UdList *UDli){
    UDli->start=NULL;
}

int is_empty(DList DLi){
    if (DLi.start==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int is_emptyU(UdList UDLi){
    if (UDLi.start==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertarUsuarios(UdList *UDLi, char nombreUsuario[15], char contrasena[50], char nombreCompleto[100], char rolUsuario[10]){
    UsuarioDL *new=(UsuarioDL *)malloc(sizeof(UsuarioDL));
    
    new->next=UDLi->start;
    if (!is_emptyU(*UDLi)){
        UDLi->start->prev=new;
    }

    UDLi->start=new;
    //asignacion de elementos a la cadena    
    strncpy(new->nombreUsuario, nombreUsuario, sizeof(new->nombreUsuario) - 1);
    strncpy(new->contrasena, contrasena, sizeof(new->contrasena) - 1);
    strncpy(new->nombreCompleto, nombreCompleto, sizeof(new->nombreCompleto) - 1);
    strncpy(new->rolUsuario, rolUsuario, sizeof(new->rolUsuario) - 1);
    //asignacion de caracter nulo al final de cada cadena para evitar problemas en el bufer
    new->nombreUsuario[sizeof(new->nombreUsuario) - 1] = '\0';
    new->contrasena[sizeof(new->contrasena) - 1] = '\0';
    new->nombreCompleto[sizeof(new->nombreCompleto) - 1] = '\0';
    new->rolUsuario[sizeof(new->rolUsuario) - 1] = '\0';
    
    new->prev=NULL;

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

void imprimirUsuarios(UdList *UDLi){
    UsuarioDL *aux = UDLi->start;
    if (is_emptyU(*UDLi)){
        printf("No hay usuarios");
    }
    else{
        while (aux!=NULL)
        {
            printf("\n");
            printf("Usuario: %s\n", aux->nombreUsuario);
            printf("Contrasena: %s\n", aux->contrasena);
            printf("Nombre completo: %s\n", aux->nombreCompleto);
            printf("Rol del usuario: %s\n", aux->rolUsuario);
            printf("\n");
            aux=aux->next;
        }
        
    }

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
    printf("elige un grupo: ");
}

void menuAdmin(){
    int eleccion;
    int opcion;
    do
    {
        printf("\n---BIENVENIDO---\n");
        printf("1. Agregar usuario nuevo\n");
        printf("2. Insertar horario");
        printf("3. Editar horarios\n");
        printf("4. Salir\n");
        printf("Por favor digite el numero de accion deseada:");
        scanf("%d", &eleccion);
        
        switch (eleccion)
        {
        case 1:


            break;
        case 2:
            mostrarGrupos();
            
            break;
        default:
            break;
        }
    } while (eleccion!=3);
    
}

void manejarInsercionEnHorario(DList *lista, int opcion) {
    char nombreClase[50], horaInicio[10], horaFin[10], grupo[10],profesor[50];

            printf("Ingrese el nombre de la clase: ");
            fgets(nombreClase, sizeof(nombreClase), stdin);
            nombreClase[strcspn(nombreClase, "\n")] = '\0';

            printf("Ingrese la hora de inicio: ");
            fgets(horaInicio, sizeof(horaInicio), stdin);
            horaInicio[strcspn(horaInicio, "\n")] = '\0';

            printf("Ingrese la hora fin: ");
            fgets(horaFin, sizeof(horaFin), stdin);
            horaFin[strcspn(horaFin, "\n")] = '\0';

            switch (opcion){
                case 1:
                    strcpy(grupo,"2CV1");
                    break;
                case 2:
                    strcpy(grupo,"2CV2");
                    break;
                case 3:
                    strcpy(grupo,"2CV3");
                    break;
                case 4:
                    strcpy(grupo,"2CV4");
                    break;    
                default:
                    printf("no se pudo ingresar el grupo");
                    break;
            }

        printf("Ingrese el nombre del profesor: ");
        fgets(profesor, sizeof(profesor), stdin);
        profesor[strcspn(profesor, "\n")] = '\0';

        insertarHorario(lista, nombreClase, horaInicio, horaFin, grupo, profesor);
}

void manejarEdicionEnGrupo(DList *lista, int opi){
        
        char nombreClaseEditar[50], nuevoProfesor[50], nuevoNombreClase[50], nuevaHoraInicio[10], nuevaHoraFin[10], nuevoGrupo[10];
        
        printf("\nIngrese el nombre de la clase que desea editar: ");
        
        fgets(nombreClaseEditar, sizeof(nombreClaseEditar), stdin);
        nombreClaseEditar[strcspn(nombreClaseEditar, "\n")] = '\0';

        printf("Ingrese nuevos datos:\n");
        printf("Nuevo nombre de la clase: ");
        fgets(nuevoNombreClase, sizeof(nuevoNombreClase), stdin);
        nuevoNombreClase[strcspn(nuevoNombreClase, "\n")] = '\0';

        printf("Nueva hora de inicio: ");
        fgets(nuevaHoraInicio, sizeof(nuevaHoraInicio), stdin);
        nuevaHoraInicio[strcspn(nuevaHoraInicio, "\n")] = '\0';

        printf("Nueva hora de fin: ");
        fgets(nuevaHoraFin, sizeof(nuevaHoraFin), stdin);
        nuevaHoraFin[strcspn(nuevaHoraFin, "\n")] = '\0';

        printf("Nuevo profesor: ");
        fgets(nuevoProfesor, sizeof(nuevoProfesor), stdin);
        nuevoProfesor[strcspn(nuevoProfesor, "\n")] = '\0';

        editarHorario(lista, nombreClaseEditar, nuevoNombreClase, nuevaHoraInicio, nuevaHoraFin, nuevoGrupo, nuevoProfesor);
        printf("\nCambios completados:\n");
        imprimirHorario(lista);
}

void editarHorario(DList *DLi, char nombreClaseEditar[50], char nuevoNombreClase[50], char nuevaHoraInicio[10], char nuevaHoraFin[10], char nuevoGrupo[10], char nuevoProfesor[50]) {
    NodeDL *aux = DLi->start;

    while (aux != NULL) {
        // Buscar el nodo con el nombre de clase a editar
        if (strcmp(aux->nombreClase, nombreClaseEditar) == 0) {
            // Realizar las ediciones necesarias
            strncpy(aux->nombreClase, nuevoNombreClase, sizeof(aux->nombreClase) - 1);
            strncpy(aux->horaInicio, nuevaHoraInicio, sizeof(aux->horaInicio) - 1);
            strncpy(aux->horaFin, nuevaHoraFin, sizeof(aux->horaFin) - 1);
            strncpy(aux->profesor, nuevoProfesor, sizeof(aux->profesor) - 1);

            // Asignar el carácter nulo al final de cada cadena
            aux->nombreClase[sizeof(aux->nombreClase) - 1] = '\0';
            aux->horaInicio[sizeof(aux->horaInicio) - 1] = '\0';
            aux->horaFin[sizeof(aux->horaFin) - 1] = '\0';
            aux->profesor[sizeof(aux->profesor) - 1] = '\0';

            // Salir del bucle después de editar el nodo
            break;
        }

        aux = aux->next;
    }
}

void imprimirCLases(DList *Dli){
    int contador = 0;
    NodeDL *aux = Dli->start;
    if (is_empty(*Dli)){

        printf("Grupo vacio");

    }
    else{
        while (aux!=NULL)
        {
            contador++;
            printf("Clase %d:  %s\n", contador, aux->nombreClase);
            printf("\n");
            aux=aux->next;

        }   

    } 

}

void manejarReduccionEnGrupo(DList *lista, int opio){
        
        char nombreClaseEliminar[50];
        
        printf("\nIngrese el nombre de la clase que desea eliminar: ");
        
        fgets(nombreClaseEliminar, sizeof(nombreClaseEliminar), stdin);
        nombreClaseEliminar[strcspn(nombreClaseEliminar, "\n")] = '\0';

        eliminarHorario(lista, nombreClaseEliminar);
        printf("\nCambios completados:\n");
        imprimirHorario(lista);
}


void eliminarHorario(DList *DLi, char nombreClaseEliminar[50]) {
    NodeDL *aux = DLi->start;

    while (aux != NULL) {
        // Buscar el nodo con el nombre de clase a eliminar
        if (strcmp(aux->nombreClase, nombreClaseEliminar) == 0) {
            // Verificar si el nodo es el primero en la lista
            if (aux == DLi->start) {
                DLi->start = aux->next;
                if (DLi->start != NULL) {
                    DLi->start->prev = NULL;
                }
            } else {
                // Conectar el nodo anterior al siguiente y viceversa
                aux->prev->next = aux->next;
                if (aux->next != NULL) {
                    aux->next->prev = aux->prev;
                }
            }

            // Liberar memoria del nodo eliminado
            free(aux);

            // Salir del bucle después de eliminar el nodo
            break;
        }

        aux = aux->next;
    }
}














/*
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
            } while (opcion != 5);*/

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