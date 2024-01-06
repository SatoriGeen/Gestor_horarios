#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

DListHorarioArmado horarioArmadoAlumno; 

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

    strncpy(new->nombreClase, nombreClase, sizeof(new->nombreClase) - 1);
    strncpy(new->horaInicio, horaInicio, sizeof(new->horaInicio) - 1);
    strncpy(new->horaFin, horaFin, sizeof(new->horaFin) - 1);
    strncpy(new->grupo, grupo, sizeof(new->grupo) - 1);
    strncpy(new->profesor, profesor, sizeof(new->profesor) - 1);

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

        if (strcmp(aux->nombreClase, nombreClaseEditar) == 0) {
            
            strncpy(aux->nombreClase, nuevoNombreClase, sizeof(aux->nombreClase) - 1);
            strncpy(aux->horaInicio, nuevaHoraInicio, sizeof(aux->horaInicio) - 1);
            strncpy(aux->horaFin, nuevaHoraFin, sizeof(aux->horaFin) - 1);
            strncpy(aux->profesor, nuevoProfesor, sizeof(aux->profesor) - 1);

            aux->nombreClase[sizeof(aux->nombreClase) - 1] = '\0';
            aux->horaInicio[sizeof(aux->horaInicio) - 1] = '\0';
            aux->horaFin[sizeof(aux->horaFin) - 1] = '\0';
            aux->profesor[sizeof(aux->profesor) - 1] = '\0';

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

        if (strcmp(aux->nombreClase, nombreClaseEliminar) == 0) {
            
            if (aux == DLi->start) {
                DLi->start = aux->next;
                if (DLi->start != NULL) {
                    DLi->start->prev = NULL;
                }
            } else {

                aux->prev->next = aux->next;
                if (aux->next != NULL) {
                    aux->next->prev = aux->prev;
                }
            }

            free(aux);

            break;
        }

        aux = aux->next;
    }
}

void menuDeListas(){
    printf("\ngrupo a editar: \n");
    printf("1. 2CV1\n");
    printf("2. 2CV2\n");
    printf("3. 2CV3\n");
    printf("4. 2CV4\n");
    printf("0. Salir\n");
}

