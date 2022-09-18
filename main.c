#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
	// la taille de tbleau principale
	int len=3;
#include "structers/structers.h"
#include "prototypes/prototype.h"
#include "services/pharmacie-services.h"
#include "services/pharmacie-print-functions.h"

int main() {
	// le tableau principale
	Product *product;
	product = (Product *) malloc( 3 * sizeof(Product) );

	
	// l'initialisation du tableau par un produit
	product[0].codeP     =  1; 
	strcpy(product[0].nomP , "Dolipran"); 
	product[0].prixP     =  14.99;  
	product[0].prixTTC   =  product->prixP + product->prixP * 15/100;  
	product[0].quantiteP =  50;
	
	product[1].codeP     =  2; 
	strcpy(product[1].nomP, "Hydrocortizone"); 
	product[1].prixP     =  39.45; 
	product[1].prixTTC   =  product->prixP + product->prixP * 15/100;  
	product[1].quantiteP =  50;
	
	product[2].codeP     =  3; 
	strcpy(product[2].nomP, "Exemple"); 
	product[2].prixP     =  9.45; 
	product[2].prixTTC   =  product->prixP + product->prixP * 15/100;  
	product[2].quantiteP =  50;
	 
	
	// topbar de l'application
	topbar();
	
	//Menu de l'applicationvoid 
	
	int input;
	while(1){
		again :
		topbar();
		printf("\t\t\t\t\tList Menu \n\n\n");
		printf("%x", product);
	// return pointur to case 0 du tableau
		do {
			printf("\t\t\t1  Ajouter un nouveau produit\n\n");
			printf("\t\t\t2  Ajouter plusieurs nouveaux produits\n\n");
			printf("\t\t\t3  Lister tous les produits\n\n");
			printf("\t\t\t4  Acheter produit\n\n");
			printf("\t\t\t5  Rechercher les produits\n\n");
			printf("\t\t\t6  Etat du stock\n\n");
			printf("\t\t\t7  Alimenter le stock\n\n");
			printf("\t\t\t8  Supprimer les produits par\n\n");
			printf("\t\t\t9  Statistique de vente\n\n\n");
			printf("\t\t\t0  Quiter\n\n");
			input=getInt();
			switch(input) {
				case  0  :   exit(0); break;
				case  1  :   product = addProducts(product);  
							 printf("%x", product);break;
				case  2  :   product = addProducts(product); break;
				case  3  :   getAllProducts(product); break;
				case  4  : break;
				case  5  : break;
				case  6  : break;
				case  7  : break;
				case  8  : break;
				case  9  : break;
				case  10 : break; 
				default  : goto again;
			}
			
		}while(input > 10 || input < 0);
	}	

		
	return 0;
}
