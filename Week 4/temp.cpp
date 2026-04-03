#include <bits/stdc++.h>
#include <memory>
// using namespace std;

class Node {
private:
    int data;
    std::unique_ptr<Node> next;
public:
    Node();
    Node(int data, Node& node) : data(data), next(std::make_unique<Node>(node)) {}

    void addNext(Node& node) {
        this->next = std::make_unique<Node>(node);
    }

    int pop() {
        Node* nextNodePtr = this->next.get();
        while (nextNodePtr) {
            nextNodePtr = nextNodePtr->next.get();
        }
        int returnVal = nextNodePtr->data;
        nextNodePtr
    }
};

void main()
{
    Node* head = malloc();
    A(head);
}

void A(Node*& head)
{
    head
}

void main() {
    Node* node = Node{}
    Node** doublePtrNode;
    doublePtrNode = malloc(sizeof(Node*));
}