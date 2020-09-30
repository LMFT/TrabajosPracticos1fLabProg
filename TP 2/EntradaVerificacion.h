/** \brief Pide un numero entero al usuario y devuelve ese numero
 *
 * \return int Numero ingresado por el usuario
 *
 */

int pedirNumeroEntero();


/** \brief Pide un numero flotante al usuario y devuelve ese numero
 *
 * \return int Numero ingresado por el usuario
 *
 */
float pedirNumeroFlotante();


/** \brief Verifica si el usuario realizó un ingreso de datos por primera vez, impidiendo el acceso a las funciones de realizar y mostrar
            calculos
 *
 * \param opcion int Opcion elegida por el usuario
 * \param flag int Bandera que indica si el usuario ingreso datos previamente
 * \return int Retorna 0 si el usuario no ingresó datos previamente. 1 si el usuario ingresó datos previamente o selecciono
            una opcion valida
 *
 */
int ValidateInput(int);

/** \brief Permite ingresar datos a un array de enteros
 *
 * \param int Tamaño del array
 * \param [] int Array a cargar
 *
 */
void InputArrayInt(int , int []);

/** \brief Permite ingresar datos a un array de flotantes
 *
 * \param int Tamaño del array
 * \param [] int Array a cargar
 *
 */
void InputArrayFloat(int, float []);


/** \brief
 *
 * \param [] char
 * \param int
 * \return void
 *
 */
void InputString(char [], int );

/** \brief
 *
 * \return char
 *
 */
char InputChar();

int ValidateStringOnlyText (char [], int);
