//Sanil Hattangadi March 24,17
//the program creates a binary search tree that allows for one to add, delete, and search for numbers
#include <cstring>
#include <iostream>
#include "Node.h"
#include <fstream>

using namespace std;

//methods that i use
void addNode(Node* head, int number, Node* &thead);
void printTree (Node* head, int indent =0);
Node* search(Node* head, int number, Node* &parent, bool &right);
bool deleteNode(Node* &head, int number);
void checkInput(ifstream &stream, bool &isFile);//checks if the input is file or input
void addNumbers(istream &from, Node* &head);

int main(){
  Node* head = NULL;//set the head to null
  char command[32];
  bool running = true;
  while (running == true){//while the user wants to play
    cout << "Enter a command: add, search, print, delete, or quit." << endl;
    cin.get(command, 32);
    cin.ignore();
    if (0==strcmp(command, "add")){//if user types in command, add
      ifstream stream;//create the variable
      bool isFile;
      checkInput(stream, isFile);//run checkInput
      addNumbers(isFile ? stream: cin, head);//run add to heap
      if (isFile) stream.close();//if its a file, do this
      cin.ignore();
      /* if (head == NULL){//if first number in the tree is added
	int number;
	cout << "What number?" << endl;
	cin >> number;
	cin.ignore();
	head = new Node(number);//create the node
      }
      else{//if there is stuff in the tree
	int number;
	cout << "What number?" << endl;
	cin >> number;
	cin.ignore();
	addNode(head, number);//run addNode
	}*/
    }
    if (0==strcmp(command, "print")){//if user types print
      if (head){//if head is not null
	//cout << "Hi" << endl;
	printTree(head);//print
	}
      else {//if nothing in the tree
	cout <<"There's nothing in the tree." << endl;
      }
    }
    if (0==strcmp(command, "search")){//if the want to search
      if (head){//if head is not null
	  int number;
	  cout << "What number do you want to search?" << endl;
	  cin >> number;
	  cin.ignore();
	  Node* parent;//create variables
	  bool right;
	  if(search(head, number, parent, right)){//run search and if found
	    cout <<"The number:" << number << " is in the tree." << endl;
	  }
	  else{//its no in tree
	    cout << "The number: " << number << "is not in the tree." << endl;
	  }
	}
      else {//if nothing in tree
	  cout << "There's nothing in the tree." << endl;
	}
      }
    if (0==strcmp(command, "quit")){//if they type quit
      running = false;//end program
    }
    if (0==strcmp(command, "delete")){//if the type delete
      if (head){//head is not null
	int number;
	cout << "What number are you trying to delete?" << endl;
	cin >> number;
	cin.ignore();
	if(deleteNode(head, number)){//if its in the tree; its deleted
	  cout << "The number: " << number << " is deleted." << endl;
	}
	else{//not found in the tree and not deleted
	  cout << "The number: " << number << " is not in the tree." << endl;
	}
      }
      else{//nothings in tree
	cout << "There's nothing in the tree." << endl;
      }
    }
  }
}

void checkInput(ifstream &stream, bool &isFile){ //checks if the input is file or input
  char input[128];
  isFile = false;
  cout << "Do you want to read from a file or input your own text?(file or input)" << endl;//check how it will be inputted
  cin.getline(input,128);
  if (0== strcmp(input, "file")){//if file and input are equal
    char name[128];
    cout << "What file?" << endl;
    cin.getline(name, 128);//get the name of the file
    stream.open(name);//try to open it
    if(stream.is_open()){//if it opends, there is a file
      isFile = true;
      cout << "Thanks. Enter a command above." << endl;
    }
    else {
      cout << "The file could not be opened" << endl;
    }
  }
  if (0==strcmp(input, "input")){
    cout << "Enter the numbers please." << endl;
  }
}

void addNumbers(istream &from, Node* &head){//adds numbers to the input and then puts into nodes
  int newInput;
  from >> newInput;//take in number
  addNode(head,newInput,head);//add it to the node
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){//
      from >> newInput;
      addNode(head,newInput,head);//add to node
    }
    else{
      from.ignore();
    }
  }
}

