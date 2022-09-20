
//fontions de services
bool productIsExist(int code, Product *product, int len);
void getAllProducts( Product *product );
Product * addProduct( Product *product );
Product * addProducts( Product *product );
void getAllProductsByNom( Product *product );
void getAllProductsByPrice( Product *product );
int getIndexOfProduct( Product *product, int code );
void findProductByCode( Product *product );
void findProductByQte( Product *product );
void stockStatus( Product *product );
void supplyStock( Product *product );
void deleteProductByCode( Product *product, int code );
float getPrixTTCProductVendu(Product *product ,int code);
void productStatistics( ProduitAcheter *product );

//fonction de l'affichage
void printTab();
void nchar(char c, int n);
void topbar();
void menu(Product *product, int *len);
int getInt();
