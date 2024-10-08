typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a);

/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);

/*Fun��o que imprime os elementos de uma �rvore.*/
void arvb_imprime(ArvB *a);

/*Fun��o que insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c);

/*Fun��o que remove um inteiro em uma �rvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

/*Fun��o que retorna a altura da �rvore.*/
int arv_altura(ArvB *a);

/*Retorna a quantidade de folhas que possuem no campo info um n�mero primo.*/
int folhas_primos(ArvB* a);

/*Retorna a quantidade de n�s que possuem os dois filhos (campos dir e esq diferentes de NULL).*/
int dois_filhos(ArvB* a);

/*Retorna a quantidade de n�s cujas sub�rvores esquerda e direita t�m igual altura.*/
int nos_igual_altura(ArvB* a);

/*Compara se duas �rvores bin�rias de busca s�o iguais.*/
int iguais(ArvB* a, ArvB* b);
