class Node {
public:
    Node(int value, 
        Node * Previous=nullptr, 
        Node * Next=nullptr);

    int data;
    Node* Previous;
    Node* Next;

};