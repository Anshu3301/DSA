#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[100];            // Global declaration
int top=-1;


void push(int x){
  stack[++top]= x;
}

int pop(){                // returns an integer
  return stack[top--];
}

int evaluate(char *postfix){
  int i=0;
  while(postfix[i]!='\0'){
    if(isdigit(postfix[i])){
      push(postfix[i]-'0');   // Converting to int & Push
    }
    else{
      int y = pop();
      int x = pop();
      switch(postfix[i]){
        case '+': {
          printf("x=%d y=%d\n",x,y);
          push(x+y); 
          break;
        }
        case '-': {
          printf("x=%d y=%d\n",x,y);
          push(x-y); 
          break;
        }
        case '*': {
          printf("x=%d y=%d\n",x,y);
          push(x*y); 
          break;
        }
        case '/': {
          printf("x=%d y=%d\n",x,y);
          push(x/y); 
          break;
        }
        case '^': {
          printf("x=%d y=%d\n",x,y);
          push(pow(x,y)); 
          break;
        }
      }
    }
    i++;
  }
  int ans =  pop();    //Popping stack[top] i.e. final answer
  return ans;
}


int main() {

  char postfix[100];
  printf("Enter the Postfix Expression: ");
  scanf("%s",postfix);

  printf("Output: %d",evaluate(postfix));

  return 0;
}
