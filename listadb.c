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
    
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[10];
    char profesor[50];

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

    menuAdmin();

    
    return 0;
}