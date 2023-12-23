#ifndef D_LISTADB_H
#define D_LISTADB_H
/*
// Nodo practico
typedef struct NodeDL{
    int e;
    struct NodeDL *next;
    struct NodeDL *prev;
} NodeDL;

typedef struct DList{
    NodeDL *start;
} DList;
*/

typedef enum {
    ADMINISTRADOR,
    ALUMNO
} Rol;

typedef struct {
    char nombreusuario[50];
    char contrasena[50];
    char nombreCompleto[100];
    Rol tipoUsuario;
} Usuario;


typedef struct {
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[5];
    char profesor[50];
} HorarioClase;

typedef struct 
{
    char nombreGrupo[10];
    Materias MateriaAsginada;
} Grupo;

typedef enum 
{
    /*
    aqui van las materias de 2do semestre
    */
    
} Materias;



void create(DList *DLi);
int is_empty(DList DLi);
void insertAtStartDL(DList *DLi, int newElement);
void insertAtEndDL(DList *Dli, int newElement);
void insertAfterNodeDL(DList *DLi, int newElement, NodeDL *a);
void modificarHorario(ListaDoble *DLi, char nombreClase[50], char nuevoNombre[50], char nuevaHoraInicio[10], char nuevaHoraFin[10], char nuevoGrupo[5], char nuevoProfesor[50]);
void eliminarHorario(ListaDoble *DLi, char nombreClase[50]);

#endif