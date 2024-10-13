#define SIZE 5
int main() {
int m1[SIZE][SIZE] = {
  {1, 2, 3, 4, 5},
  {6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15},
  {16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25}
  };
  int m2[SIZE][SIZE] = {
  {25, 24, 23, 22, 21},
  {20, 19, 18, 17, 16},
  {15, 14, 13, 12, 11},
  {10, 9, 8, 7, 6},
  {5, 4, 3, 2, 1}
  };

  printf("Menu:\n1)Add Matricies\n2)Multiply Matricies\n3)Transpose Matricies\n4)Print Matricies");
  printf("\n\nEnter your choice: ");
  int user_choice;
  scanf("%d",&user_choice);
  if(user_choice == 1){
    add(m1,m2);
  }else if(user_choice == 2){
    multiply(m1, m2);
  }else if(user_choice == 3){
    transpose(m1,m2)
  }else if(user_choice == 3){
    continue;
  }else{
    printf("Invalid option")
  }
  return 0;
}

int add(m1, m2){
  int result[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }

int multiply(m1, m2){
  continue;
  }

void transpose(m1, m2){
  continue;
  }
}
