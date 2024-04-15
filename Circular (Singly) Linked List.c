#include <stdio.h>

struct node{
 int data;
 struct node *next;
};                    
struct node *head=NULL;            // Global Declaration


struct node *create_node(){       // as returns value of struct node type
  struct node *h1;
  h1 = (struct node *)malloc(sizeof(struct node));  

  printf("Enter the value to be inserted: ");
  scanf("%d",&h1->data);

  h1->next = NULL;
  return h1;
}


void inBegin(){                  // Insertion at Begining
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head = k1;
    head->next = head;
  }
  else{
    k1->next = head;
    struct node *temp = head;
    
    while(temp->next != head){
      temp = temp->next;
    }
    temp->next = k1;
    head = k1;
  }
}


void inMiddle(){             //Insertion in middle (Position wise)
  struct node *k1;
  k1 = create_node();

  if(head==NULL){
    head = k1;
    k1->next = head;
  }
  else{
    int pos;
    printf("Enter the position(1 based Indexing): ");
    scanf("%d",&pos);

    struct node *temp = head;
    int i=0;
    while(i<pos-2){
      temp = temp->next;
      i++;
    }
    k1->next = temp->next;
    temp->next = k1;  
  }
}


void inEnd(){                 // Insertion at End
  struct node *k1; 
  k1 = create_node();

  if(head==NULL){
    head = k1;
    k1->next = head;
  }
  else{
    if(head->next == head){   // only 1 node present
      head->next = k1;
      k1->next = head;
    }
    else{
      struct node *temp = head;
      while(temp->next!=head){
        temp = temp->next;
      }
      temp->next = k1;
      k1->next = head;
    }
    
  }
}


void delBegin(){                  // Delete from Begining
  if(head==NULL){
    printf("List is empty");
  }
  else{                         
    if(head->next==head){       // 1 element Present
      struct node *temp = head;
      head = NULL;
      free(temp);
    }
    else{
      struct node *temp = head;
      struct node *temp1 = head;
      while(temp1->next != head){
        temp1 = temp1->next;
      }
      temp1->next = head->next;
      head = head->next;
      free(temp);
    }  
  }
}


void delMiddle(){                 // Delete from Middle
   if(head==NULL){
    printf("List is empty");
  }
  else{
    if(head->next==head){       // 1 element Present
      struct node *temp = head;
      head = NULL;
      free(temp);
    }
    else{
      /* int pos;                   // Position Wise deletion
      printf("Position to be Deleted(1 based Indexing): ");
      scanf("%d",&pos);

      struct node *temp = head;
      int i=0;
      while(i<pos-2){
        temp = temp->next;
        i++;
      }

      struct node *d1 = temp->next;
      temp->next = d1->next;
      d1->next = NULL;
      free(d1);   */


      int val;                    // Value Wise Deletion
      printf("Enter the value to be deleted: ");
      scanf("%d",&val);

      struct node *temp = head;
      while(temp->next->data != val){
        temp = temp->next;
      }
      struct node *d1 = temp->next;
      temp->next = d1->next;
      d1->next = NULL;
      free(d1);
      
    }   
  } 
}


void delEnd(){                    // Delete from End
  if(head==NULL){
    printf("List is empty");
  }
  else{
    if(head->next==head){
      struct node *temp = head;
      head = NULL;
      free(temp);
    }
    else{
      struct node *temp = head;
      while(temp->next->next != head){
        temp = temp->next;
      }
      struct node *d1 = temp->next;
      temp->next = head;
      d1->next = NULL;
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
    
    while(temp->next != head){
      printf("%d\t",temp->data);  
      temp = temp->next;
    }
    printf("%d\t",temp->data);
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
