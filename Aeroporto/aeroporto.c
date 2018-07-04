#include "aeroporto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para criar uma nova arvore
ARV nova_arv()
{
    return NULL;
}

int EMPTY (ARV a)
{
    return (a == NULL);
}

//  Função para inserir um novo elemento 'b' na arvore 'a'
ARV insere (ARV a, AEROPORTO b)
{
    ARV nova;
    if (EMPTY(a))
    {
        nova = (ARV) malloc (sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->e = b;
        return nova;
    }
    else
    {
        if ( strcmp(a->e.codigo,b.codigo) < 0 )
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b);  /* Repeticoes sao inseridas na esquerda! */
        return a;
    }
}

// Função para procurar um elemento numa arvore
ARV procura (ARV a , char *b)
{
    if (EMPTY(a))
        return NULL;
    else if ( strcmp(a->e.codigo,b) == 0 )
        return a;
    else if ( strcmp(a->e.codigo,b) < 0 )
        return procura (a->dir, b);
    else
        return procura (a->esq, b);
}

//Função para percorrer a arvore binária com critério pre-ordem
void preordem (ARV a)
{
    if (! EMPTY(a) )
    {
        printf("%s ",a->e.codigo);
        preordem(a->esq);
        preordem(a->dir);
    }
}

//Função para percorrer a arvore binária com critério em-ordem
void emordem (ARV a)
{
    if (! EMPTY(a) )
    {
        emordem(a->esq);
        fflush(stdin);
        printf("%s ",a->e.codigo);
        emordem(a->dir);
    }
}

//Função para percorrer a arvore binária com critério pós-ordem
void posordem (ARV a)
{
    if (! EMPTY(a) )
    {
        posordem(a->esq);
        posordem(a->dir);
        printf("%s ",a->e.codigo);
    }
}

AEROPORTO LimparAeroporto(AEROPORTO e)
{
    int j;
    for(j=0; j<50; j++)
        e.continente[j]=0;
    for(j=0; j<25; j++)
        e.cidade[j]=0;
    for(j=0; j<4; j++)
        e.codigo[j]=0;
    for(j=0; j<60; j++)
        e.nome[j]=0;
    return e;
}
