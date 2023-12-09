#include "d_listadb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void create(DList *DLi){
    DLi->start=NULL;
}

int is_empty(DList DLi){
    if (DLi.start==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertAtStartDL(DList *DLi, int newElement){
    NodeDL *new=(NodeDL *)malloc(sizeof(NodeDL));
    new->next=DLi->start;
    if (!is_empty(*DLi)){
        DLi->start->prev=new;
    }
    DLi->start=new;
    new->e=newElement;
    new->prev=NULL;
}

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
}