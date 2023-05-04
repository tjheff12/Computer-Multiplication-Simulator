/**************************
 *Your name    TJ Heffner       *
 *CPSC2130 Fall 2020            *
 *Lab Section: 3                *
 *UserName:   aheffne           *
 *Instructor:  Dr. Yvon Feaster *
*************************/
#include <stdio.h>
#include "functions.h"
int main(){

  int M;
  int Q;
  int C = 0;
  int ACC = 0;


  scanNumbers(&C, &ACC, &Q, &M);

  runMultiplication(C, ACC, Q, M);


  return 0;

}
