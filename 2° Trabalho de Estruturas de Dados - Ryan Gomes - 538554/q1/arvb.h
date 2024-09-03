typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);

/*Função que retorna a altura da Árvore.*/
int arv_altura(ArvB *a);

/*Retorna a quantidade de folhas que possuem no campo info um número primo.*/
int folhas_primos(ArvB* a);

/*Retorna a quantidade de nós que possuem os dois filhos (campos dir e esq diferentes de NULL).*/
int dois_filhos(ArvB* a);

/*Retorna a quantidade de nós cujas subárvores esquerda e direita têm igual altura.*/
int nos_igual_altura(ArvB* a);
