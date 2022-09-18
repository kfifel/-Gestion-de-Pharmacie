#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "structers/structers.h"
#include "prototypes/prototype.h"
#include "services/pharmacie-services.h"
#include "services/pharmacie-print-functions.h"

int main() {
	// le tableau principale
	Product *product;
	product = (Product *) malloc( 3 * sizeof(Product) );
	// la taille de tbleau principale
	int len=3, *pLen;
	
	// l'initialisation du tableau par un produit
	product->codeP     =  1; 
	product->nomP      = "Dolipran"; 
	product->prixP     =  14.99;  
	product->prixTTC   =  product->prixP + product->prixP * 15/100;  
	product->quantiteP =  50;
	product++;
	
	product->codeP     =  2; 
	product->nomP      = "Hydrocortizone"; 
	product->prixP     =  39.45; 
	product->prixTTC   =  product->prixP + product->prixP * 15/100;  
	product->quantiteP =  50;
	product++;
	
	product->codeP     =  3; 
	product->nomP      = "Exemple"; 
	product->prixP     =  9.45; 
	product->prixTTC   =  product->prixP + product->prixP * 15/100;  
	product->quantiteP =  50;
	product = product - 2;
	
	pLen = &len; //pLen poin sur la taille de tableau 
	
	// topbar de l'application
	topbar();
	
	//Menu de l'application
	menu(product, pLen);
		
	return 0;
}
