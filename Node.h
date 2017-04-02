//Sanil Hattangadi. node header that creates variables and methods
#include <cstring>

class Node{
 public://methods
  Node(int newdata);//constructor that creates node
  Node();//default constructor
  ~Node();//deconstructor when node is deleted
  Node* getLeft();//gets the left node
  Node* getRight();//gets the right node
  int getData();//gets the data the node holds
  void setLeft(Node* node);//sets the left node
  void setRight(Node* node);//sets the right node
 private://variables
  int data;
  Node* left;
  Node* right;
};
