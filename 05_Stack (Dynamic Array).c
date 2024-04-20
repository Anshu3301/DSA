
#include <stdio.h>

struct stack{
   int top;
   int size;
   int *arr;
};

void push(struct stack *stk,int data){
  if(isFull(stk)){
    printf("Stack Overflow!!\n");
  }
  else{
    stk->top++;
    stk->arr[stk->top]=data;
  } 
}


void pop(struct stack *stk){
   if(isEmpty(stk)){
     printf("Stack Underflow!!\n");
   }
  else{
    int data=stk->arr[stk->top];
    printf("Popped element: %d\n",data);
    stk->top--;
  }
}


int peek(struct stack *stk){
  if(isEmpty(stk)){
     printf("Stack Empty!\n");
   }
  else{
    printf("Top element: %d\n",stk->arr[stk->top]);
  }
}


int isFull(struct stack *stk){
  if(stk->top==stk->size-1){
    return 1;
  }
  else{
    return 0;
  }  
}


int isEmpty(struct stack *stk){
  if(stk->top==-1){
    return 1;
  }
  else{
    return 0;
  }  
}


void display(struct stack *stk){
  if(isEmpty(stk)){
    printf("Stack is Empty!\n");
  }
  else{
    printf("Stack elements(Top->Bottom): ");
    for(int i=stk->top;i>=0;i--){
      printf("%d\t",stk->arr[i]);
    }
  }
}


int main() {

  struct stack *stk = (struct stack*)malloc(sizeof(struct stack));

  stk->top = -1;
  printf("Enter Max Size of stack: ");
  scanf("%d", &stk->size);

  stk->arr = (int*)calloc(stk->size,sizeof(int));


   printf("\n1.Push");
   printf("\n2.Pop");
   printf("\n3.Peek");
   printf("\n4.Display");
   printf("\n5.Exit");

  int ch;
  while(1){
    printf("\n\nEnter your Choice:");
    scanf("%d", &ch);

    switch(ch){
      case 1:{ 
        int data;
        printf("Enter the data:");
        scanf("%d", &data);
        push(stk,data);
        break;
      }
      case 2:{
       pop(stk);
       break;
      }
      case 3:{
        peek(stk);
        break;
      }
      case 4:{
       display(stk);
       break;
      }
      case 5:{
       printf("Program Exited!");
       return 0;
       break;
      }
      deafult:{
        printf("Invalid Choice");
      }
    }
  }
  
  return 0;
}
