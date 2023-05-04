/**************************
 *Your name    TJ Heffner       *
 *CPSC2130 Fall 2020            *
 *Lab Section: 3                *
 *UserName:   aheffne           *
 *Instructor:  Dr. Yvon Feaster *
*************************/
#include "functions.h"
#include <stdio.h>

void showBinary(int x){
  char arr[8];
  //This for loop inserts the bits of x by moding by 2 then dividing by 2
  for(int i = 0; i < 8; i++){
    //By starting at index 7, we avoid having the binary backwards
    if(x % 2 == 0){
      arr[7 - i] = '0';
    } else {
      arr[7 - i] = '1';
    }
    x = x / 2;
  }
  //This for loop prints the binary determined in the other loop
  for(int i = 0; i < 8; i++){
    printf("%c", arr[i]);
    if(i == 3){
      printf(" ");
    }
  }
}

void shiftBits(int* c, int* acc, int* q){
  //This division is the same as shifting >> 1
  *q = *q / 2;
  //This if statement determines if there will be a 1 shifted
  //from the lsb of the ACC, then adds it if necessary
  if(*acc % 2 == 1){
    *q = *q + 128;
  }
  //This division is the same as shifting >> 1
  *acc = *acc / 2;
  //This if statment adds 128 to the ACC if there is a 1 in C
  //to simulate shifting from C to ACC
  if(*c == 1){
    *acc += 128;
  }
  //After a shift, C will always equal 0, so this makes sure that is true
  *c = 0;
}

void printLine(int C, int ACC, int Q){
  //This prints the C, ACC, and Q in binary in a line.
  //This code was repeated several times, so I made a function
  printf("%d\t", C);
  showBinary(ACC);
  printf("\t");
  showBinary(Q);
}

void runMultiplication(int C, int ACC, int Q, int M){
  //These printf statements print out the values for C, ACC, Q, and M
  printf("\n");
  printf("M = multiplicand = %d (User specified)\n", M);
  printf("Q = multiplier = %d (User specified)\n", Q);
  printf("C = carry = %d\n", C);
  printf("ACC = accumulator = %d\n", ACC);
  printf("\n");
  //This prints out step 0, showing the initialization of the registers
  printf("STEP 0\t\tInitialize the data M = ");
  showBinary(M);
  printf(" (%d) C = %d ACC = %d Q = ", M, C, ACC);
  showBinary(Q);
  printf(" (%d)\n\n", Q);
  //This for loop is the bulk of the program. It repeats 8 times to
  //fully carry out the mulitplication of an 8 bit integer
  for(int i = 0; i < 8; i++){
    printf("\tC\tACC\t\tQ\n");
    printf("STEP %d\t", i + 1);
    printLine(C,ACC,Q);
    printf("\n");
    //This if statement determines wheter the lsb in Q is 1 or 0
    //then adds to the ACC if necessary.
    //it also prints out whether there is a need to add
    if(Q % 2 == 1){
      printf("\t +\t");
      showBinary(M);
      printf("\t\t lsb = 1 add M to ACC\n");
      ACC += M;
      //This if statement prevents any bit greater than 8 from
      //being set to 1. If it would be, C is set to 1 instead.
      //This is to prevent the shiftBits function from shifting
      //incorrect 1's into existance.
      //It is necessary when keeping each value in its own int
      if(ACC > 255){
        C = 1;
        ACC -= 256;
      }
      printf("\t\t");
    } else {
      printf("\t +\t");
      showBinary(0);
      printf("\t\t lsb = 0 no add to ACC\n");
      printf("\t\t");
    }
    //This for loop prints out the underline for addition
    for(int j = 0; j < 25; j++){
      printf("_");
    }
    //These last print statements print the shifing of everything
    //to the terminal
    printf("\n\t");
    printLine(C,ACC,Q);
    printf("\n");
    printf("\t\t\t\t\t Shift>>1\n\t");
    shiftBits(&C,&ACC,&Q);
    printLine(C,ACC,Q);
    printf("\n\n");

  }
}

void scanNumbers(int* C,int* ACC,int* Q,int* M){
  printf("Please enter a number between 0 and 255\n");
  scanf("%d", M);
  printf("Please enter another number between 0 and 255\n");
  scanf("%d", Q);
  //This while loop makes sure M is 0-255
  while(*M > 255 || *M < 0){
    printf("The first number is out of range. Please enter again\n");
    scanf("%d", M);
  }
  //This while loop makes sure Q is 0-255
  while(*Q > 255 || *Q < 0){
    printf("The second number is out of range. Please enter again\n");
    scanf("%d", Q);
  }
}
