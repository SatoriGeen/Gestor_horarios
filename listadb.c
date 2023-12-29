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
    DList *listas[] = {&_2CV1_, &_2CV2_, &_2CV3_, &_2CV4_};

    char nombreClase[50], horaInicio[10], horaFin[10], grupo[10], profesor[50];
    int opcion;
    do{
        printf("\nSeleccione la lista:\n");
        printf("1. 2CV1\n");
        printf("2. 2CV2\n");
        printf("3. 2CV3\n");
        printf("4. 2CV4\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); 
        
        if (opcion >= 1 && opcion <= sizeof(listas) / sizeof(listas[0])) {
            
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

            insertarHorario(listas[opcion - 1], nombreClase, horaInicio, horaFin, grupo, profesor);
            printf("\nGrupo actualizado\n");
            printf("\n lista 1:");
            imprimirHorario(&_2CV1_);
            printf("\nlista 2:");
            imprimirHorario(&_2CV2_);
            printf("\nlista 3:");
            imprimirHorario(&_2CV3_);
            printf("\nlista 4:");
            imprimirHorario(&_2CV4_);
        } 
        else if(opcion != 0) {
            printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    }while (opcion != 0);





    // Validar la opción

         
    /*
    UdList usuarios;
    createU(&usuarios);
    char nombreUsuario[15],contrasena[50], nombreCompleto[100], rolUsuario[10];

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
    imprimirUsuarios(&usuarios);*/





    
    return 0;
}

