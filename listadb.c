#include "d_listadb.h"
#include "d_listadb.c"
#include <stdio.h>
#include <string.h>

int main(){
    
    DList _2CV1_, _2CV2_, _2CV3_, _2CV4_;
    create(&_2CV1_);
    create(&_2CV2_);
    create(&_2CV3_);
    create(&_2CV4_);

    UdList usuarios;
    createU(&usuarios);
    
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[10];
    char profesor[50];

    char nombreUsuario[15];
    char contrasena[50];
    char nombreCompleto[100];
    char rolUsuario[10];
    int opcion;

    printf("ingrese el nuevo usuario: ");
    fgets(nombreUsuario, sizeof(nombreUsuario), stdin);
    nombreUsuario[strcspn(nombreUsuario, "\n")] = '\0';

    printf("Ingrese la contrasena: ");
    fgets(contrasena, sizeof(contrasena), stdin);
    contrasena[strcspn(contrasena, "\n")] = '\0';

    printf("ingrese el nombre completo: ");
    fgets(nombreCompleto, sizeof(nombreCompleto), stdin);
    nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0';

    printf("Elija el tipo de usuario: \n");
    printf("1. Administrador\n");
    printf("2. Alumno\n");
    scanf("%d", &opcion);

    if (opcion == 1){
        strcpy(rolUsuario, "admin");
    }
    else{
        strcpy(rolUsuario, "alumno");
    }
    
    insertarUsuarios(&usuarios, nombreUsuario, contrasena, nombreCompleto, rolUsuario);
    imprimirUsuarios(&usuarios);


    /*printf("Ingrese el nombre de la clase: ");
    fgets(nombreClase, sizeof(nombreClase), stdin);
    nombreClase[strcspn(nombreClase, "\n")] = '\0';

    printf("Ingrese la hora de inicio: ");
    fgets(horaInicio, sizeof(horaInicio), stdin);
    horaInicio[strcspn(horaInicio, "\n")] = '\0';

    printf("Ingrese la hora fin: ");
    fgets(horaFin, sizeof(horaFin), stdin);
    horaFin[strcspn(horaFin, "\n")] = '\0';

    printf("Ingrese el nomnbre del grupo: ");
    fgets(grupo, sizeof(grupo), stdin);
    grupo[strcspn(grupo, "\n")] = '\0';

    printf("Ingrese el nombre del profesor: ");
    fgets(profesor, sizeof(profesor), stdin);
    profesor[strcspn(profesor, "\n")] = '\0';
    
    insertarHorario(&_2CV1_, nombreClase, horaInicio, horaFin, grupo, profesor);
    imprimirHorario(&_2CV1_);*/



    
    return 0;
}