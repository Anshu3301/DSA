#include <stdio.h>
#include <string.h>
#include <ctype.h>

char postfix[100];           // Global declaration
int top = -1;


void push(char x){
  postfix[++top] = x;
}


char pop(){
  char x = postfix[top--];
  return x;
  // x = NULL;
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


void InfixToPostfix(char *infix){
  int i=0;
  while(infix[i]!='\0'){

    if(isalnum(infix[i])){           // for alphabets and numbers
      printf("%c",infix[i]);
    }
    else if(infix[i]=='('){         // for opening bracket
      push(infix[i]);
    }
    else if(infix[i]==')'){        // for closing bracket
      while(top != -1 && postfix[top]!='('){
        char x = pop();
        printf("%c",x);
      }
      pop();                      // to pop the '('
    }
    else{                        // for operators
      while(top != -1 && priority(postfix[top])>=priority(infix[i])){
        char x = pop();
        printf("%c",x);
      }
      push(infix[i]);
    }

    i++;
  }
  
  while(top!=-1){                 // printing remaing operators
    char x = pop();
    printf("%c",x);
  }
}


int main() {
  char infix[100];
  printf("Enter Infix Expression:");
  scanf("%s",infix);

  
  printf("Postfix Expression: ");
  InfixToPostfix(infix);
  
  return 0;
}
