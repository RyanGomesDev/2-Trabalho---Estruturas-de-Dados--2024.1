#include<stdio.h>
#include<stdlib.h>
#include "arvb.h"

struct arvb{
	ArvB *esq;
	int info;
	ArvB *dir;
};

int ehPrimo(int num){
	if (num <= 1){
		return 0;
	}

	for (int i = 2; i*i <= num; i++){
		if (num % i == 0){
			return 0;
		}
	}

	return 1;
};

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a==NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a)){
		return NULL;
	} else if(a->info < c){
		return arvb_busca(a->dir,c);
	} else if(a->info > c){
		return arvb_busca(a->esq,c);
	} else{ //(a->info == c)
		return a;
	}
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("| %d | ",a->info);
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c){
				a->esq = arvb_insere(a->esq,c);
	}else if (a->info < c){
		a->dir = arvb_insere(a->dir,c);
	}else{
		printf("\nElemento Ja Pertence a Arvore");
	}
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
 		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
 		else{
			ArvB* t;
	 		if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
		 	}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
		 	}else{
				t = a->esq;
				while(t->dir!=NULL)
					t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
 			}
 		}
	}
	return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

int arv_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSubArvEsq = arv_altura(a->esq);
		int hSubArvDir = arv_altura(a->dir);
		
		if(hSubArvEsq > hSubArvDir)
			return 1+hSubArvEsq;
		else
			return 1+hSubArvDir;
 	}
}

int folhas_primos(ArvB* a){
	if(arvb_vazia(a)){
		return 0;
	} else if(ehPrimo(a->info)){
		return 1 + folhas_primos(a->esq) + folhas_primos(a->dir);
	}
	
	return folhas_primos(a->esq) + folhas_primos(a->dir);
}

int dois_filhos(ArvB *a) {
    if (arvb_vazia(a)) {
        return 0;
    }
    
    int cont = 0;
    
    if (a->esq != NULL && a->dir != NULL) {
        cont = 1;
    }
    
    cont += dois_filhos(a->esq);
    cont += dois_filhos(a->dir);
    
    return cont;
}


/*int dois_filhos(ArvB* a){
	if(a == NULL){
		return 0;
	} else if(a->esq != NULL && a->dir != NULL){
		return 1 + folhas_primos(a->esq) + folhas_primos(a->dir);
	}
	
	return folhas_primos(a->esq) + folhas_primos(a->dir);
}*/

int nos_igual_altura(ArvB* a) {
    if (arvb_vazia(a)) {
        return 0;
    }

    int hEsq = arv_altura(a->esq);
    int hDir = arv_altura(a->dir);
    int cont = 0;

    if (arv_altura(a->esq) == arv_altura(a->dir)) {
        cont = 1;
    }

    cont += nos_igual_altura(a->esq);
    cont += nos_igual_altura(a->dir);
    
    return cont;
}


/*int nos_igual_altura(ArvB* a){
	if(a == NULL){
		return 0;
	} else if(arv_altura(a->esq) == arv_altura(a->dir)){
		return 1 + nos_igual_altura(a->esq) + nos_igual_altura(a->dir);
	}
	
	return nos_igual_altura(a->esq) + nos_igual_altura(a->dir);
}*/
