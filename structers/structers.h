typedef struct Product{
	float prixTTC;
	int codeP;
	char nomP[50];
	int quantiteP;
	float prixP;
}Product;

typedef struct ProduitAcheter {
	int codeP;
	int quantiteP;
    struct tm *date;
}ProduitAcheter;