void manejarInsercionDeUsuarios(UdList* UDLi) {
    char nombreUsuario[15], contrasena[50], nombreCompleto[100], rolUsuario[10];
    int rol;

    printf("\nIngrese los datos del nuevo usuario:\n");
    getchar();

    printf("Nombre de usuario: ");
    fgets(nombreUsuario, sizeof(nombreUsuario), stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = '\0';

    printf("Contrasena: ");
    fgets(contrasena, sizeof(contrasena), stdin);
    contrasena[strcspn(contrasena, "\n")] = '\0';

    printf("Nombre completo: ");
    fgets(nombreCompleto, sizeof(nombreCompleto), stdin);
    nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0';

    printf("Rol de usuario:\n");
    printf("Digite el numero correspondiente del rol:\n");
    printf("1. Administrador\n2. Alumno\n");
    
    if (scanf("%d", &rol) != 1) {
        printf("Error al leer el rol");
        return;
    }
    
    getchar(); // Limpiar el búfer de nueva línea

    switch (rol) {
        case 1:
            strcpy(rolUsuario, "Admin");
            break;
        case 2:
            strcpy(rolUsuario, "Alumno");
            break;
        default:
            printf("Opcion no valida");
            return;
    }

    insertarUsuarios(UDLi, nombreUsuario, contrasena, nombreCompleto, rolUsuario);

    printf("\nUsuario insertado correctamente\n");
}

int iniciarSesion(UdList *UDLi, char nombreUsuario[], char contrasena[]) {
    UsuarioDL *aux = UDLi->start;

    while (aux != NULL) {
        if (strcmp(aux->nombreUsuario, nombreUsuario) == 0 && strcmp(aux->contrasena, contrasena) == 0) {
            printf("\nInicio de sesion exitoso.\n");
            return 1;
        }
        aux = aux->next;
    }

    printf("\nUsuario o contrasena incorrectos.\n");
    return 0; 
}

void menuAlumno(DList *lista) {
    int opcion;
    
    do {
        printf("\n--- Menú del Alumno ---\n");
        printf("1. Armar horario de clases\n");
        printf("2. Imprimir horario\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarClaseAlumno(lista);
                break;
            case 2:
                imprimirHorarioArmado(&horarioArmadoAlumno);
                break;
            case 3:
                printf("Hasta la próxima :D\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 3);
}

void agregarClaseAlumno(DList *lista) {
    mostrarGrupos();
    int opcion;
    printf("Seleccione el grupo en el que desea agregar clases: ");
    scanf("%d", &opcion);

    DList *grupoSeleccionado = &lista[opcion - 1];  

    printf("Ingrese el número de clases que desea agregar: ");
    int numClases;
    scanf("%d", &numClases);

    for (int i = 0; i < numClases; i++) {
        printf("Ingrese el nombre de la clase %d: ", i + 1);
        char nombreClase[50];
        scanf("%s", nombreClase);

    
        char horaInicio[] = "15:00";
        char horaFin[] = "16:30";
        char profesor[] = "Profesor Ejemplo";

     
        if (VerificarTraslape(grupoSeleccionado, horaInicio, horaFin, nombreClase)) {
            printf("Error: Clase con traslape. No se pudo agregar la clase.\n");
            i--;  
        } else {
            insertarHorario(grupoSeleccionado, nombreClase, horaInicio, horaFin, grupoSeleccionado->grupo, profesor);
            printf("Clase agregada exitosamente.\n");
        }
    }

    printf("Horario final:\n");
    imprimirHorario(grupoSeleccionado);
}

void imprimirHorarioArmado(DListHorarioArmado* list) {
    NodeHorarioArmado* current = list->startArmado;

    printf("\nHorario Armado del Alumno:\n");

    while (current != NULL) {
        printf("Nombre de la Clase: %s\n", current->nombreClase);
        printf("Hora de Inicio: %s\n", current->horaInicio);
        printf("Hora de Fin: %s\n", current->horaFin);
        printf("Grupo: %s\n", current->grupo);
        printf("Profesor: %s\n", current->profesor);
        printf("\n");

        current = current->next;
    }
}

int VerificarTraslape(DList *DLi, char horaInicio[10], char horaFin[10], char grupo[10]) {
    NodeDL *current = DLi->start;

    while (current != NULL) {
        if (strcmp(current->grupo, grupo) == 0) {
            if ((strcmp(horaInicio, current->horaInicio) >= 0 && strcmp(horaInicio, current->horaFin) <= 0) ||
                (strcmp(horaFin, current->horaInicio) >= 0 && strcmp(horaFin, current->horaFin) <= 0)) {
                return 1; 
            }
        }

        current = current->next;
    }

    return 0;
}
void insertarHorarioArmado(DListHorarioArmado* list, char nombreClase[50], char horaInicio[10], char horaFin[10], char grupo[10], char profesor[50]) {
    NodeHorarioArmado *new = (NodeHorarioArmado*)malloc(sizeof(NodeHorarioArmado));

    new->next = list->startArmado;

    if (list->startArmado != NULL) {
        list->startArmado->prev = new;
    }

    list->startArmado = new;

    strncpy(new->nombreClase, nombreClase, sizeof(new->nombreClase) - 1);
    strncpy(new->horaInicio, horaInicio, sizeof(new->horaInicio) - 1);
    strncpy(new->horaFin, horaFin, sizeof(new->horaFin) - 1);
    strncpy(new->grupo, grupo, sizeof(new->grupo) - 1);
    strncpy(new->profesor, profesor, sizeof(new->profesor) - 1);

    new->nombreClase[sizeof(new->nombreClase) - 1] = '\0';
    new->horaInicio[sizeof(new->horaInicio) - 1] = '\0';
    new->horaFin[sizeof(new->horaFin) - 1] = '\0';
    new->grupo[sizeof(new->grupo) - 1] = '\0';
    new->profesor[sizeof(new->profesor) - 1] = '\0';

    new->prev = NULL;
}
