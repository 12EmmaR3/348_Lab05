/* Name: Emma Roy
   Lab number & Section: Lab 05, Friday 1PM
   File Purpose: This file has two given matricies and based on the option given by the user performs certain
   functions such as addition, multipulcation, transposition, and printing
*/

#include <stdio.h>
#define SIZE 5
void add(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
  int result[SIZE][SIZE];   //makes a new 5x5 array
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        result[i][j] = m1[i][j] + m2[i][j];  //puts the added values into their designated place into the array
      }
  }
  printf("Result of addition:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", result[i][j]);  //prints out the array w the added values
    }
    printf("\n");    //each row has its own line
    }
}

void multiply(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
  int result[SIZE][SIZE] = {0}; //array value set to 0
  for (int i = 0; i < SIZE; i++) { //loops needed to iterate through every row & col + adding these values
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {  
        result[i][j] += m1[i][k] * m2[k][j]; //array multipulcation is row*col for the amount of rows/col (in this case 5)
      }
    }
  }
  
  printf("Result of multiplication:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", result[i][j]);   //prints off array with multiplied values
    }
    printf("\n"); //each row has its own line
  }
}

void transpose(int m[SIZE][SIZE]) {
  int result[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result[j][i] = m[i][j];   //the rows are now columns and the columns are now the rows
      }
  }
  
  printf("Transposed matrix:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", result[i][j]);  //prints out the now transposed matrix
      }
    printf("\n");
  }
}

void print_m(int m[SIZE][SIZE]) {
  printf("Original Matrix:\n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", m[i][j]);   //prints out the original inputted matrix
      }
    printf("\n");
  }
}

int main() {
  int m1[SIZE][SIZE] = {   //initalizes the first matrix
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };
  int m2[SIZE][SIZE] = {   //initalizes the second matrix
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
  };

  printf("Menu:\n1) Add Matrices\n2) Multiply Matrices\n3) Transpose Matrices\n4) Print Matrices\n");
  printf("Enter your choice: ");  //accepts user input
    
  int user_choice;
  scanf("%d", &user_choice);
  
  if (user_choice == 1) {  //calls add function
    add(m1, m2);
  } else if (user_choice == 2) { //calls multipulcation function
    multiply(m1, m2);
  } else if (user_choice == 3) {  //calls transpose function
    printf("Transposed matrix of m1:\n");
    transpose(m1);
    printf("Transposed matrix of m2:\n");
    transpose(m2);
  } else if (user_choice == 4) {  //calls print function
    print_m(m1);
    print_m(m2);
  } else {   //if the user enters an option that isn't the given 1-4
    printf("Invalid option\n");
  }
    
  return 0;
}