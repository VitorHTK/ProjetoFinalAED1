#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void criar(ArvoreBB *ABB){
    ABB->rootNome = NULL;
    ABB->rootRA = NULL;
}

bool vaziaNome(ArvoreBB *ABB){
    return ABB->rootNome == NULL;
}

bool vaziaRA(ArvoreBB *ABB){
    return ABB->rootRA == NULL;
}

bool cheia(ArvoreBB *ABB){
    (void) ABB;
    NodeNomePtr temp = (NodeNomePtr) malloc (sizeof(NodeNome));//NodeRAPtr temp = (NodeRAPtr) malloc (sizeof(NodeRA));
    if (temp == NULL) return  true;
    free (temp);
    return false;
}

NodeNomePtr EstaNaArvoreNome(NodeNomePtr root, char Nome[100]){
    if(root == NULL) return NULL;
    int cmp = strcmp(Nome,root->info.Nome);
    if (cmp == 0) return root;
    else if (cmp < 0) return EstaNaArvoreNome(root->esq, Nome);
    else if (cmp > 0) return EstaNaArvoreNome(root->dir, Nome);
    return NULL;
}

NodeRAPtr EstaNaArvoreRA(NodeRAPtr root, int RA){
    if(root == NULL) return NULL;
    if (RA == root->info.RA) return root;
    else if (RA < root->info.RA) return EstaNaArvoreRA(root->esq, RA);
    else if (RA > root->info.RA) return EstaNaArvoreRA(root->dir, RA);
    return NULL;
}

void in_ordemNomeAlfa(NodeNomePtr root){//vai ser utilizado para ordenção
    if(root == NULL)
        return;
    in_ordemNomeAlfa(root->esq);
    printf("%d|%s\n", root->info.RA, root->info.Nome);
    in_ordemNomeAlfa(root->dir);
}

void in_ordemNomeAnti(NodeNomePtr root){//vai ser utilizado para ordenção
    if(root == NULL)
        return;
    in_ordemNomeAnti(root->dir);
    printf("%d|%s\n", root->info.RA, root->info.Nome);
    in_ordemNomeAnti(root->esq);
}

void in_ordemRACres(NodeRAPtr root){//vai ser utilizado para ordenação
    if(root == NULL)
        return;
    in_ordemRACres(root->esq);
    printf("%d|%s\n", root->info.RA, root->info.Nome);
    in_ordemRACres(root->dir);
}

void in_ordemRADecres(NodeRAPtr root){//vai ser utilizado para ordenação
    if(root == NULL)
        return;
    in_ordemRADecres(root->dir);
    printf("%d|%s\n", root->info.RA, root->info.Nome);
    in_ordemRADecres(root->esq);
}

void pre_ordemNome(NodeNomePtr root){//percorre a arvore toda a partir do root(ordem de criação de arvore)
    if(root == NULL)
        return;
    printf("%s",root->info.Nome);
    pre_ordemNome(root->esq);
    pre_ordemNome(root->dir);
}

void pre_ordemRA(NodeRAPtr root){
    if(root == NULL)
        return;
    printf("%d",root->info.RA);
    pre_ordemRA(root->esq);
    pre_ordemRA(root->dir);
}

void pos_ordemNome(NodeNomePtr root){//percorre a arvore a partir da ultima folha(ordem de destruição)
    if(root == NULL)
        return;
    pos_ordemNome(root->esq);
    pos_ordemNome(root->dir);
    printf("%s",root->info.Nome);
}

void pos_ordemRA(NodeRAPtr root){
    if(root == NULL)
        return;
    pos_ordemRA(root->esq);
    pos_ordemRA(root->dir);
    printf("%d",root->info.RA);
}

bool inserirNome(NodeNomePtr *root, Cadastro c){//ponteiro para ponteiro.
    if(*root == NULL){
        NodeNomePtr aux = (NodeNomePtr) malloc (sizeof(NodeNome));
        aux->dir = NULL;
        aux->esq = NULL;
        aux->info = c;
        *root = aux;
        return true;
    }
    int cmp = strcmp(c.Nome, (*root)->info.Nome);

    if(cmp < 0)
        return inserirNome(&(*root)->esq, c);

    else if(cmp > 0)
        return inserirNome(&(*root)->dir, c);

    else{//posso colocar o if(cmp == 0)
        if(c.RA < (*root)->info.RA)
        return inserirNome(&(*root)->esq, c);

        else if(c.RA > (*root)->info.RA)
            return inserirNome(&(*root)->dir, c);

        else{//posso colocar o if(c.RA == (*root)->info.RA)
            printf("Nome e RA do cadastro ja existem.\n");
            return false;
        }
    }
    return false;
}

