#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
	// la taille de tbleau principale
	int len=3, lenBuy = 1;
#include "structers/structers.h"
#include "prototypes/prototype.h"
#include "services/pharmacie-services.h"
#include "services/pharmacie-print-functions.h"

int main() {
	//time
	time_t rawtime;
    time( &rawtime );
    
	// le tableau principale
	Product *product;
	product = (Product *) malloc( 3 * sizeof(Product) );
	
	ProduitAcheter *productAcheter;
	productAcheter = (ProduitAcheter *) malloc( lenBuy * sizeof(ProduitAcheter) );
	// l'initialisation du tableau par un produit
	product[0].codeP     =  1; 
	strcpy(product[0].nomP , "Dolipran"); 
	product[0].prixP     =  14.99;  
	product[0].prixTTC   =  product[0].prixP + product[0].prixP * 15/100;  
	product[0].quantiteP =  50;
	
	product[1].codeP     =  2; 
	strcpy(product[1].nomP, "Hydrocortizone"); 
	product[1].prixP     =  39.45; 
	product[1].prixTTC   =  product[1].prixP + product[1].prixP * 15/100;  
	product[1].quantiteP =  50;
	
	product[2].codeP     =  3; 
	strcpy(product[2].nomP, "Exemple"); 
	product[2].prixP     =  9.45; 
	product[2].prixTTC   =  product[2].prixP + product[2].prixP * 15/100;  
	product[2].quantiteP =  50;
	 
	productAcheter[0].codeP = product[0].codeP;
	productAcheter[0].quantiteP = 2;
	productAcheter[0].date =localtime( &rawtime );
	
	// topbar de l'application
	topbar();
	
	//Menu de l'applicationvoid 
	
	int input;
	while(1){
		again :
		topbar();
		printf("\t\t\t\t\tList Menu \n\n\n");
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
				case  0  :  exit(0); break;
				case  1  :  product = addProduct(product);  break;
				case  2  :  product = addProducts(product); break;
				case  3  :  
							while(1){
								int choix;
								do{
									topbar();
									printf("\t\t\t\t----  lister tous les produits ---- \n\n\n");
									printf("\t\t\t1  lister tous les produits selon l’ordre alphabétique  croissant du nom \n\n");
									printf("\t\t\t2  lister tous les produits selon l’ordre  décroissant du prix.\n\n");
									printf("\t\t\t0  Menu \n\n");
									choix = getInt();
								}while( choix > 2 || choix < 0);
								
								switch( choix ){
									case 1 :  findProductByCode(product); break;
									case 2 :  findProductByQte(product);break;
									case 0 :  break;
								}
								if(!choix) break;
							} 
				case  4  :   buyProduct( product, productAcheter ); break;
				case  5  : 	while(1){
								int choix;
								do{	
									topbar();
									printf("\t\t\t1  Rechercher Des Produits Par Code \n\n");
									printf("\t\t\t2  Rechercher Des Produits Par Quantite\n\n");
									printf("\t\t\t0  Menu \n\n");
									choix = getInt();
								}while( choix > 2 || choix < 0);
								
								switch( choix ){
									case 1 :  findProductByCode(product); break;
									case 2 :  findProductByQte(product);break;
									case 0 :  break;
								}
								if(!choix) break;
							} 
							break;		
				case  6  :  stockStatus(product); break;
				case  7  :  supplyStock(product); break;
				case  8  :  break;
				case  9  :  break;
				case  10 :  break; 
				default  :  goto again;
			}
			
		}while(input > 10 || input < 0);
	}	

		
	return 0;
}
