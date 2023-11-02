#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next; 
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {} 
    Node(int x, Node* next) : val(x), next(next) {} 
};

class ListNodes{
    public:
        Node* head; // Initialize a Node object pointer, constructor aren't executed for now
        ListNodes(){
            head = NULL; 
        }

        ~ListNodes(){
            Node* current = head; // starting at head
            Node* temp = current->next;
            delete current;
            while (true){
                current = temp;
                if (current == NULL || current->next == NULL){
                    break;
                }
                temp = current->next;
            }
        }
        
        void insertNode(int val){
            Node* new_node = new Node(val);
            if (head == NULL){
                head = new_node; // head now points to the FIRST new_node
                return; // exit the function after creating the first node
            } 
            Node* temp = head;
            while (temp->next != NULL){
                temp = temp->next; 
            } 
            temp->next = new_node; // update indirectly through pointer
        }

        void printList(){
            Node* temp = head; 
            while (true){
                cout << temp->val << endl;
                if (temp->next == NULL){
                    break;
                }
                temp = temp->next;
            }
        }

        Node* swapPairs(Node* head) {
           this->head = head; 
           Node* current_node = head;
           Node* temp = NULL;
           if (current_node->next == NULL){
                return current_node;
           }
           this->head = current_node->next;
           current_node = swapConsecutive(current_node);
           if(current_node->next != NULL) {
                if(current_node->next->next != NULL){
                    while(true){
                        temp = current_node->next;
                        current_node->next = temp->next;
                        current_node = swapConsecutive(temp);
                        if(
                            current_node->next == NULL ||
                            current_node->next->next == NULL
                            ){
                            break;
                        }
                    }
                }
           }
           return this->head;
        }

    private:
        Node* swapConsecutive(Node* current_node){
            Node* temp = current_node->next;
            current_node->next = temp->next;
            temp->next = current_node;
            return current_node; 
        }
};

int main(){
    ListNodes list;   
    Node* input_node;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(4);
    list.insertNode(5);
    list.insertNode(6);
    list.insertNode(7);
    input_node = list.head;
    Node* new_head = list.swapPairs(input_node->next);
    list.printList();
    cout << "current head: " << new_head->val << endl;
}