bool inserirRA(NodeRAPtr *root, Cadastro c){//ponteiro para ponteiro.
    if(*root == NULL){
        NodeRAPtr aux = (NodeRAPtr) malloc (sizeof(NodeRA));
        aux->dir = NULL;
        aux->esq = NULL;
        aux->info = c;
        *root = aux;
        return true;
    }
    if(c.RA < (*root)->info.RA)
        return inserirRA(&(*root)->esq, c);

    else if(c.RA > (*root)->info.RA)
        return inserirRA(&(*root)->dir, c);

    else{//posso colocar o if(c.RA == (*root)->info.RA)
        printf("RA do cadastro ja existe\n");
        return false;
    }
    return false;
}

NodeNomePtr ValorMinArvoreNome(NodeNomePtr root){//acha o valor minimo de uma arvoreBB de Nome
    NodeNomePtr aux = root;
    while(aux && aux->esq)
        aux = aux->esq;
    return aux;
}

NodeNomePtr ValorMaxArvoreNome(NodeNomePtr root){//acha o valor maximo de uma arvoreBB de Nome
    NodeNomePtr aux = root;
    while(aux && aux->dir)
        aux = aux->dir;
    return aux;
}

NodeRAPtr ValorMinArvoreRA(NodeRAPtr root){//acha o valor minimo de uma arvoreBB de RA
    NodeRAPtr aux = root;
    while(aux && aux->esq)
        aux = aux->esq;
    return aux;
}

NodeRAPtr ValorMaxArvoreRA(NodeRAPtr root){//acha o valor maximo de uma arvoreBB de RA
    NodeRAPtr aux = root;
    while(aux && aux->dir)
        aux = aux->dir;
    return aux;
}

bool removerNome(NodeNomePtr *root, Cadastro c){
    if(*root==NULL) return false;
    int cmp = strcmp(c.Nome, (*root)->info.Nome);
    if(cmp < 0) return removerNome(&(*root)->esq, c);
    else if(cmp > 0) return removerNome(&(*root)->dir, c);
    else if(cmp == 0){
//        if((*root)->esq == NULL && (*root)->dir == NULL){
//            NodeNomePtr temp = *root;
//            *root = (*root)->dir;
//            free(temp);
//            return true;
//        } nao precisava disso
        if((*root)->dir == NULL){//else if((*root)->esq != NULL && (*root)->dir == NULL){
            NodeNomePtr temp = *root;
            *root = (*root)->esq;
            free(temp);
            return true;
        }
        else if((*root)->esq == NULL){//else if((*root)->dir != NULL && (*root)->esq == NULL){
            NodeNomePtr temp = *root;
            *root = (*root)->dir;
            free(temp);
            return true;
        }
        else if((*root)->esq != NULL && (*root)->dir != NULL){
            NodeNomePtr aux = ValorMinArvoreNome((*root)->dir);//NodeNomePtr aux = ValorMaxArvoreNome((*root)->esq)
            (*root)->info = aux->info;
            removerNome(&(*root)->dir, aux->info);//removerNome(&(*root)->esq, aux->info);
            return true;
        }
    }
    return false;
}

bool removerRA(NodeRAPtr *root, Cadastro c){
    if(*root == NULL) return false;
    if(c.RA < (*root)->info.RA) return removerRA(&(*root)->esq, c);
    else if(c.RA > (*root)->info.RA) return removerRA(&(*root)->dir, c);
    else if(c.RA == (*root)->info.RA){
        if((*root)->dir == NULL){
            NodeRAPtr temp = *root;
            *root = (*root)->esq;
            free(temp);
            return true;
        }
        else if((*root)->esq == NULL){
            NodeRAPtr temp = *root;
            *root = (*root)->dir;
            free(temp);
            return true;
        }
        else if((*root)->esq != NULL && (*root)->dir != NULL){
            NodeRAPtr aux = ValorMaxArvoreRA((*root)->esq);//NodeRAPtr aux = ValorMinArvore((*root)->dir);
            (*root)->info = aux->info;
            removerRA(&(*root)->esq, aux->info);//removerRA(&(*root)->dir, aux->info);
            return true;
        }
    }
    return false;
}

