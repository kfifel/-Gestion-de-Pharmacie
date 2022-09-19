//    ------------------- Functions of  the projet -------------------    
   
bool productIsExist(int code, Product *product, int lenc){
	int i, exist = 0;
	for( i = 0; i < lenc; i++){
		if( product[i].codeP == code) exist = 1;
	}
	return exist? true : false;
}

void getAllProducts( Product *product ){
	
	int i;
	printTab();
	printf("Liste All products : len: %d \n", len);
	for( i = 0; i < len; i++) {
		printTab();
		printf("Name of product : %s |  Prix : %.3fDH | PrixTTC : %.3fDH \n", product[i].nomP, product[i].prixP, product[i].prixTTC);
	}
	//free(productLocale);
	system("pause");
	
}

		               
Product *addProduct( Product *product ){
	bool exist;
	char nom[50];
	printTab();
	
	len = len + 1;    
	product = realloc ( product, len * sizeof( *product ) );
		printTab();
		printf("---  les Donner de Produit --- \n");
	
	do{
		printTab();
		printf("Saisez le Code de produit  ");
		scanf("%d", &product[len - 1].codeP);
		exist = productIsExist( product[len - 1].codeP, product, len - 1 ); // 0 1 2  len 3 
		printTab();
		if( exist ) printf("le code  %d deja exister ...\n", product[len - 1].codeP);
		
	}while( exist );
	
	printf("Saisez le Nom de produit : ");
	scanf("%s", nom);
	strcpy(product[len - 1].nomP ,nom);
	
	printTab();
	printf("Saisez la Quantite de produit : ");
	scanf("%d", &product[len - 1].quantiteP);
	
	printTab();
	printf("Saisez le Prix de produit  : ");
	scanf("%f", &product[len - 1].prixP);
	
	product[len - 1].prixTTC = product[len - 1].prixP + product[len - 1].prixP * 15 / 100;
	
	printTab();
	printf("Product n is saved with success\n");
	system("pause");
	return product;
}

Product *addProducts( Product *product ){
	bool exist;
	int N, pos = 0, i;
	char nom[50];
	
	printTab();
	printf("Donner le nombre des produits que vous voullez ajoutez : ");
	scanf("%d", &N);
	
	len = len + N;    
	product = realloc ( product, len * sizeof( *product ) );
	printf("%x", product);
	for( i = len - N ; i  < len; i++ ){
		pos++;
			printTab();
			printf("---  les Donner de Produit N : %d --- \n", pos);
		
		do{
			printTab();
			printf("Saisez le Code de produit %d:  ", pos);
			scanf("%d", &product[i].codeP);
			printf("%d", product[i].codeP);
			system("pause");
			exist = productIsExist( product[i].codeP, product, len - N + pos - 1 ); // 0 1 2  len 3 
			
			printTab();
			if( exist ) printf("le code  %d deja exister ...\n", product[i].codeP);
			
		}while( exist );
		
		printf("Saisez le Nom de produit %d : ", pos);
		scanf("%s", nom);
		strcpy(product[i].nomP ,nom);
		
		printTab();
		printf("Saisez la Quantite de produit %d : ", pos);
		scanf("%d", &product[i].quantiteP);
		
		printTab();
		printf("Saisez le Prix de produit %d : ", pos);
		scanf("%f", &product[i].prixP);
		
		product[i].prixTTC = product[i].prixP + product[i].prixP * 15 / 100;
		
		printTab();
		printf("Product n %d is saved with success\n", pos);
	}
	return product;
}

void getAllProductsByNom( Product *product ){
	
}

void getAllProductsByPrice( Product *product ){
	
}

void buyProduct( Product Product, int qte ) {
	
}

void findProductByCode( Product *product){
	int code, i; 
	
	printTab();
	printf("--- Rechercher Des Produits Par Code ---\n\n");
	
	printTab();
	printf("Donner Le Code De Produit A Chercher\n\n");
	code = getInt();
	
	for( i = 0; i < len; i++) {
		printTab();
		if( product[i].codeP == code )
		printf("Name of product : %s |  Prix : %.3fDH | PrixTTC : %.3fDH \n", product[i].nomP, product[i].prixP, product[i].prixTTC);
	}
	//free(productLocale);
	system("pause");
}


void findProductByQte( Product *product ){
	int qte, i; 
	
	printTab();
	printf("--- Rechercher Des Produits Par Quantite ---\n\n");
	
	printTab();
	printf("Donner La Une Quantite A Rechercher\n\n");
	qte = getInt();
	
	for( i = 0; i < len; i++) {
		if( product[i].quantiteP == qte ){
			printTab();
			printf("Name of product : %s |  Prix : %.3fDH | PrixTTC : %.3fDH \n", product[i].nomP, product[i].prixP, product[i].prixTTC);
		}
	}
	//free(productLocale);
	system("pause");
	
}

void stockStatus( Product *product ){
	//afficher les produit dans la qte et < 3
}

void supplyStock( Product *product, int code, int qte){
	//permet de mettre � jour la quantit� apr�s avoir introduit le code produit et la quantit� � ajouter
}

void deleteProductByCode( Product *product, int code ) {
	// delete product by 
}

void productStatistics( Product *product, int n ){
// Afficher le total des prix des produits vendus en journ�e courante
// Afficher la moyenne des prix des produits vendus en journ�e courante
// Afficher le Max des prix des produits vendus en journ�e courante
// Afficher le Min des prix des produits vendus en journ�e courante

	float totalPrix, moyennePrix, maxPrix, minPrix;
	
}
