#ifndef AEROPORTO_H_INCLUDED
#define AEROPORTO_H_INCLUDED

typedef struct aeroporto
{
    char continente[50];
    char cidade[40];
    char codigo[4];
    char nome[120];
} AEROPORTO;

typedef struct nodo
{
    AEROPORTO e;
    struct nodo *esq;
    struct nodo *dir;
} NO;
typedef NO *ARV;

ARV nova_arv();
int EMPTY (ARV a);
ARV insere (ARV a, AEROPORTO b);
ARV procura (ARV a , char *b);
void preordem (ARV a);
void emordem (ARV a);
void posordem (ARV a);
AEROPORTO LimparAeroporto(AEROPORTO e);

#endif // AEROPORTO_H_INCLUDED
