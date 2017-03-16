#include <cstring>

class Node{
 public:
  Node(int newdata);
  Node();
  ~Node();
  Node* getLeft();
  Node* getRight();
  int getData();
  void setLeft(Node* node);
  void setRight(Node* node);
 private:
  int data;
  Node* left;
  Node* right;
};
