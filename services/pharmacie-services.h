//    ------------------- Functions of  the projet ------------------- 
   
// fonction predefinie to use it in sort
int compare(const void *x_void, const void *y_void)
{
  int x = *(int *)x_void;
  int y = *(int *)y_void;
  return y - x;
}
   
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
		printf("Name of product : %8s |  Prix : %.3fDH | PrixTTC : %.3fDH \n", product[i].nomP, product[i].prixP, product[i].prixTTC);
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
	sleep(2);
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
  qsort( product, len, sizeof(Product), compare);
  getAllProducts(product);
}

int getIndexOfProduct( Product *product, int code ){
	int i;
	for( i = 0; i < len; i++){
		if(product[i].codeP == code ) return i;
	}
 return -1;	
}

void buyProduct( Product *product, ProduitAcheter *productToBuy ) {
	int n = lenBuy, codeP, indexP, i, qte;
	bool exist;
	productToBuy = realloc ( productToBuy , ++lenBuy * sizeof(ProduitAcheter));
	printTab();
	printf("Choisi Le Code De Product Que Vous Acheter: \n");
	for( i = 0; i < len; i++) {
		printTab();
		printf("Code De Produit : %d |  Name Of Product : %s |  Prix : %.3fDH | PrixTTC : %.3fDH \n", product[i].codeP, product[i].nomP, product[i].prixP, product[i].prixTTC);
	}
	do{
		codeP = getInt();
		exist = productIsExist(codeP, product, len );
		if( !exist ) printf("Produit n'est pas dans la list");
	}while( !exist );
	
	printTab();
	printf("Donner La Quantite Acheter :");
	scanf("%d", &qte );
	
	indexP = getIndexOfProduct(product, codeP);
	printf("index  = %d ", indexP);
	
	if( product[indexP].quantiteP > qte){
		product[indexP].quantiteP -= qte; // - la qte acheter
		
		productToBuy[n].quantiteP = qte;
		productToBuy[n].codeP = codeP;
		productToBuy[n].prixTTC = product[indexP].prixTTC;
		
		//definier le temps
		time_t rawtime;
	    time( &rawtime );
		productToBuy[n].date = localtime( &rawtime );
		
		printTab();
		printf("Bien Enregistrer .\n");
		sleep(2);
	}else{		
		printTab();
		printf("Stock est insuffisant .!");
		sleep(4);
	}
	
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
	 int i, exist=0;
	
   	 topbar();
	 printTab();
	 printf(" ---  les produits dont la quantite est inferieure a 3  ---\n\n\n\n");
	 for(i = 0; i < len; i++ ) {
	 	if( product[i].quantiteP < 3){
	 		
	 		printTab();
	 		printf("Name of product : %s | Prix : %.3fDH | PrixTTC : %.3fDH "
				   "\n", product[i].nomP, product[i].prixP, product[i].prixTTC);
				   exist++;
		 }
	 }
	 if(!exist) {
	 	printTab();
	 	printf("Aucun Produits a une quantite inferieur a 3\n\n");
	 }
	 printTab();
	 system("pause");
	 
}

void supplyStock( Product *product){
	//permet de mettre à jour la quantité après avoir introduit le code produit et la quantité à ajouter
	int i, qte, codeP, exist, indexP;
	topbar();
	printTab();
	printf("--- mettre à jour le Stock ---\n\n\n");
	printTab();
	printf("    Choisir Le Code De Product Concernant: \n");
	for( i = 0; i < len; i++) {
		printTab();
		printf("Code De Produit : %d |  Name Of Product : %s |  Quantite : %d | PrixTTC : %.3fDH \n", product[i].codeP, product[i].nomP, product[i].quantiteP, product[i].prixTTC);
	}
	
	do{
		codeP = getInt();
		exist = productIsExist(codeP, product, len ); //tester si le code de produit saisir est dans la list;
		if( !exist ) printf("Produit n'est pas dans la list");
	}while( !exist );
	
	printTab();
	printf("Donner La Quantite A Ajouter :");
	scanf("%d", &qte );
	
	indexP = getIndexOfProduct(product, codeP);//get index de  Produit selectionnee
	
	product[indexP].quantiteP += qte;
	printTab();
	printf("Bien mettre à jouree ");
	sleep(3);
}

void deleteProductByCode( Product *product, int code ) {
	// delete product by 
}

float getPrixTTCProductVendu(Product *product ,int code){
	int i;
	for( i = 0; i < len; i++) {
		if(product[i].codeP == code ) return product[i].prixTTC;
	}
	
	return 0;
}

void productStatistics( Product *product, ProduitAcheter *productVendu ){
// Afficher le total des prix des produits vendus en journée courante
// Afficher la moyenne des prix des produits vendus en journée courante
// Afficher le Max des prix des produits vendus en journée courante
// Afficher le Min des prix des produits vendus en journée courante
	time_t t;
	time(&t);
	struct tm *timecurrent = localtime( &t );
	float totalPrixDay=0, moyennePrixDay, maxVenduDay, minVenduDay, prixTTC;
	int i, count;
	maxVenduDay = 0;
	minVenduDay = 100;
	for( i = 0; i < lenBuy; i++ ) {
		if( productVendu[i].date->tm_mday == timecurrent->tm_mday && productVendu[i].date->tm_mon == timecurrent->tm_mon && productVendu[i].date->tm_year == timecurrent->tm_year ){
			prixTTC = getPrixTTCProductVendu( product, productVendu[i].codeP ); // get prix TTC
			totalPrixDay += prixTTC * productVendu[i].quantiteP; 
			if( maxVenduDay < productVendu[i].prixTTC ){
				maxVenduDay = productVendu[i].prixTTC;
			}
			if( maxVenduDay > productVendu[i].prixTTC ){
				minVenduDay = productVendu[i].prixTTC;
			}
			count++;
		}
	}
	moyennePrixDay = totalPrixDay / count;
	printTab();
	printf("Min : %.3f; Max : %3.f \n", minVenduDay, maxVenduDay);
	printf("Total Prix : %.3f; Moyenne Prix : %.3f \n", totalPrixDay, moyennePrixDay );
	system("pause");
}

Product findProduct( Product *product, int codeP ){
	Product productFound;
	int index, i;
    index = getIndexOfProduct( product,  codeP );
    for( i = 0; i < len; i++){
    	if( product[i].codeP == codeP ){
    		productFound = product[i];
    		break;
		}
	}
return 	productFound;
}

void historyProductVendu( Product *product, ProduitAcheter *productVendu ){
	int i;
	Product productFound;
	for( i = 0; i < lenBuy ; i++ ){
		productFound = findProduct( product, productVendu[i].codeP );
		printTab();
		printf("Nom de Produit : %s  |  Quantite : %d  ", productFound.nomP, productVendu[i].quantiteP );
		printf("|  PrixTTC : %.3f  |  Date : %d:%d:%d  %d/%d/%d\n", productVendu[i].prixTTC, productVendu[i].date->tm_hour, productVendu[i].date->tm_min, productVendu[i].date->tm_sec, productVendu[i].date->tm_yday, productVendu[i].date->tm_mon, productVendu[i].date->tm_year  );
	}
	
	system("pause");
}
