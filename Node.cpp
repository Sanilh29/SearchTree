#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int newdata){
  data = newdata;
}

Node::Node(){
  
}

Node::~Node(){
  delete &data;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

int Node::getData(){
  return data;
}

void Node::setLeft(Node* node){
  left = node;
}

void Node::setRight(Node* node){
  right = node;
}



