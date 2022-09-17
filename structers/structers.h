typedef struct Produit{
	int codeP;
	char *nomP;
	int quantiteP;
	float prixP;
	float prixTTC;
}Produit;

typedef struct ProduitAcheter {
	Produit Produit;
    struct tm date;
};
