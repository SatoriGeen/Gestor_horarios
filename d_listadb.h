#ifndef D_LISTADB_H
#define D_LISTADB_H

typedef struct UsuarioDL{
    char nombreUsuario[15];
    char contrasena[50];
    char nombreCompleto[100];
    char rolUsuario[10];
    struct UsuarioDL *prev;
    struct UsuarioDL *next;
} UsuarioDL;

typedef struct UdList{
    UsuarioDL *start;
} UdList;

typedef struct NodeDL{
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[10];
    char profesor[50];
    struct NodeDL* next;
    struct NodeDL* prev;
} NodeDL;

typedef struct DList{
    NodeDL *start;
    char grupo[10];
} DList;

typedef struct NodeHorarioArmado {
    char nombreClase[50];
    char horaInicio[10];
    char horaFin[10];
    char grupo[10];
    char profesor[50];

    struct NodeHorarioArmado* next;
    struct NodeHorarioArmado* prev;
} NodeHorarioArmado;

typedef struct DListHorarioArmado {
    NodeHorarioArmado* startArmado;  
} DListHorarioArmado;

extern DListHorarioArmado horarioArmadoAlumno;

void create(DList *DLi);
void createU(UdList *UDli);
int is_empty(DList DLi);
int is_emptyU(UdList UDLi);
void insertarHorario(DList *DLi, char nombreClase[50], char horaInicio[10], char horaFin[10], char grupo[10], char profesor[50]);
void insertarUsuarios(UdList *UDLi, char nombreUsuario[15], char contrasena[50], char nombreCompleto[100], char rolUsuario[10]);
void editarHorario(DList *DLi, char nombreClaseEditar[50], char nuevoNombreClase[50], char nuevaHoraInicio[10], char nuevaHoraFin[10], char nuevoGrupo[10], char nuevoProfesor[50]);
void manejarInsercionEnHorario(DList *lista, int opcion);
int iniciarSesion(UdList *UDLi, char nombreUsuario[], char contrasena[]);
void manejarEdicionEnGrupo(DList *lista, int opi);
void manejarReduccionEnGrupo(DList *lista, int opio);
void eliminarHorario(DList *DLi, char nombreClaseEliminar[50]);
void manejarInsercionDeUsuarios(UdList* UDLi);
void imprimirHorario(DList *Dli);
void imprimirUsuarios(UdList *UDLi);
void imprimirListas(DList *Dli);
void mostrarGrupos();
void imprimirCLases(DList *Dli);
void menuDeListas();
int iniciarSesion(UdList *UDLi, char nombreUsuario[], char contrasena[]);
void printListArmado(DListHorarioArmado* DLiArmado);
void armarHorario(DList* DLi, DListHorarioArmado* DLiArmado);
void createHorarioArmado(DListHorarioArmado* DLiArmado);

void eliminarHorarioRep(DListHorarioArmado* DLiArmado);
void mostrarHorariosArmados(DListHorarioArmado* DLiArmado);
#endif