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

    void setNext( K key, V value){
        next = new MinhNode(key, value); 
    }

private:
    K key;
    V value;
    MinhNode* next;
};