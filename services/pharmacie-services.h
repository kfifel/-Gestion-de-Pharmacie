//    ------------------- Functions of  the projet -------------------    
   
bool productIsExist(int code, Product *product, int lenc){
	printf("\n\ti'm in\n");
	int i, exist = 0;
	for( i = 0; i < lenc; i++){
		if( product[i].codeP == code) exist = 1;
	}
	return exist? true : false;
}

void getAllProducts( Product *product ){
	
	printf("%x", product);
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

//		               
//Product *addProduct( Product *product, int *len ){
//	bool exist;
//	*len = *len + 1;
//	product = realloc ( product, *len * sizeof( *product ) );
//	
//	Product *pProduct;
//	pProduct = product + ( *len - 1 );
//	do{
//		printTab();
//		printf("Saisez le Code de produit :  ");
//		scanf("%d", &pProduct->codeP);
//		
//		exist = productIsExist( pProduct->codeP, product, len, 1 );
//		
//		printTab();
//		if( exist ) printf("Product with code : %d deja exister ...\n", pProduct->codeP);
//		
//	}while( exist );
//	
//	printf("Saisez le Nom de produit : ");
//	scanf("%s", &pProduct->nomP);
//	
//	printTab();
//	printf("Saisez la Quantite de produit : ");
//	scanf("%f", &pProduct->quantiteP);
//	
//	printTab();
//	printf("Saisez le Prix de produit : ");
//	scanf("%f", &pProduct->prixP);
//	
//	pProduct->prixTTC = pProduct->prixP + pProduct->prixP * 15 / 100;
//	
//	printTab();
//	printf("save with success\n");
//	pProduct= pProduct-(*len-1);
//	//free(pProduct);
//	system("pause");
//	return product;
//}

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
		system("pause");
	}
	return product;
}

void getAllProductsByNom( Product *product ){
	
}

void getAllProductsByPrice( Product *product ){
	
}

void buyProduct( Product Product, int qte ) {
	
}

void findProductByCode( Product *product,  int code ){
	
}


void findProductByQte( Product *product,  int qte ){
	
}

void stockStatus( Product *product ){
	//afficher les produit dans la qte et < 3
}

void supplyStock( Product *product, int code, int qte){
	//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à ajouter
}

void deleteProductByCode( Product *product, int code ) {
	// delete product by 
}

void productStatistics( Product *product, int n ){
// Afficher le total des prix des produits vendus en journée courante
// Afficher la moyenne des prix des produits vendus en journée courante
// Afficher le Max des prix des produits vendus en journée courante
// Afficher le Min des prix des produits vendus en journée courante

	float totalPrix, moyennePrix, maxPrix, minPrix;
	
}