void addNode(Node* head, int number, Node* &thead){//method for adding nodes using recursion
  if (thead == NULL){
    thead = new Node(number);
  }
  else if (number < head->getData()){//if the number inputted is smaller than the heads data; go left
    if (head->getLeft()){//keep going left until its null
      addNode(head->getLeft(), number, thead);
    }
    else{//once it reaches end of tree, set the left node to new node
      head->setLeft(new Node(number));
    }
  }
  else if (number > head->getData()){//if the number is larger than heads data
    if (head->getRight()){//go right until null
      addNode(head->getRight(), number, thead);
    }
    else{//set the right node to new node
      head->setRight(new Node(number));
    }
  }
}

void printTree(Node* head, int indent){//prints the tree
  if (head->getRight()){//if get right is not null
    printTree(head->getRight(), indent +1);//recursion
  }
  for (int i = 0; i <=indent; i++){//print a space
    cout << "  ";
  }
  cout << head->getData();//print the data
  cout << endl;//go to next line
  if (head->getLeft()){//if left is not null
    printTree(head->getLeft(), indent + 1);//go left
  }
}

Node* search(Node* head, int number, Node* &parent, bool &right){//to search for a node
  if (number < head->getData()){//if the number is less that head node
    if (head->getLeft()){//go left until get left is null
      right = false;//set right to false; right tells us if left or right child
      parent = head;//set parent
      return search(head->getLeft(), number, parent, right);//return the node
     }
    else return NULL;//if nothing is found; return null
   }
  if (number > head->getData()){//if number is larger than head
    if (head->getRight()){//go right until null
      right = true;//set right to true
       parent = head;
       return search(head->getRight(), number, parent, right);
     }
     else return NULL;
   }
   else return head;
}

bool deleteNode(Node* &head, int number){//deleting a node
   Node* parent;
   bool right;
   Node* deleted;
   Node* swap;
   deleted = search(head, number, parent, right);//find where the deleted node  is
   if (!deleted){//if doesnt exist
     return false;
   }
   if(deleted->getLeft() == NULL && deleted->getRight() != NULL){//if the deleted has one child: right child
     swap = deleted->getRight();//set a node to be the right
     if (head ==deleted){//if its the head; swap it
       head = swap;
     }
     else if (right == true){//if its the deleted node is right child
       parent->setRight(swap);//set the swap to the parents right
     }
     else if (right == false){//if its the left child,
       parent->setLeft(swap);//set th eswap to parents left
     }
   }
   if(deleted->getLeft()!= NULL && deleted->getRight() == NULL){//if only has one child: left
     swap = deleted->getLeft();//set a node to be left
     if (head == deleted){//if head
       head = swap;
     }
     else if(right==true){//if deleted is right child
       parent->setRight(swap);//set swap to be right of parent
     }
     else if (right==false){//if left child
       parent->setLeft(swap);//set the swap to be left
     }
   }
   if(deleted->getLeft() != NULL && deleted->getRight()!= NULL){ //if it has 2 children
     Node* old=NULL;
     Node* newn = NULL;
     Node* move = deleted->getLeft();//set a node to go left of deleted
     while (move->getRight() != NULL){//then go all the way right
       old = move;//set old to move
       move = move->getRight();
       newn = move;
     }
     if (head == deleted){//if its head
       head = move;//swap head and move
       // cout << head->getData() << endl;
     }
     else if (right == true){//if its deleted is right
       parent->setRight(move);//set move to be right
     }
     else if (right == false){//if left
       parent->setLeft(move);//set left 
     }
     move->setRight(deleted->getRight());//set moves right to be deleted
     if (move != deleted->getLeft()){//unusual scenario
       old->setRight(move->getLeft());
       move->setLeft(deleted->getLeft());
     }
   }
       /*

     if (deleted->getLeft()->getRight() == NULL && deleted->getLeft()->getLeft()==NULL){
     move->setLeft(NULL);
     move->setRight(deleted->getRight());
     }
     if (deleted->getLeft()->getLeft()!=NULL){
       move->setLeft(deleted->getLeft()->getLeft());
     }
     else {
       move->setLeft(deleted->getLeft());
       deleted->setRight(deleted->getRight());
     }
     }*/

   if (deleted->getLeft() == NULL && deleted->getRight() == NULL){//if no children
     swap = NULL;
     if (head ==deleted){//set to null
       // cout << "He;" << endl;
       head = NULL;
     }
     else if (right == true){//set to null
       parent->setRight(swap);
       }
     else if (right ==false){//set to null
       parent->setLeft(swap);
     }
   }
   return true;
}
