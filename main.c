#include "Projeto_Final_AED.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    ArvoreBB ABB;
    criar(&ABB);

    int opcao, stop = 1, RA;
    char Nome[100];
    printf("Como voce quer inserir o cadastro?:\n");
    printf("0.Finalizar o programa.\n");
    printf("1.Digitando no prompt.\n");
    printf("2.Por um arquivo'.txt'.\n");
    do{
    printf("Digite o numero da sua opcao(1 ou 2):");
    scanf("%d",&opcao);
    }
    while(opcao != 0 && opcao != 1 && opcao != 2);

    //while(stop != 0){
        switch(opcao){
            case 0:{
                stop = 0;
                break;
            }
            case 1:{
                InserirManualmente(&ABB);
                break;
            }
            case 2:{
                if(cheia(&ABB)){
                    printf("Nao foi possivel alocar memoria.\n");
                    return 1;
                }

                char arquivo[100];
                printf("\nInsira o nome do arquivo.\n");
                printf("Arquivo tem que estar no fomato 'RA Nome completo(com ou sem espacos)'.\n");
                printf("Exemplo:\n101 Ana Silva\n102 Ana Silva\n103 Ana Silva\n104 Ana Silva\n105 Ana Silva\n");
                printf("Nome do Arquivo:");
                scanf("%s", arquivo);

                LerArquivo(&ABB, arquivo);

                printf("Leitura do arquivo foi concluida.");
                break;
            }
        }
    //}
    while(stop != 0){
        printf("\n\nO que gostaria de fazer a lista de cadastros?\n");
        printf("0.Finalizar o programa.\n");
        printf("1.Ordenar.\n");
        printf("2.Buscar.\n");
        printf("3.Inserir.\n");
        printf("4.Remover.\n");
        do{
        printf("Digite o numero da sua opcao(0, 1, 2, 3 ou 4):");
        scanf("%d",&opcao);
        }
        while(opcao != 0 && opcao != 1 && opcao != 2 && opcao !=3 && opcao !=4);

        switch(opcao){
            case 0:{
                stop = 0;
                break;
            }
            case 1:{
                printf("\n\nComo ordenar?:\n");
                printf("0.Finalizar o programa.\n");
                printf("1.Ordem alfabetica.\n");
                printf("2.Ordem antialfabetica.\n");
                printf("3.Ordem numerica crescente.\n");
                printf("4.Ordem numerica decrescente.\n");
                do{
                    printf("Digite o numero da sua opcao(0, 1, 2, 3 ou 4):");
                    scanf("%d",&opcao);
                }
                while(opcao != 0 && opcao != 1 && opcao != 2 && opcao !=3 && opcao !=4);
                switch(opcao){
                    case 0:{
                        stop = 0;
                        break;
                    }
                    case 1:{
                        in_ordemNomeAlfa(ABB.rootNome);
                        printf("Voce deseja criar um arquivo com a lista de cadastro ordenada?\n");
                        printf("1.Sim.\n");
                        printf("2.Nao.\n");
                        int op;
                        do{
                            printf("Digite sua opcao(1 ou 2):");
                            scanf("%d",&op);
                        }
                        while(op != 1 && op != 2);
                        if(op == 1){
                            FILE *fp = fopen("OrdemAlfabetica.txt","w+");
                            if(PrintABBalfa(ABB.rootNome, fp)){
                                printf("Foi criado(se ja nao existia) um arquivo na pasta deste codigo chamado 'OrdemAlfabetica.txt' contendo a lista ordenada.");
                            }
                            fclose(fp);
                        }
                        
                        break;
                    }
                    case 2:{
                        in_ordemNomeAnti(ABB.rootNome);
                        printf("Voce deseja criar um arquivo com a lista de cadastro ordenada?\n");
                        printf("1.Sim.\n");
                        printf("2.Nao.\n");
                        int op;
                        do{
                            printf("Digite sua opcao(1 ou 2):");
                            scanf("%d",&op);
                        }
                        while(op != 1 && op != 2);
                        if(op == 1){
                            FILE *fp = fopen("OrdemAntialfabetica.txt","w+");
                            if(PrintABBanti(ABB.rootNome, fp)){
                                printf("Foi criado(se ja nao existia) um arquivo na pasta deste codigo chamado 'OrdemAntialfabetica.txt' contendo a lista ordenada.");
                            }
                            fclose(fp);
                        }
                        
                        break;
                    }
                    case 3:{
                        in_ordemRACres(ABB.rootRA);
                        printf("Voce deseja criar um arquivo com a lista de cadastro ordenada?\n");
                        printf("1.Sim.\n");
                        printf("2.Nao.\n");
                        int op;
                        do{
                            printf("Digite sua opcao(1 ou 2):");
                            scanf("%d",&op);
                        }
                        while(op != 1 && op != 2);
                        if(op == 1){
                            FILE *fp = fopen("OrdemNumCrescente.txt","w+");
                            if(PrintABBCres(ABB.rootRA, fp)){
                                printf("Foi criado(se ja nao existia) um arquivo na pasta deste codigo chamado 'OrdemNumCrescente.txt' contendo a lista ordenada.");
                            }
                            fclose(fp);
                        }
                        
                        break;
                    }
                    case 4:{
                        in_ordemRADecres(ABB.rootRA);
                        printf("Voce deseja criar um arquivo com a lista de cadastro ordenada?\n");
                        printf("1.Sim.\n");
                        printf("2.Nao.\n");
                        int op;
                        do{
                            printf("Digite sua opcao(1 ou 2):");
                            scanf("%d",&op);
                        }
                        while(op != 1 && op != 2);
                        if(op == 1){
                            FILE *fp = fopen("OrdemNumDecrescente.txt","w+");
                            if(PrintABBdecres(ABB.rootRA, fp)){
                                printf("Foi criado(se ja nao existia) um arquivo na pasta deste codigo chamado 'OrdemNumDecrescente.txt' contendo a lista ordenada.");
                            }
                            fclose(fp);
                        }
                        
                        break;
                    }
                }
                break;
            }
            case 2:{
                printf("\n\nBuscar por qual fator?\n");
                printf("0.Finalizar o programa.\n");
                printf("1.Buscar por RA.\n");
                printf("2.Buscar por Nome.\n");
                do{
                    printf("Digite o numero da sua opcao(0, 1, ou 2):");
                    scanf("%d",&opcao);
                }
                while(opcao != 0 && opcao != 1 && opcao != 2);
                switch(opcao){
                    case 0:{
                        stop = 0;
                        break;
                    }
                    case 1:{
                        printf("\n\nDigite o RA do cadastro que procura:");
                        scanf("%d", &RA);
                        if(!BuscaDoCadRA(ABB.rootRA, RA)){
                            printf("Nao existe cadastro com RA %d.", RA);
                        }
                        break;
                    }
                    case 2:{
                        printf("\n\nDigite o nome do cadastro que procura:");
                        getchar();
                        fgets(Nome, sizeof(Nome), stdin);
                        RemoverNewLine(Nome);
                        if(!BuscaDoCadNome(ABB.rootNome, Nome)){
                            printf("Nao existe cadastro com Nome %s", Nome);
                        }
                        break;
                    }
                }
                break;
            }
            case 3:{
                printf("Como voce deseja inserir mais cadastros?:\n");
                printf("0.Finalizar o programa.\n");
                printf("1.Digitando no prompt.\n");
                printf("2.Por um arquivo'.txt'.\n");
                do{
                    printf("Digite o numero da sua opcao(0, 1, ou 2):");
                    scanf("%d",&opcao);
                }
                while(opcao != 0 && opcao != 1 && opcao != 2);
                switch(opcao){
                    case 0:{
                        stop = 0;
                        break;
                    }
                    case 1:{
                        InserirManualmente(&ABB);
                        break;
                    }
                    case 2:{
                        char arquivo[100];
                        printf("\nInsira o nome do arquivo.\n");
                        printf("Arquivo tem que estar no fomato 'RA Nome completo(com ou sem espacos)'.\n");
                        printf("Exemplo:\n101 Ana Silva\n102 Ana Silva\n103 Ana Silva\n104 Ana Silva\n105 Ana Silva\n");
                        printf("Nome do Arquivo:");
                        scanf("%s", arquivo);
                        LerArquivo(&ABB, arquivo);
                        printf("A leitura do arquivo foi concluida.");
                        break;
                    }
                }
                break;
            }
            case 4:{
                printf("Como voce deseja remover cadastros?:\n");
                printf("0.Finalizar o programa.\n");
                printf("1.Digitando no prompt.\n");
                printf("2.Por um arquivo'.txt'.\n");
                do{
                    printf("Digite o numero da sua opcao(0, 1, ou 2):");
                    scanf("%d",&opcao);
                }
                while(opcao != 0 && opcao != 1 && opcao != 2);
                switch(opcao){
                    case 0:{
                        stop = 0;
                        break;
                    }
                    case 1:{
                        RemoverManualmente(&ABB);
                        break;
                    }
                    case 2:{
                        char arquivo[100];
                        printf("\nInsira o nome do arquivo.\n");
                        printf("Arquivo tem que estar no fomato 'RA Nome completo(com ou sem espacos)'.\n");
                        printf("Exemplo:\n101 Ana Silva\n102 Ana Silva\n103 Ana Silva\n104 Ana Silva\n105 Ana Silva\n");
                        printf("Nome do Arquivo:");
                        scanf("%s", arquivo);
                        RemoverPorArquivo(&ABB, arquivo);
                        printf("A remoção por arquivo foi concluida.");
                        break;
                    }
                }
                break;
            }

        }
    }
    return 0;
}


