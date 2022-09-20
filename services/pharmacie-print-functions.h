void nchar(char c, int n){
	while(n--){
		printf("%c", c);
	}
}

void printTab(){
	printf("\t\t\t\t\t\t");
}

int getInt(){
	int n;
	printf("\t\t\t:");
	scanf("%d", &n);
return n;
}

void topbar(){
	
	system("color 7");
	system("cls");
	printf("\n\n");
	printTab();
	
	nchar('-', 18);
	printf("Projet Fin SAS (2022/2023)");
	nchar('-', 18);
	
	printf("\n");
	printTab();
	nchar('-', 21);
	printf("Gestion de Pharmacie");
	nchar('-', 21);
	printf("\n\n\n\n");
}


