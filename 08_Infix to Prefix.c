
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char prefix[100];  //Global Declaration
int top=-1;
char output[100];  //Storing the Final Output
int top2=-1;


void push_output(char c){
  output[++top2]=c;
}


void push(char c){
  prefix[++top]=c;
}

char pop(){
  char x = prefix[top--];
  return x;
}

int priority(char operator){
  switch (operator) {
      case '+':
      case '-':
          return 1;
      case '*':
      case '/':
          return 2;
      case '^':
          return 3;
      default:                    
          return 0;
  }
}

void InfixToPrefix(char *infix){
  int i = strlen(infix)-1;          //Starting from end index
  while(i>=0){
    if(isalnum(infix[i])){
      push_output(infix[i]);        //Pushing operands into Output Stack
    }
    else if(infix[i] == ')'){
      push(infix[i]);
    }
    else if(infix[i] == '('){
      while(top!=-1 && prefix[top] != ')'){
        push_output(pop());        //Pushing into Output Stack
      } 
      pop();                      // popping the ')'
    }
    else{                         // for operators
      while(top!=-1 && priority(prefix[top])>priority(infix[i])){
        push_output(pop());
      }
      push(infix[i]);
    }
    i--;
  }
  while(top!=-1){
    push_output(pop());           //Pushing remaining operators
  }
}


void display(char *str){         // Printing in Reversed Order
  int i=strlen(str)-1;
  while(i>=0){
    printf("%c",str[i--]);
  }
}

int main(void) {

  char infix[100];
  printf("Enter Infix expression: ");
  scanf("%s",infix);

  InfixToPrefix(infix);
  printf("Prefix Expression: ");
  display(output);
  
  return 0;
}
