void nchar(char c, int n){
	while(n--){
		printf("%c", c);
	}
}

void printTab(){
	printf("\t\t\t");
}

int getInt(){
	int n;
	printf("\t\t\t:");
	scanf("%d", &n);
return n;
}

void topbar(){
	system("cls");
	printf("\t\t\t");
	
	nchar('-', 18);
	printf("Projet Fin SAS (2022/2023)");
	nchar('-', 18);
	
	printf("\n");
	printf("\t\t\t");
	nchar('-', 21);
	printf("Gestion de Pharmacie");
	nchar('-', 21);
	printf("\n\n\n\n");
}

void menu(Product *product, int *len){
	Product *products = product;
	int input;
	while(1){
		topbar();
		printf("\t\t\t\t\tList Menu \n\n\n");
	
		do{
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
				case  1  :   addProduct(products, len); break;
				case  2  :   addProducts(products, len); break;
				case  3  :  getAllProducts(products, len); break;
				case  4  :  break;
				case  5  :  break;
				case  6  :  break;
				case  7  :  break;
				case  8  :  break;
				case  9  :  break;
				case  10 :  break;
			}
			
		}while(input > 10 || input < 0);
	}	
}


