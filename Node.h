#ifndef NODE_H
#define NODE_H

#include "Alumni.h"

class Node {
private:
  Alumni *data;
  Node *next;
  Node *prev;
public:
  Node();
  Node(Alumni *data, Node *next, Node *prev);
  ~Node();
  void setData(Alumni *data);
  void setNext(Node *next);
  void setPrev(Node *prev);
  Alumni *getData() const;
  Node *getNext() const;
  Node *getPrev() const;
};

#endif