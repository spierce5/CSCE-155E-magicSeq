#include<stdlib.h>
#include<stdio.h>

/*
* A function to determine if an array of integers is a magic sequence.
* Returns 1 if true and 0 if false.
*/
int isMagicSequence(int length, int *arr){
  int count = 0;
  for(int i=0; i < length; i++){
    if(arr[i] == 0){
      for(int j = i+1; j < length; j++){
        if((arr[j] == (j-i)) || (arr[j] == 0)){
            count = 1;
        }
      }
      if(count == 1){
        for(int j = i-1; j >= 0; j--){
          if((arr[j] == (i-j)) || (arr[j] == 0)){     //FIXME:: 4,3,2,1,0 not working
              count = 1;
          }
          else{
            count = 0;
          }
        }
      }
    }
  }
  return count;
}

int main(){
  int length;
  printf("Enter length of sequence: \n");
  scanf("%d", &length);

  int userSequence[length];
  printf("Enter a sequence of numbers: \n");
  for(int i=0; i < length; i++){
    scanf("%d", &userSequence[i]);
  }

  if(isMagicSequence(length, userSequence) == 1){
    printf("The sequence is a magic sequence\n");
  }
  else{
    printf("The sequence is not a magic sequence\n");
  }

return 0;
}
