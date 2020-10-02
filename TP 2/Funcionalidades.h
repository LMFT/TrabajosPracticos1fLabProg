/** \brief Inicializa un array del tipo int
 *
 * \param int[] Array a inicializar
 * \param int Tamaño del array
 *
 */
void InitializeArrayInt(int[], int);

/** \brief Inicializa un array del tipo float
 *
 * \param float[] Array a inicializar
 * \param int Tamaño del array
 *
 */
void InitializeArrayFloat(float[], int);

/** \brief  Inicializa un array strings
 *
 * \param [][20] char Array a inicializar
 * \param int Tamaño del array
 *
 */
void InitializeArrayString(char [][20], int );

/** \brief Ordena varios arrays paralelos de mayor a menor segun un criterio de ordenamiento
 *
 * \param int[] Array de enteros a ordenar
 * \param float[] Array de flotantes a ordenar
 * \param [20] char[] Array de strings a ordenar
 * \param int Tamaño de los array paralelos. Deben ser iguales
 * \param int Opcion que permite alternar entre qué criterio de ordenamiento aplicar
 * \return void
 *
 */
void ArrangeArraysMax(int[], float[],char[] [20],int, int);

/** \brief Ordena varios arrays paralelos de menor a mayor segun un criterio de ordenamiento
 *
 * \param int[] Array de enteros a ordenar
 * \param float[] Array de flotantes a ordenar
 * \param [20] char[] Array de strings a ordenar
 * \param int Tamaño de los array paralelos. Deben ser iguales
 * \param int Opcion que permite alternar entre qué criterio de ordenamiento aplicar
 * \return void
 *
 */
void ArrangeArraysMin(int [],float [], char [][20], int, int);

/** \brief Ordena varios arrays paralelos de forma alfabética segun un criterio de ordenamiento
 *
 * \param int[] Array de enteros a ordenar
 * \param float[] Array de flotantes a ordenar
 * \param [20] char[] Array de strings a ordenar
 * \param int Tamaño de los array paralelos. Deben ser iguales
 * \param int Opcion que permite alternar entre qué criterio de ordenamiento aplicar
 * \return void
 *
 */
void ArrangeArraysAlphabetical(int [], float [],char [][20], int, int);

/** \brief Permite al usuario realizar otro ingreso de datos
 *
 * \return char Respuesta del usuario
 *
 */
char AnotherInput();

/** \brief Menu principal del programa. Muestra cada opcion principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();

/** \brief Pide confirmacion al usuario antes de realizar una operacion
 *
 * \return int
 *
 */
int Confirmation();