bool PrintABBalfa(NodeNomePtr root, FILE *fp){//criar, abrir e fechar file no main
    if(root == NULL)
        return false;
    PrintABBalfa(root->esq, fp);
    fprintf(fp,"(%d)%s\n",root->info.RA, root->info.Nome);
    PrintABBalfa(root->dir, fp);
    return true;
}

bool PrintABBanti(NodeNomePtr root, FILE *fp){//criar, abrir e fechar file no main
    if(root == NULL)
        return false;
    PrintABBanti(root->dir, fp);
    fprintf(fp,"(%d)%s\n",root->info.RA, root->info.Nome);
    PrintABBanti(root->esq, fp);
    return true;
}

bool PrintABBCres(NodeRAPtr root, FILE *fp){//criar, abrir e fechar file no main
    if(root == NULL)
        return false;
    PrintABBCres(root->esq, fp);
    fprintf(fp,"(%d)%s\n",root->info.RA, root->info.Nome);
    PrintABBCres(root->dir, fp);
    return true;
}

bool PrintABBdecres(NodeRAPtr root, FILE *fp){//criar, abrir e fechar file no main
    if(root == NULL)
        return false;
    PrintABBdecres(root->dir, fp);
    fprintf(fp,"(%d)%s\n",root->info.RA, root->info.Nome);
    PrintABBdecres(root->esq, fp);
    return true;
}

bool BuscaDoCadNome(NodeNomePtr root, char Nome[100]){// vou ter que trocar quando for fzr um struct NomeCompleto
    if(root==NULL) return false;
    int cmp = strcmp(Nome, root->info.Nome);
    if(cmp < 0) BuscaDoCadNome(root->esq, Nome);
    else if(cmp > 0) BuscaDoCadNome(root->dir, Nome);
    else if(cmp == 0){//após podar a arvore começa a busca pelos galhos que restam.
        printf("RA:%d|nome:%s\n",root->info.RA, root->info.Nome);
        BuscaDoCadNome(root->esq, Nome);
        BuscaDoCadNome(root->dir, Nome);
        return true;
    }
}//busca todos os cadastros com o nome em questao

bool BuscaDoCadRA(NodeRAPtr root, int RA){
    if(root==NULL){
        return false;   
    }
    if(RA < root->info.RA) BuscaDoCadRA(root->esq, RA);
    else if(RA > root->info.RA) BuscaDoCadRA(root->dir, RA);
    else if(RA == root->info.RA){
        printf("RA:%d|Nome:%s\n",root->info.RA, root->info.Nome);
        return true;
    }
}//busca o cadastro com o RA em questao

void RemoverNewLine(char *Nome){//na linha de baixo tem um '(int)', é um cast(conversao de tipo) falando que quero guardar o resultado de strlen(Nome) em um int.
    int length = (int)strlen(Nome);// o mais certo seria size_t(variavel para indices, numeros nao negativos, para funções de tamanho(strlen,sizeof,etc)).
    if (length > 0 && Nome[length-1] == '\n'){// se o tamanho for maior que 0 e o caractere antes do '\0' for '\n'.
        Nome[length-1] = '\0';//transforma o '\n' em '\0'.
    }
}

void InserirManualmente(ArvoreBB *ABB){//coloquei em função para nao bagunçar o main.
    Cadastro c;

    if(cheia(ABB)){
        printf("Nao foi possivel alocar memoria.\n");
        return;
    }
    printf("\nInsira cada cadastro manualmente.\n");
    printf("No formato 'RA' e depois 'Nome' e aperte enter.\n");
    printf("Quando acabar digite como se o RA do cadastro fosse 0.\n\n");

    while(1){
        printf("RA (digite 0 para encerrar):");
        scanf("%d",&c.RA);

        if(c.RA == 0){
            printf("Encerrando a leitura.\n");
                    break;
        }

        getchar();// ele lê o caractere "\n" que o scanf deixa no buffer para o fgets nao ler e finalizar a leitura do nome antes de ler no nome.

        printf("Nome:");
        fgets(c.Nome, sizeof(c.Nome),stdin);//nao usa o gets pq é perigoso, ele nao sabe o tamanho do buffer no caso nome[100], pode estourar ele.

        RemoverNewLine(c.Nome);

        if(!inserirRA(&ABB->rootRA, c)){//tenta inserir e se der errado...
            printf("Nao foi possivel inserir RA:%d na arvore de RA(RA ja existe).\n",c.RA);
        }
        if(!inserirNome(&ABB->rootNome, c)){//tenta inserir se der errado...
            printf("Nao foi possivel inserir Nome:%s na arvore de Nome(RA + Nome ja existem).\n",c.Nome);
        }
    }
}

