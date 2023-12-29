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

// Inicio estructuras enum

typedef enum {
    ADMINISTRADOR,
    ALUMNO
} Rol;

typedef enum {
    ALGORITMOS_Y_ESTRUCTURA_DE_DATOS,
    ALGEBRA_LINEAL,
    CALCULO_APLICADO,
    MECANICA_Y_ELECTROMAGNETISMO,
    INGENIERIA_ETICA_Y_SOCIEDAD,
    FUNDAMENTOS_ECONOMICOS    
} Materias;

typedef enum {
    _2CV1_,
    _2CV2_,
    _2CV3_,
    _2CV4_,
    _2CV5_
} Grupos;

typedef enum {
    ESQUIVEL_CENTENO_JOSE_ARMANDO,
    MONTIEL_SANCHEZ_ANGEL_SALVADOR,
    JUAREZ_MENDEZ_ANA_BELEM,
    NAVA_LARA_JOEL,
    JUAREZ_LEON_CARLOS,
    ZARATE_CARDENAS_ALEJANDRO,
    HERNANDEZ_GARCIA_ROSA_ALBA,
    ESTRADA_ELIZALDE_SERAFIN,
    MACIAS_PEREZ_FRANCISCO_JAVIER,
    TIRADO_LULE_JUDITH_MARGARITA,
    FLORES_MERAZ_YESICA_SONIA,
    CRUZ_LAZARO_ING_APOLINAR_FRANCISCO,
    VILLEGAS_NAVARRETE_SONIA,
    CRUZ_GARCIA_DANIEL,
    LEON_HERNANDEZ_MIGUEL_ABEL,
    LEVARIO_MEDINA_SERGIO,
    GONZALEZ_ALBARRAN_GISELA,
    MOSCOSO_MALAGON_YOSAFAT,
    ORTUNO_ARAUJO_JESUS,
    GONZALEZ_GARCIA_GUSTAVO
} Profesores;

typedef enum {
    Salon1,
    Salon2,
    Salon3,
    Salon4,
    Salon5,
    Salon6,
    Salon7,
    Salon8,
    Salon9
} Salones;

// Fin estrcuturas enum

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
} DList;


/*
typedef struct {
    int idHorario;
    int idAlumno;
} HorarioAlumno;
*/


void create(DList *DLi);
void createU(UdList *UDli);
int is_empty(DList DLi);
int is_emptyU(UdList UDLi);
void insertarHorario(DList *DLi, char nombreClase[50], char horaInicio[10], char horaFin[10], char grupo[10], char profesor[50]);
void insertarUsuarios(UdList *UDLi, char nombreUsuario[15], char contrasena[50], char nombreCompleto[100], char rolUsuario[10]);
void imprimirHorario(DList *Dli);
void imprimirUsuarios(UdList *UDLi);
void imprimirListas(DList *Dli);
void mostrarGrupos();
void menuAdmin();

/*
void insertAtEndDL(DList *Dli, int newElement);
void insertAfterNodeDL(DList *DLi, int newElement, NodeDL *a);

void modificarHorario(ListaDoble *DLi, char nombreClase[50], char nuevoNombre[50], char nuevaHoraInicio[10], char nuevaHoraFin[10], char nuevoGrupo[5], char nuevoProfesor[50]);
void eliminarHorario(ListaDoble *DLi, char nombreClase[50]);
*/

#endif