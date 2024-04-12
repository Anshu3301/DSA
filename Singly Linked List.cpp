#include <stdio.h>
#include <string.h>

struct node{
int data;
struct node *next;
};                    
struct node *head=NULL;            // Global Declaration


struct node *create_node(){       // as it returns value of struct node type
  struct node *h1;
  h1 = (struct node *)malloc(sizeof(struct node));  // Pointer stores address of new allocated memory for new node
  
  printf("Enter the value to be inserted: ");
  scanf("%d",&h1->data);
    
  h1->next = NULL;
  return h1;
}


void inBegin(){            // Insertion at Begining
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head=k1;
  }
  else{
    k1->next = head;
    head = k1;
  }
}


void inMiddle(){          // Insertion in middle
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head=k1;
  }
  else {
   /* int position;      // At a specific Position 
    printf("Insert at which position (1 based indexing)?: ");
    scanf("%d",&position);

    struct node *temp = head;
    int i = 0;
    while(i<position-2){
      temp = temp->next;
      i++;
    }
    k1->next = temp->next;
    temp->next = k1;    */

    
    int value;      // Before a Element
    printf("Insert before which value?: "); 
    scanf("%d",&value);

    struct node *temp = head;
    while(temp->next->data!=value){
      temp = temp->next;
    }
    k1->next = temp->next;
    temp->next = k1;
  } 
}


void inEnd(){            // Insertion at End
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head=k1;
  }
  else {
   struct node *temp;
   temp = head;      

    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = k1;
  }
}


int delBegin(){           // Delete from Begining
  if(head==NULL){
    printf("List is empty");
  }
  else{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
  }
}


int delMiddle(){          // Delete from Middle
  if(head==NULL){
    printf("List is empty");
  }
  else{
    if(head->next==NULL){   // i.e. only one element in list
      free(head);
      head = NULL;
    }
    else{
     int value;      // Delete a Element
     printf("Element to be deleted: "); 
     scanf("%d",&value);

     struct node *temp = head;

     while(temp->next->data!=value){
       temp = temp->next;
     }
     struct node *d1 = temp->next;
     temp->next =  d1->next;  // or, temp->next->next;
     free(d1);
  }
 }
}


int delEnd(){             // Delete from End
  if(head==NULL){
    printf("List is empty");
  }
  else{
    if(head->next==NULL){   // i.e. only one element in list
      free(head);
      head = NULL;
    }
    else{
     struct node *temp;
     temp = head;

     while(temp->next->next!=NULL){
      temp = temp->next;
     }

     struct node *temp2;
     temp2 = temp->next;
     temp->next = NULL;
     free(temp2);
    }
  }
}


int display(){               // Display the Elements
  if(head==NULL){
    printf("List is empty. Nothing to Display!");  // Checks if list is empty
  }
  else{
    printf("The elements in the Linked List: ");

    struct node *temp;
    temp = head;         // Temporary pointer to traverse the list

    while(temp!= NULL){
      printf("%d\t",temp->data);
      temp = temp->next;
    }
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
