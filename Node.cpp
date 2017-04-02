//Sanil Hattangadi, its the node.cpp that has all the methods with what they do
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int newdata){//creates the node; constructore
  data = newdata;
}

Node::Node(){//other default constructor
  
}

Node::~Node(){//deconstructor that deletes the data
  delete &data;
}

Node* Node::getLeft(){//gets the left node
  return left;
}

Node* Node::getRight(){//gets the right node
  return right;
}

int Node::getData(){//gets the data the node holds
  return data;
}

void Node::setLeft(Node* node){//sets the left node
  left = node;
}

void Node::setRight(Node* node){//sets the right node
  right = node;
}



