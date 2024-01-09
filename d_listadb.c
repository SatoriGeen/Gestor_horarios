#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool existeHorario(DListHorarioArmado* DLiArmado, const char* horaInicio, const char* horaFin);

void createHorarioArmado(DListHorarioArmado* DLiArmado) {
    DLiArmado->startArmado = NULL;
}

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

void insertarHorario(DList *DLi, char nombreClase[50], char horaInicio[10], char horaFin[10], char grupo[10], char profesor[50]) {
    
    // Verificar si ya existe un horario con la misma hora de inicio y fin en el grupo y la misma materia
    NodeDL *aux = DLi->start;
    while (aux != NULL) {
        if (strcmp(aux->grupo, grupo) == 0) {
            if ((strcmp(horaInicio, aux->horaInicio) >= 0 && strcmp(horaInicio, aux->horaFin) < 0) ||
                (strcmp(horaFin, aux->horaInicio) > 0 && strcmp(horaFin, aux->horaFin) <= 0) ||
                (strcmp(horaInicio, aux->horaInicio) <= 0 && strcmp(horaFin, aux->horaFin) >= 0)) {
                
                // Verifica traslape mat
                
                if (strcmp(nombreClase, aux->nombreClase) == 0) {
                    printf("No se puede agregar la materia al grupo, ya existe o coincide con algun horario.\n");
                    system("pause");
                    return;
                }
            }
        }
        aux = aux->next;
    }

    // procede
    NodeDL *new = (NodeDL *)malloc(sizeof(NodeDL));

    new->next = DLi->start;
    
    if (!is_empty(*DLi)){
        DLi->start->prev = new;
    }

    DLi->start = new;

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

void imprimirUsuarios(UdList *UDLi) {
    UsuarioDL *aux = UDLi->start;

    if (is_emptyU(*UDLi)) {
        printf("No hay usuarios\n");
    } else {

        printf("\n");
        printf("|----------------------|------------------------------------------|----------------------|\n");
        printf("| %-20s | %-40s | %-20s |\n", "Usuario", "Nombre completo", "Rol del usuario");
        printf("|----------------------|------------------------------------------|----------------------|\n");

        while (aux != NULL) {
            printf("| %-20s | %-40s | %-20s |\n",
                   aux->nombreUsuario, aux->nombreCompleto, aux->rolUsuario);
            aux = aux->next;
        }

        printf("|----------------------|------------------------------------------|----------------------|\n");
        printf("\n");
    }

    printf("Presiona Enter para continuar...");
    system("pause");
}

void imprimirHorario(DList *Dli) {
    NodeDL *aux = Dli->start;

    if (is_empty(*Dli)) {
        printf("Grupo vacio\n");
    } else {
        printf("\n");        
        printf("|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
        printf("| %-40s | %-11s | %-11s | %-8s | %-40s |\n", "Clase", "Hora inicio", "Hora fin", "Grupo", "Profesor");
        printf("|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");

        while (aux != NULL) {
            printf("| %-40s | %-11s | %-11s | %-8s | %-40s |\n", aux->nombreClase, aux->horaInicio, aux->horaFin, aux->grupo, aux->profesor);
            aux = aux->next;
        }

        printf("|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
        printf("\n");
    }
    
    printf("Presiona Enter para continuar...");
    getchar();
}

void manejarInsercionEnHorario(DList *lista, int opcion) {
    char nombreClase[50], horaInicio[10], horaFin[10], grupo[10],profesor[50];
            system("cls");
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
        printf("\n");
        insertarHorario(lista, nombreClase, horaInicio, horaFin, grupo, profesor);
        printf("Materia agregada exitosamente!\n");
        imprimirHorario(lista);
        
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
    printf("\nSeleccione un grupo: \n");
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
    
    getchar();

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

void armarHorario(DList* DLi, DListHorarioArmado* DLiArmado) {
    NodeDL* aux = DLi->start;
    int contador = 0;
    int seleccion;

    printf("Selecciona las materias que deseas agregar al horario (ingresa el numero correspondiente):\n");

    printf("\n");        
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
    printf("|%-2s | %-40s | %-11s | %-11s | %-8s | %-40s |\n", "No", "Clase", "Hora inicio", "Hora fin", "Grupo", "Profesor");
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");


    while (aux != NULL && contador < 4) {
        printf("|%d. ", contador + 1);
        printf("| %-40s | %-11s | %-11s | %-8s | %-40s |\n", aux->nombreClase, aux->horaInicio, aux->horaFin, aux->grupo, aux->profesor);

        aux = aux->next;
        contador++;
    }
    
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
    printf("\n");



    printf("Ingresa 0 para cancelar\n");

    while (contador > 0) {
        printf("Selecciona una materia (1-%d) o ingresa 0 para cancelar: ", contador);
        scanf("%d", &seleccion);

        if (seleccion == 0) {
            printf("Saliendo al menu principal...\n");
            break;
        }

        if (seleccion < 1) {
            printf("Seleccion no valida.\n");
            continue;
        }

        // se obtiene el nodo correspondiente
        aux = DLi->start;
        for (int i = 1; i < seleccion; i++) {
            aux = aux->next;
        }

        if (!existeHorario(DLiArmado, aux->horaInicio, aux->horaFin)) {

            NodeHorarioArmado* newArmado = (NodeHorarioArmado*)malloc(sizeof(NodeHorarioArmado));

            strncpy(newArmado->nombreClase, aux->nombreClase, sizeof(newArmado->nombreClase) - 1);
            strncpy(newArmado->horaInicio, aux->horaInicio, sizeof(newArmado->horaInicio) - 1);
            strncpy(newArmado->horaFin, aux->horaFin, sizeof(newArmado->horaFin) - 1);
            strncpy(newArmado->grupo, aux->grupo, sizeof(newArmado->grupo) - 1);
            strncpy(newArmado->profesor, aux->profesor, sizeof(newArmado->profesor) - 1);

            // uso de metodo para ingresar al inicio
            newArmado->next = DLiArmado->startArmado;
            newArmado->prev = NULL;

            if (DLiArmado->startArmado != NULL) {
                DLiArmado->startArmado->prev = newArmado;
            }

            DLiArmado->startArmado = newArmado;

            printf("La materia se agrego extosamente!.\n");
            contador--;
        } else {
            printf("No se puede ingresar, ya existe un horario con las mismas caracteristicas. verifica tu eleccion por favor.\n");
        }
    }
}

void printListArmado(DListHorarioArmado* DLiArmado) {
    NodeHorarioArmado* aux = DLiArmado->startArmado;
    int contador = 0;

    printf("Horario Armado:\n");
    printf("\n");        
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
    printf("|%-2s | %-40s | %-11s | %-11s | %-8s | %-40s |\n", "No", "Clase", "Hora inicio", "Hora fin", "Grupo", "Profesor");
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");

    while (aux != NULL) {
        contador++;
        printf("|%d. ", contador);
        printf("| %-40s | %-11s | %-11s | %-8s | %-40s |\n", aux->nombreClase, aux->horaInicio, aux->horaFin, aux->grupo, aux->profesor);
        aux = aux->next;
    }

    // Línea separadora al final
    printf("|---|------------------------------------------|-------------|-------------|----------|------------------------------------------|\n");
    printf("\n");

    printf("\nPresiona Enter para continuar...");
    system("pause");
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
    printf("\nSeleccione el numero del horario que desea eliminar (ingrese 0 para cancelar): \n");
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