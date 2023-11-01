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
            Node* current = head; // starting at head
            Node* temp = current->next;
            delete current;
            while (true){
                current = temp;
                if (current->next == NULL){
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

        Node* swapPairs(Node* head) {
            /*
            Change the value of `next` for each node
            Args:
            - takes in a Node object pointer, if the addressed it points to 
              , input node would be made as a new head
            Returns:
            - New head;
            */
           this->head = head; 
           Node* current_node = head;
           Node* temp = NULL;
           if (current_node->next == NULL){
                return current_node;
           }
           current_node = swapConsecutive(this->head);
           do{
                temp = current_node->next;
                current_node->next = temp->next;
                current_node = temp;
                current_node = swapConsecutive(current_node);
                // cout << current_node->val << endl;
           }while(current_node->next != NULL);

           return this->head;
        }
    private:
        Node* swapConsecutive(Node* current_node){// current_node is either head or (tail -2)
        // 1 and 2 is swapped but two is not printed because head is still pointing to Node 1
        // NOTE: call this when '1 2 3 N or '1 2 N
            // cout << "head is: " << head << ", " << "current node is: " << current_node << endl; 
            // cout << "before next next: " << current_node->next->next << endl;
            if (current_node == head){
                head = current_node->next;
            }
            Node* temp = current_node->next;
            current_node->next = temp->next;
            temp->next = current_node;
            // cout << "after next: " << current_node->next << ", head is: " << head << endl;

            return current_node; // address of the Node next to current node after they're swapped 
        }
};

int main(){
    ListNodes list;   
    Node* main_node;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    // list.insertNode(5);
    // list.insertNode(6);
    list.swapPairs(list.head);
    // main_node = list.swapHeadTail(list.head);
    // cout << "res: " << main_node->next << endl;
    list.printList();
}
