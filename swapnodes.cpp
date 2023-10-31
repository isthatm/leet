#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next; 
    Node() : val(0), next(nullptr) {cout << "default initialization" << endl;} //default constructor, used when creating new nodes
    Node(int x) : val(x), next(nullptr) {} 
    Node(int x, Node* next) : val(x), next(next) {} //next(next_arg)
};

class ListNodes{
    public:
        Node* head; // Initialize a Node object pointer, constructor aren't executed for now
        ListNodes(){
            head = NULL; 
        }

        ~ListNodes(){
            Node* temp = head; // starting at head
            delete temp;
            while (true){
                if (temp->next == NULL){
                    break;
                }
                temp = temp->next;
            }
        }
        
        void insertNode(int val){
            Node* new_node = new Node(val);
            if (head == NULL){
                head = new_node; // head now points to the FIRST new_node
                return; // exit the function after creating the first node
            } 
            Node* temp = head; //starts at head, temp and head now point to the same address
            while (temp->next != NULL){
                // for the first loop (from the 2nd node), temp->next = NULL, this loop is skipped
                temp = temp->next; //dereferencing the pointer stored in next
            } 
            temp->next = new_node; // update indirectly through pointer
        }

        void printList(){
            Node* temp = head; //start at head
            while (true){
                cout << temp->val << endl;
                if (temp->next == NULL){
                    break;
                }
                temp = temp->next;
            }
        }

        void swapPairs() {
            /*
            Change the value of `next` for each node
            Returns:
            - New head;
            */   
           Node* current_node = head;
           Node* temp;
           do{
            temp = current_node->next->next;
            current_node->next = current_node;
            current_node = temp->next;
           }while(temp->next != NULL);

           return;
        }
    // private:
        Node* swap_head_tail(Node* current_node){// current_node is either head or (tail -2)
            cout << "head is: " << head << ", " << "current node is: " << current_node << endl; 
            cout << "before next next: " << current_node->next->next << endl;
            Node* temp = current_node->next;
            current_node->next = temp->next;
            temp->next = current_node;
            cout << "after next: " << current_node->next << ", head is: " << head->val << endl;

            return current_node->next; // address of the current 
        }
};

int main(){
    ListNodes list;   
    Node* main_node;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
    list.insertNode(6);
    // list.swapPairs();
    main_node = list.swap_head_tail(list.head);
    // cout << "res: " << main_node->next << endl;
    list.printList();
}

