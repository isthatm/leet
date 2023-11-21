template <typename K, typename V>
class MinhNode{
public:
    MinhNode(K key, V value): key(key), value(value), next(NULL){}

    MinhNode* getNext(){
        return next;
    }

    V getValue(){
        return value;
    }

    K getKey(){
        return key;
    }

    void setNew(K key, V value){
        next = new MinhNode(key, value); 
    }

    void updateValue(V value){
        this->value = value;
    }

    void setNext(MinhNode* next_node){
        next = next_node;
    }

private:
    K key;
    V value;
    MinhNode* next;
};