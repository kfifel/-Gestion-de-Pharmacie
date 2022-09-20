
//fontions de services
bool productIsExist(int code, Product *product, int len);
void getAllProducts( Product *product );
void getAllProductsVendu( ProduitAcheter *product );
Product * addProduct( Product *product );
Product * addProducts( Product *product );
void getAllProductsByNom( Product *product );
void getAllProductsByPrice( Product *product );
int getIndexOfProduct( Product *product, int code );
void findProductByCode( Product *product );
void findProductByQte( Product *product );
void stockStatus( Product *product );
void supplyStock( Product *product );
void deleteP(Product *product);
void deleteProductByCode( Product *product, int indexP );
float getPrixTTCProductVendu(Product *product ,int code);
void productStatistics( Product *product, ProduitAcheter *productVendu );
void historyProductVendu( Product *product, ProduitAcheter *productVendu );
Product findProduct( Product *product, int codeP );

//fonction de l'affichage
void printTab();
void nchar(char c, int n);
void topbar();
void menu(Product *product, int *len);
int getInt();
void production();
