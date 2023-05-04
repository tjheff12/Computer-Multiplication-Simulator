/**************************
 *Your name    TJ Heffner       *
 *CPSC2130 Fall 2020            *
 *Lab Section: 3                *
 *UserName:   aheffne           *
 *Instructor:  Dr. Yvon Feaster *
*************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/* Parameters: int - the number in which you want to show the last 8 bits of
 * Return:  This function returns nothing, but prints out the last 8 bits of
 * the int x, leaving as space between the 4th and 5th bit
 */
void showBinary(int x);
/* Parameters: int* - the address of the C (carry) in the program
 * Parameters: int* - the address of the ACC (accumulator) in the program
 * Parameters: int* - the address of the Q (multiplier) in the program
 * Return:  This function returns nothing, but shifts the bit of the C, ACC,
 * and Q in a way that each adds up to how the simulated registers would act
 * in the computer. There is no pass by reference in C, so we use pointers instead
 */
void shiftBits(int*, int*, int*);
/* Parameters: int - the C (carry) in the program
 * Parameters: int - the ACC (accumulator) in the program
 * Parameters: int - the Q (multiplier) in the program
 * Return:  This function returns nothing, but prints out the C, ACC, and Q
 * in binary in a way that is formated to keep each number distinct
 */
void printLine(int, int, int);
/* Parameters: int - the C (carry) in the program
 * Parameters: int - the ACC (accumulator) in the program
 * Parameters: int - the Q (multiplier) in the program
 * Parameters: int - the M (multiplicand) in the program
 * Return:  This function returns nothing, but prints the simulated registers of
 * how a computer would preform a mulitplication problem.
 */
void runMultiplication(int,int,int,int);
/* Parameters: int* - the address of the C (carry) in the program
 * Parameters: int* - the address of the ACC (accumulator) in the program
 * Parameters: int* - the address of the Q (multiplier) in the program
 * Parameters: int* - the address of the M (multiplicand) in the program
 * Return:  This function returns nothing, but instead asks the user for
 * input on what Q and M should be, then validates the input is 0-255 for each.
 */
void scanNumbers(int*,int*,int*,int*);
#endif
