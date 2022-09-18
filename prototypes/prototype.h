
//fontions de services
bool productIsExist(int code, Product *product, int *len, int lenAdded);
void getAllProducts( Product *product, int *len );
void addProduct( Product *product, int *len );
void addProducts( Product *product, int *len );
void getAllProductsByNom( Product *product );
void getAllProductsByPrice( Product *product );
void findProductByCode( Product *product,  int code );
void findProductByQte( Product *product,  int qte );
void stockStatus( Product *product );
void supplyStock( Product *product, int code, int qte);
void deleteProductByCode( Product *product, int code );
void productStatistics( Product *product, int n );

//fonction de l'affichage
void printTab();
void nchar(char c, int n);
void topbar();
void menu(Product *product, int *len);
int getInt();
