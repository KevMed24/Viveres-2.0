void leerDatos(const char *filename, char nombresproduc[][3][30], double precio[], int *n);
void guardarDatos(const char *filename, char nombresproduc[][3][30], double precio[], int n);
void imprimirInventario(char nombresproduc[][3][30], double precio[], int n);
int buscarProductoXNombre(char nombresproduc[][3][30], char nombreAbuscar[], int n);
void imprimirProductoXIndice(char nombreAbuscar[], char nombresproduc[][3][30], double precio[], int index);
void editarProducto(char nombreAbuscar[], char nombresproduc[][3][30], double precio[], int n);
void agregarProducto(char nombresproduc[][3][30], double precio[], int *n);
void eliminarProducto(char nombresproduc[][3][30], double precio[], int *n, char nombreABuscar[]);
