#include <stdio.h>
#define MAX 10


int main() {

int stk[MAX], top=-1, temp,ch;

    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Peek");
    printf("\n4.Display");
    printf("\n5.Exit");

while(1){
  printf("\n\nEnter your Choice:");
  scanf("%d", &ch);
  
  switch(ch){
    case 1:{ 
     if (top == MAX-1){       //if top was = 0,then check top == MAX
      printf("Stack Overflow!");
     }
     else{
      printf("Enter the data: ");
      scanf("%d", &temp);
      stk[++top] = temp;
      }
      break;
    }
     case 2:{
      if(top == -1){
        printf("Stack Underflow!");
    }
      else{
       printf("Popped Element:%d", stk[top]);
       top--;
    }
    break;
   }
     case 3:{
      if(top == -1){
       printf("Stack is Empty");
     }
     else{
     printf("Top Element:%d", stk[top]);
     }
     break;
    }
     case 4:{
      if(top == -1){
       printf("Empty Stack!");
     }
     else{
      printf("Stack Elements(Top to Bottom):");
       for(int i=top;i>=0;i--){
        printf("%d\t", stk[i]);
       }
     } 
    break;
   }
     case 5:{
      printf("Program Exited!");
      return 0;
    }
     default: printf(" Not a Good Choice!!");
      break;
  }
}

  
return 0;
}
