#pragma once


#include <stdio.h>
#include <stdbool.h>

typedef struct Cadastro{
    int RA;
    char Nome[100];
}Cadastro;

typedef struct NodeNome{
    Cadastro info;
    struct NodeNome *dir;
    struct NodeNome *esq;
}NodeNome;

typedef struct NodeRA{
    Cadastro info;
    struct NodeRA *dir;
    struct NodeRA *esq;
}NodeRA;

typedef NodeNome* NodeNomePtr;

typedef NodeRA* NodeRAPtr;

typedef struct ArvoreBB{
    NodeNomePtr rootNome;
    NodeRAPtr rootRA;
}ArvoreBB;

void criar(ArvoreBB *ABB);
bool vaziaNome(ArvoreBB *ABB);//retorna true se a arvore esta, caso contrario false
bool vaziaRA(ArvoreBB *ABB);//retorna true se a arvore esta vazia, caso contrario false
bool cheia(ArvoreBB *ABB);//retorna true se a memoria esta cheia, caso contrario false
NodeNomePtr EstaNaArvoreNome(NodeNomePtr root, char Nome[100]);//retorna o ponteiro que aponta para o struct node que contém o string de char "Nome"
NodeRAPtr EstaNaArvoreRA(NodeRAPtr root, int RA);//retorna o ponteiro que aponta para o struct node que contém o valor inteiro "RA"
void in_ordemNomeAlfa(NodeNomePtr root);//é
void in_ordemNomeAnti(NodeNomePtr root);
void in_ordemRACres(NodeRAPtr root);
void in_ordemRADecres(NodeRAPtr root);
void pre_ordemNome(NodeNomePtr root);
void pre_ordemRA(NodeRAPtr root);
void pos_ordemNome(NodeNomePtr root);
void pos_ordemRA(NodeRAPtr root);
bool inserirNome(NodeNomePtr *root, Cadastro c);
bool inserirRA(NodeRAPtr *root, Cadastro c);
NodeNomePtr ValorMinArvoreNome(NodeNomePtr root);
NodeNomePtr ValorMaxArvoreNome(NodeNomePtr root);
NodeRAPtr ValorMinArvoreRA(NodeRAPtr root);
NodeRAPtr ValorMaxArvoreRA(NodeRAPtr root);
bool removerNome(NodeNomePtr *root, Cadastro c);
bool removerRA(NodeRAPtr *root, Cadastro c);
bool PrintABBalfa  (NodeNomePtr root, FILE *fp);
bool PrintABBanti  (NodeNomePtr root, FILE *fp);
bool PrintABBCres  (NodeRAPtr   root, FILE *fp);
bool PrintABBdecres(NodeRAPtr   root, FILE *fp);
bool BuscaDoCadNome(NodeNomePtr root, char Nome[100]);
bool BuscaDoCadRA(NodeRAPtr root, int RA);
void RemoverNewLine(char *Nome);
void InserirManualmente(ArvoreBB *ABB);
void LerArquivo(ArvoreBB *ABB, char* Arquivo);
void RemoverPorArquivo(ArvoreBB *ABB, char *arquivo);
void RemoverManualmente(ArvoreBB *ABB);