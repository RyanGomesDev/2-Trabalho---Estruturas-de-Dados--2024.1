#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main(void){

	ArvB* arv1 = arvb_cria_vazia();
	arv1=arvb_insere(arv1,9);
	arv1=arvb_insere(arv1,5);
	arv1=arvb_insere(arv1,21);
	arv1=arvb_insere(arv1,4);
	arv1=arvb_insere(arv1,77);
	arv1=arvb_insere(arv1,0);
	arv1=arvb_remove(arv1,4);
	printf("\nAltura da arvore: %d\n",arv_altura(arv1));
	printf("Qtd folhas primos: %d\n",folhas_primos(arv1));
	printf("Qtd de nos dois filhos: %d\n",dois_filhos(arv1));
	printf("Nos igual altura: %d\n",nos_igual_altura(arv1));

	ArvB* arv2 = arvb_cria_vazia();
	arv2=arvb_insere(arv2,5);
	arv2=arvb_insere(arv2,6);
	arv2=arvb_insere(arv2,11);
	ArvB* arv3 = arvb_cria_vazia();
	arv3=arvb_insere(arv3,5);
	arv3=arvb_insere(arv3,6);
	arv3=arvb_insere(arv3,11);
	printf("<Impressao arvore 1>\n");
	arvb_imprime(arv1); //impressao em ordem sim�trica
	printf("\n<Impressao arvore 2>\n");
	arvb_imprime(arv2); //impressao em ordem sim�trica
	printf("\n");
	int comp = iguais(arv1,arv2);
	printf("Arvores iguais %d\n",comp);
	comp = iguais(arv2,arv3);
	printf("Arvores iguais %d\n\n",comp);
	arvb_libera(arv1);
	arvb_libera(arv2);
	arvb_libera(arv3);
	system("PAUSE");

	return 0;
}
