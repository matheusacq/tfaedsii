#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "aeroporto.h"

int main()
{
    FILE *arquivo;
    ARV a=NULL;
    AEROPORTO e;
    int i=0,j,opcao;
    char continua='s';
    char item[120];
    int f1=0,f2=0,f3=0,f4=0;
    setlocale(LC_ALL, "Portuguese");
    arquivo = fopen("ListadeAeroportos.txt","r");
    while(1)
    {
        printf("Lista de Aeroportos\n");
        printf("1-Listar todos os aeroportos\n");
        printf("2-Listar códigos dos aeroportos\n");
        printf("0-Sair\n");
        scanf("%d", &opcao);
        for(j=0; j<120; j++)item[j]=0;
        if(opcao==1)
        {

            while (continua != EOF)
            {
                continua=fgetc(arquivo);
                i=0;
                while(continua!=';'&&continua!='\n'&&continua!=EOF)
                {
                    item[i]=continua;
                    i++;
                    continua=fgetc(arquivo);
                }
                item[i]='\0';

                if (f1==0)
                {
                    strcpy(e.continente,item);
                    f1=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f2==0)
                {
                    strcpy(e.cidade,item);
                    f2=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f3==0)
                {
                    strcpy(e.codigo,item);
                    f3=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f4==0)
                {
                    strcpy(e.nome,item);
                    f4=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                if((f1==1)&&(f2==1)&&(f3==1)&&(f4==1))
                {
                    printf("Continente: %s \nCidade: %s \nCodigo: %s \nNome: %s\n\n",e.continente,e.cidade,e.codigo,e.nome);
                    a=insere(a,e);
                    f1=0;
                    f2=0;
                    f3=0;
                    f4=0;
                    e=LimparAeroporto(e);
                }
            }
        }
        else if(opcao==2)
        {
            //fclose(arquivo);
            for(j=0; j<120; j++)item[j]=0;
            while (continua != EOF)
            {
                continua=fgetc(arquivo);
                i=0;
                while(continua!=';'&&continua!='\n'&&continua!=EOF)
                {
                    item[i]=continua;
                    i++;
                    continua=fgetc(arquivo);
                }
                item[i]='\0';

                if (f1==0)
                {
                    strcpy(e.continente,item);
                    f1=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f2==0)
                {
                    strcpy(e.cidade,item);
                    f2=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f3==0)
                {
                    strcpy(e.codigo,item);
                    f3=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                else if (f4==0)
                {
                    strcpy(e.nome,item);
                    f4=1;
                    for(j=0; j<120; j++)
                        item[j]=0;
                }
                if((f1==1)&&(f2==1)&&(f3==1)&&(f4==1))
                {
                    //printf("Continente: %s \nCidade: %s \nCodigo: %s \nNome: %s\n\n",e.continente,e.cidade,e.codigo,e.nome);
                    a=insere(a,e);
                    f1=0;
                    f2=0;
                    f3=0;
                    f4=0;
                    e=LimparAeroporto(e);
                }
            }
            printf("\nCódigo de Aeroportos\nEm ordem:\n");
            emordem(a);
            printf("\nPré ordem:\n");
            preordem(a);
            printf("\nPós ordem:\n");
            posordem(a);
        }
        else if(opcao==0)
        {
            break;
        }
        else
        {
            printf("\nOpção Inválida!\n");
        }
        fflush(arquivo);
        system("PAUSE");
        system("CLS");
    }
    fclose(arquivo);
    return 0;
}
