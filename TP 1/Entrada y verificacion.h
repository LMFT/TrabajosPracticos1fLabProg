
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



/** \brief Muestra el menu principal de la calculadora
 *
 * \param float Numero A mostrado en el menu para informar al usuario del actual valor del numero
 * \param float Numero B mostrado en el menu para informar al usuario del actual valor del numero
 * \return int  El valor de la variable opcion introducida por el usuario, indicando que opcion quiere que ejecute el programa
 *
 */
int menu(float , float );

/** \brief Verifica si el usuario realiz� un ingreso de datos por primera vez, impidiendo el acceso a las funciones de realizar y mostrar
            calculos
 *
 * \param flag int Bandera que indica si el usuario ingreso datos previamente
 * \param opcion int Opcion elegida por el usuario
 * \return int Retorna 0 si el usuario no ingres� datos previamente. 1 si el usuario ingres� datos previamente o selecciono
            una opcion valida
 *
 */
int verificarPrimerIngreso(int flag, int opcion);

