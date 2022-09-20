#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
	// la taille de tbleau principale
	int len=3, lenBuy = 3;
#include "structers/structers.h"
#include "prototypes/prototype.h"
#include "services/pharmacie-services.h"
#include "services/pharmacie-print-functions.h"

int main() {
	production();
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
	product[0].quantiteP =  48;
	
	product[1].codeP     =  2; 
	strcpy(product[1].nomP, "Hydrocortizone"); 
	product[1].prixP     =  39.45; 
	product[1].prixTTC   =  product[1].prixP + product[1].prixP * 15/100;  
	product[1].quantiteP =  50;
	
	product[2].codeP     =  3; 
	strcpy(product[2].nomP, "Exemple"); 
	product[2].prixP     =  11.45; 
	product[2].prixTTC   =  product[2].prixP + product[2].prixP * 15/100;  
	product[2].quantiteP =  49;
	 
	productAcheter[0].codeP = product[0].codeP;
	productAcheter[0].prixTTC = product[0].prixTTC;
	productAcheter[0].quantiteP = 3;
	productAcheter[0].date =localtime( &rawtime );
	
	productAcheter[1].codeP = product[1].codeP;
	productAcheter[1].prixTTC = product[1].prixTTC;
	productAcheter[1].quantiteP = 2;
	productAcheter[1].date =localtime( &rawtime );
	
	productAcheter[2].codeP = product[2].codeP;
	productAcheter[2].prixTTC = product[2].prixTTC;
	productAcheter[2].quantiteP = 1;
	productAcheter[2].date =localtime( &rawtime );
	// topbar de l'application
	topbar();
	
	//Menu de l'applicationvoid 
	
	int input;
	while(1){
		again :
		topbar();
		printTab();printf("\t\tList Menu \n\n\n");
		do {
			printTab();printf("1  Ajouter un nouveau produit\n\n");
			printTab();printf("2  Ajouter plusieurs nouveaux produits\n\n");
			printTab();printf("3  Lister tous les produits\n\n");
			printTab();printf("4  Acheter produit\n\n");
			printTab();printf("5  Rechercher les produits\n\n");
			printTab();printf("6  Etat du stock\n\n");
			printTab();printf("7  Alimenter le stock\n\n");
			printTab();printf("8  Supprimer les produits par\n\n");
			printTab();printf("9  Statistique de vente\n\n\n");
			printTab();printf("10 Historique des ventes\n\n\n");
			printTab();printf("11 afficher les ventes\n\n\n");
			printTab();printf("0  Quiter\n\n");
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
									printTab();printf("\t----  lister tous les produits ---- \n\n\n");
									printTab();printf("1  lister tous les produits selon l'ordre alphabetique  croissant du nom \n\n");
									printTab();printf("2  lister tous les produits selon l'ordre  decroissant du prix.\n\n");
									printTab();printf("0  Menu \n\n");
									choix = getInt();
								}while( choix > 2 || choix < 0);
								
								switch( choix ){
									case 1 :  getAllProductsByNom( product ); break;
									case 2 :  getAllProducts(product);break;
									case 0 :  break;
								}
								if(!choix) break;
							} 
							break;
				case  4  :   buyProduct( product, productAcheter ); break;
				case  5  : 	while(1){
								int choix;
								do{	
									topbar();
									printTab();printf("1  Rechercher Des Produits Par Code \n\n");
									printTab();printf("2  Rechercher Des Produits Par Quantite\n\n");
									printTab();printf("0  Menu \n\n");
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
				case  8  :  deleteP(product);
							break;
				case  9  :  productStatistics( product, productAcheter ); break;
				case  10 :  historyProductVendu( product, productAcheter ); break; 
				case  11 :  getAllProductsVendu( productAcheter ); break; 
				default  :  
							{
								topbar();
								system("color 4");
								printTab();
								printf("         404 not found \n");
							}
							sleep(3);
							goto again;
			}
			
		}while(input > 10 || input < 0);
	}	

		
	return 0;
}
