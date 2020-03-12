#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define V 5
#define true 1
#define false 0

typedef int bool;

typedef struct aux{
    int v;
    struct aux* prox;
} NO;

typedef struct {
    NO* inicio;
    int flag;
} VERTICE;

//////////////////////////////////////////////////
void inicializar(VERTICE* g){
    int i;
    for(i = 0; i < V; i++){
        g[i].inicio = NULL;
    }
}

void printar(VERTICE* g){
    NO* p;
    int i;
    for(i = 0; i < V; i++){
        p = g[i].inicio;
        printf("vertice %d \n", g[i].inicio->v);
        while (p != NULL){
            printf("%d \n", p->v);
            p = p->prox;
        }
    }
}
//////////////////////////////////////////////////


bool arestaExiste(VERTICE* g, int v1, int v2){
    NO* p = g[v1].inicio;
    while(p != NULL) {
        if(p->v == v2)
            return true;
        p = p->prox;
    }
    return false;
}

bool criarAresta(VERTICE* g, int v1, int v2){
    if(arestaExiste(g, v1, v2))
        return false;
    NO* p = (NO*) malloc(sizeof(NO));
    p->v = v2;
    p->prox = g[v1].inicio;
    g[v1].inicio = p;
    return true;
}

NO* buscarAresta(VERTICE* g, int v1, int v2, NO* ant){
    ant = NULL;
    NO* p = g[v1].inicio;
    while(p != NULL){
        if(p->v == v2)
            return p;
        ant = p;
        p = p->prox;
    }
    return NULL;
}

bool excluirAresta(VERTICE* g, int v1, int v2){
    NO* ant = NULL;
    NO* p = buscarAresta(g, v1, v2, ant);
    if(p == NULL)
        return false;
    if(ant != NULL)
        ant->prox = p->prox;
    else
        g[v1].inicio = p->prox;
    free(p);
    return true;
}
//////////////////////////////////////////////////


int grauEntrada(VERTICE* g, int x){

}

int grauSaida(VERTICE* g, int x){
    int cont = 0;
    NO* p = g[x].inicio;
    while(p != NULL){
        cont++;
        p = p->prox;
    }
    return cont;
}
//////////////////////////////////////////////////


bool listasIguais(NO* p1, NO* p2){
    while(p1 != NULL && p2 != NULL){
        if (p1->v != p2->v)
            return false;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    if (p1 == NULL && p2 == NULL)
        return true;
    return false;
}

bool iguais(VERTICE* g1, VERTICE* g2){
    int i;
    for(i = 0; i < V; i++){
        NO* p1 = g1[i].inicio;
        NO* p2 = g1[2].inicio;
        if(listasIguais(p1, p2) == false)
            return false;
    }
    return true;
}
//////////////////////////////////////////////////


int main()
{
    VERTICE* g = (VERTICE *) malloc(V * sizeof(VERTICE));
    inicializar(g);
    criarAresta(g, 0, 10);
    criarAresta(g, 0, 11);
    criarAresta(g, 0, 9);
    criarAresta(g, 0, 0);
    printar(g);
    arestaExiste(g, 0, 8);

    return 0;
}
