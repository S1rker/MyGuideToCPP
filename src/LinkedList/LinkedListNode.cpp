#include "LinkedListNode.h"

Node::Node(int value, Node * Previous=nullptr, Node * Next=nullptr)
    : data(value),
    Previous(Previous),
    Next(Next)

{

};