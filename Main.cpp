#include <cstring>
#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Node* head, int number);

int main(){
  Node* head = NULL;
  char command[32];
  bool running = true;
  while (running == true){
    cout << "Enter a command: add, search, print, delete, or quit." << endl;
    cin.get(command, 32);
    if (0==strcmp(command, "add")){
      if (head == NULL){
	head = new Node();
      }
      else{
	int number;
	cout << "What number?" << endl;
	cin >> number;
	addNode(head, number);
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

void printTree(Node* head){

}

Node* Search(){

}

bool deleteNode(){

}
