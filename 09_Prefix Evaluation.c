#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[100];    // Globally declared
int top = -1;

void push(int x){
  stack[++top] = x;
}

int pop(){
  return stack[top--];
}

int evaluate(char *prefix){
  int i = strlen(prefix) - 1;
  while(i >= 0){
    if(isdigit(prefix[i])){
      push(prefix[i] - '0');   // converting to int & push
    }
    else{                      // For operator
      int x = pop();
      int y = pop();

      switch(prefix[i]){
        case '+': {
          push(x+y); 
          break;
        }
        case '-': {
          //printf("x=%d y=%d\n",x,y);
          push(x-y); 
          break;
        }
        case '*': {
          //printf("x=%d y=%d\n",x,y);
          push(x*y); 
          break;
        }
        case '/': {
          //printf("x=%d y=%d\n",x,y);
          push(x/y); 
          break;
        }
        case '^': {
          //printf("x=%d y=%d\n",x,y);
          push(pow(x,y)); 
          break;
        }
      }
    }
    i--;
  }
  return pop();          // Popping final Answer i.e. Stack[top]
}


int main() {

  char prefix[100];  
  printf("Enter Prefix Expression: ");
  scanf("%s",prefix);

  printf("Answer: %d",evaluate(prefix));
  
  return 0;
}
