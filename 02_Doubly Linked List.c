#include <stdio.h>

struct node{
 struct node *prev;
 int data;
 struct node *next;
};                    
struct node *head=NULL;            // Global Declaration


struct node *create_node(){       // as it returns value of struct node type
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));  

  printf("Enter the value to be inserted: ");
  scanf("%d",&newnode->data);

  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}


void inBegin(){                  // Insertion at Begining
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head = k1;
  }
  else{
    k1->next = head;
    head->prev = k1;
    head = k1;
  }
}


void inMiddle(){             //Insertion in middle (Position wise)
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head = k1;
  }
  else{
    int pos;
    printf("Enter the position(1 based indexing): ");
    scanf("%d",&pos);

    struct node *temp = head;
    int i = 0;
    while(i<pos-2){
      temp = temp->next;
      i++;
    }
    k1->next = temp->next;
    k1->prev = temp;
    k1->next->prev = k1;
    temp->next = k1;
  } 
}


void inEnd(){                 // Insertion at End
  struct node *k1; 
  k1 = create_node();

  if(head==NULL){
    head = k1;
  }
  else{
    struct node *temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = k1;
    k1->prev = temp;
  } 
}


int delBegin(){                  // Delete from Begining
  if(head==NULL){
    printf("List is empty. Nothing to Delete!");
  }
  else{
    if(head->next==NULL){
      struct node *temp = head;
      head = NULL;
      free(temp);
    }
    else{
      struct node *temp = head;
      head = temp->next;
      head->prev = NULL;
      free(temp);
    }
  }
}


int delMiddle(){                 // Delete from Middle
  if(head==NULL){
    printf("List is empty. Nothing to Delete!");
  }
  else{
    if(head->next==NULL){         // i.e. only 1 node is present
      struct node *temp = head;
      head = NULL;
      free(temp);
    }
    else{
      int val;
      printf("Value to be deleted: ");
      scanf("%d",&val);

      struct node *temp = head;
      while(temp->next->data != val){
        temp = temp->next;
      }
      struct node *d1 = temp->next;
      temp->next = d1->next;
      d1->next->prev = temp;
      free(d1); 
    }
  }
}


int delEnd(){                    // Delete from End
  if(head==NULL){
    printf("List is empty. Nothing to Delete!");
  }
  else{
    if(head->next==NULL){        // i.e. only 1 node is present
      head = NULL;
    }
    else{
      struct node *temp;
      while(temp->next->next!=NULL){
        temp = temp->next;
      }
      struct node *d1=temp->next;
      d1->prev=NULL;
      temp->next = NULL;
      free(d1);
    }
  }
}


int display(){               // Display the Elements

  if(head==NULL){
    printf("List is Empty!");
  }
  else{
    struct node *temp  = head;
    printf("List elements are: ");
    while(temp != NULL){
      printf("%d\t",temp->data);   // Printing
      temp = temp->next;
    }
    // while(temp->prev != NULL){
    //   printf("%d\t",temp->data);   // Printing in Reverse
    //   temp = temp->prev;
    // }
  }
}



int main() {

  printf("1.Insert at Begining.");
  printf("\n2.Insert at Middle.");
  printf("\n3.Insert at End.");
  printf("\n4.Delete from Begining.");
  printf("\n5.Delete from Middle.");
  printf("\n6.Delete from End.");
  printf("\n7.Display.");
  printf("\n8.Exit.");

  int choice;

  while(choice!=8){
    printf("\n\nEnter choice:");
    scanf("%d",&choice);

    switch(choice){
      case 1: {
        inBegin();
        break;
      }
      case 2: {
         inMiddle();
         break;
       }
      case 3: {
        inEnd();
        break;
      }
      case 4: {
        delBegin();
        break;
      }
      case 5: {
        delMiddle();
        break;
      }
      case 6: {
        delEnd();
        break;
      }
      case 7: {
        display();
        break;
      }
      case 8: {
        printf("Program Exited!");
        return 0;
      }
      default:{
        printf("Invalid choice");
        break;
      }
    }
  }

  return 0;
}
