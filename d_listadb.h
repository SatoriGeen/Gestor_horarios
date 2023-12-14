#ifndef D_LISTADB_H
#define D_LISTADB_H


typedef struct NodeDL{
    int e;
    struct NodeDL *next;
    struct NodeDL *prev;
}NodeDL;

typedef struct DList{
    NodeDL *start;
}DList;

typedef struct RolesUsuarios{
    char Administrador;
    char Alumno;
}rol;



void create(DList *DLi);
int is_empty(DList DLi);
void insertAtStartDL(DList *DLi, int newElement);
void insertAtEndDL(DList *Dli, int newElement);
void insertAfterNodeDL(DList *DLi, int newElement, NodeDL *a);

#endif