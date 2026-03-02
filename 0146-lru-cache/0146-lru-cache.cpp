class LRUCache {
public:
    class Node{
        public:
        int data,key;
        Node * next;
        Node * prev;

        Node(int d,int k){
            data=d;
            key=k;
            prev=NULL;
            next=NULL;
        }
    };
    Node * head=NULL;
    Node * tail=NULL;
    int cap=0;
    unordered_map<int,Node *>mp;


    // add to doubly 
    void addToLL(int d,int key){
        Node * newNode=new Node(d,key);
        Node * nextNode=head->next;;

        head->next=newNode;
        newNode->prev=head;
        newNode->next=nextNode;
        nextNode->prev=newNode;
    }

     void deleteFromLL(Node * target){
        Node * nextNode=target->next;
        Node * prevNode=target->prev;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }











    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        Node * ans=mp[key];
        mp.erase(key);
        deleteFromLL(ans);

        put(key,ans->data);

        return ans->data;
        
    }

    void put(int key, int value) {
        // if capacity already full
        // already exist
        if(mp.find(key)!=mp.end()){   
            deleteFromLL(mp[key]);
            mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteFromLL(tail->prev);
        }

        addToLL(value,key);
        mp[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */