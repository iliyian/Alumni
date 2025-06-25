#include "Node.h"

Node::Node() : data(nullptr), next(nullptr), prev(nullptr) {}

Node::Node(Alumni *data, Node *next, Node *prev) : data(data), next(next), prev(prev) {}

Node::~Node() {
  delete data;
}

void Node::setData(Alumni *data) {
  this->data = data;
}

void Node::setNext(Node *next) {
  this->next = next;
}

void Node::setPrev(Node *prev) {
  this->prev = prev;
}

Alumni *Node::getData() const {
  return data;
}

Node *Node::getNext() const {
  return next;
}

Node *Node::getPrev() const {
  return prev;
}