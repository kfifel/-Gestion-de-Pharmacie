typedef struct Product{
	int codeP;
	char nomP[50];
	int quantiteP;
	float prixP;
	float prixTTC;
}Product;

typedef struct ProduitAcheter {
	Product Produit;
    struct tm date;
}ProduitAcheter;
