#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Node* head, int number);
void printTree (Node* head, int indent =0);
Node* search(Node* head, int number, Node* &parent, bool &right);
	     

int main(){
  Node* head = NULL;
  char command[32];
  bool running = true;
  while (running == true){
    cout << "Enter a command: add, search, print, delete, or quit." << endl;
    cin.get(command, 32);
    if (0==strcmp(command, "add")){
      if (head == NULL){
	int number;
	cout << "What number?" << endl;
	cin >> number;
	head = new Node(number);
      }
      else{
	int number;
	cout << "What number?" << endl;
	cin >> number;
	addNode(head, number);
      }
    }
    if (0==strcmp(command, "print")){
      if (head){
	printTree(head);
	}
      else {
	cout <<"There's nothing in the tree." << endl;
      }
    }
    if (0==strcmp(command, "search")){
	if (head){
	  int number;
	  cout << "What number do you want to search?" << endl;
	  cin >> number;
	  Node* parent;
	  bool right;
	}
      }
  }
}

void addNode(Node* head, int number){
  if (number < head->getData()){
    if (head->getLeft()){
      addNode(head->getLeft(), number);
    }
    else{
      head->setLeft(new Node(number));
    }
  }
  if (number > head->getData()){
    if (head->getRight()){
      addNode(head->getRight(), number);
    }
    else{
      head->setRight(new Node(number));
    }
  }
}

void printTree(Node* head, int indent){
  if (head->getRight()){
    printTree(head->getRight(), indent +1);
  }
  for (int i = 0; i <=indent; i++){
    cout << "  ";
  }
  head->getData();
  cout << endl;
  if (head->getLeft()){
    printTree(head->getLeft(), indent + 1);
  }
}

 Node* search(Node* head, int number, Node* &parent, bool &right){
   if (number < head->getData()){
     if (head->getLeft()){
       right = false;
       parent = head;
       return search(head->getLeft(), number, parent, right);
     }
     else return NULL;
   }
   if (number > head->getData()){
     if (head->getRight()){
       right = true;
       parent = head;
       return search(head->getRight(), number, parent, right);
     }
     else return NULL;
   }
   else return head;
}

bool deleteNode(Node* &head, int number){//dont actually delete it though; need to delete head scenario
   Node* parent;
   bool right;
   Node* deleted;
   Node* swap;
   deleted = search(head, number, parent, right);
   if (!deleted){
     return false;
   }
   if(deleted->getLeft() == NULL && deleted->getRight() != NULL){
     swap = deleted->getRight();
     if (right == true){
       parent->setRight(swap);
     }
     if (right == false){
       parent->setLeft(swap);
     }
   }
   if(deleted->getLeft()!= NULL && deleted->getRight() == NULL){
     swap = deleted->getLeft();
     if(right==true){
       parent->setRight(swap);
     }
     if (right==false){
       parent->setLeft(swap);
     }
   }
   if(deleted->getLeft() != NULL && deleted->getRight()!= NULL){

   }
   if (deleted->getLeft() == NULL && deleted->getRight() == NULL){
     swap = NULL;
     if (right == true){
       parent->setRight(swap);
       }
     if (right ==false){
       parent->setLeft(swap);
     }
   } 
   /*else if (!deleted->getLeft()){
     swap = deleted->getRight();
   }
   else if (!deleted->getRight()){
     swap = deleted->getLeft();
   }
   else if (deleted->getLeft()->getRight()){
     Node* current = deleted->getLeft();
     

     }*/
}
