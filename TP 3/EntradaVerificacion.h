

/** \brief Allow to introduce an int number and send it to a pointer
 *
 * \param [] char Custom input message, allowing to ask for a cetain data
 * \param [] char Custom error message, in case the inputed value is not an int
 * \param int* Pointer to the variable to store the number inputed
 * \return int Returns 1 if succesfully assigned a value, 0 if it couldn't allocate the number
 *
 */
int ev_InputInt(char [], int*);


/** \brief Allow to introduce a float number and send it to a pointer
 *
 * \param [] char Custom input message, allowing to ask for a cetain data
 * \param [] char Custom error message, in case the inputed value is not an int
 * \param int* Pointer to the variable to store the number inputed
 * \return int Returns 1 if succesfully assigned a value, 0 if it couldn't allocate the number
 *
 */
float ev_InputFloat(char [], float* );

/** \brief Permite ingresar un caracter y validar que se haya ingresado un único caracter
 *
 * \return char Caracter ingresado
 *
 */
char ev_InputChar(char inputMessage[], char errorMessage[], char* number);


/** \brief Allows the user to input an only alphabetic string, formatted to match names.
 *
 * \param [] char Array of characters
 * \param int Array size
 * \param [] char Input message
 * \param [] char Error message (in case the user inputed a digit)
 *
 */
void ev_InputString_Name(char [], int , char [], char []);

/** \brief Valis
 *
 * \param [] char Array a validar
 * \param int Tamaño del array
 * \return La funcion retorna 0 si no encontró ni
 *
 */

void ev_InputString_OnlyText(char [], int , char [], char []);

int ev_ValidateStringOnlyText (char [], int);

void ev_NormalizeText_Name (char [], int );

void ev_Fix_fgets(char [], int );

void ev_NormalizeText (char [], int );

int ev_ValidateIntOverParameter(int , int , char []);

int ev_ValidateFloatOverParameter(float , float , char []);

int ev_InputIntOverParameter(char [], char [], int* , int );

int ev_InputFloatOverParameter(char [], char [], float* , float );

int ev_ValidateString_OnlyNumbers(char [], int stringsize);

void ev_InputString_OnlyNumbers(char [], int , char [], char []);

void ev_InputInt_BetweenTwoNumbers(char inputMessage[], char errorMessage[], int* number, int min, int max);