void LerArquivo(ArvoreBB *ABB, char* Arquivo){// decidi colocar aqui pra nao ter que criar as variaveis de arquivo no main.
    FILE *fp = fopen(Arquivo,"r");//abre o arquivo em modo de leitura e aponta o ponteiro 'fp' tipo FILE para ele.

    if(fp == NULL){
        printf("Nao foi possivel abrir este arquivo(Nome errado?).");
        return;
    }

    Cadastro c;

    while(fscanf(fp, "%d ", &c.RA) == 1){//enquanto o arquivo nao acabar ou der erro na no fscan o enqunato continua. Aqui ele ja leu o RA.
        if(fgets(c.Nome, sizeof (c.Nome), fp) == NULL){//linha mal formatada ou fim inesperado.
            break;
        }

        RemoverNewLine(c.Nome);//tira o \n que o fgets leu substituindo ele por \0.

        if(!inserirRA(&ABB->rootRA, c)){//tenta inserir e se der errado...
            printf("Nao foi possivel inserir RA:%d na arvore de RA(RA ja existe).\n",c.RA);
        }
        if(!inserirNome(&ABB->rootNome, c)){//tenta inserir se der errado...
            printf("Nao foi possivel inserir Nome:%s na arvore de Nome(RA + Nome ja existem).\n",c.Nome);
        }        
    }
    fclose(fp);
}

void RemoverPorArquivo(ArvoreBB *ABB, char *Arquivo){
        FILE *fp = fopen(Arquivo,"r");//abre o arquivo em modo de leitura e aponta o ponteiro 'fp' tipo FILE para ele.

    if(fp == NULL){
        printf("Nao foi possivel abrir este arquivo(Nome errado?).");
        return;
    }

    Cadastro c;

    while(fscanf(fp, "%d ", &c.RA) == 1){//enquanto o arquivo nao acabar ou der erro na no fscan o enqunato continua. Aqui ele ja leu o RA.
        if(fgets(c.Nome, sizeof (c.Nome), fp) == NULL){//linha mal formatada ou fim inesperado.
            break;
        }

        RemoverNewLine(c.Nome);//tira o \n que o fgets leu substituindo ele por \0.

        if(!removerRA(&ABB->rootRA, c)){//tenta remover e se der errado...
            printf("Nao foi possivel Remover RA:%d na arvore de RA(Cadastro nao existe).\n",c.RA);
        }
        if(!removerNome(&ABB->rootNome, c)){//tenta remover se der errado...
            printf("Nao foi possivel Remover Nome:%s na arvore de Nome(Cadastro nao existe).\n",c.Nome);
        }        
    }
    fclose(fp);
}

void RemoverManualmente(ArvoreBB *ABB){
    Cadastro c;

    if(vaziaNome(ABB)){
        printf("A lista de cadastros está vazia\n");
        return;
    }
    printf("\nInsira cada cadastro manualmente.\n");
    printf("No formato 'RA' e depois 'Nome' e aperte enter.\n");
    printf("Quando acabar digite como se o RA do cadastro fosse 0.\n\n");

    while(1){
        printf("RA (digite 0 para encerrar):");
        scanf("%d",&c.RA);

        if(c.RA == 0){
            printf("Encerrando a leitura.\n");
                    break;
        }

        getchar();// ele lê o caractere "\n" que o scanf deixa no buffer para o fgets nao ler e finalizar a leitura do nome antes de ler no nome.

        printf("Nome:");
        fgets(c.Nome, sizeof(c.Nome),stdin);//nao usa o gets pq é perigoso, ele nao sabe o tamanho do buffer no caso nome[100], pode estourar ele.

        RemoverNewLine(c.Nome);

        if(!removerRA(&ABB->rootRA, c)){//tenta remover e se der errado...
            printf("Nao foi possivel remover RA:%d na arvore de RA(cadastro nao existe).\n",c.RA);
        }
        if(!removerNome(&ABB->rootNome, c)){//tenta remover se der errado...
            printf("Nao foi possivel remover Nome:%s na arvore de Nome(cadastro não existe).\n",c.Nome);
        }
    }
}