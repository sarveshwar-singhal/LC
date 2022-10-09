#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{

public:
    int key;
    int data;
    Node *left, *right;

    Node(int key, int d){
        this->key = key;
        this->data = d;
        left = NULL;
        right = NULL;
    }

    ~Node(){
        if(right!=NULL){
            delete this->right;
        }
    }
};


class LRUCache {
    int cap;
    Node *head, *last;
    int curr_cap;
    unordered_map<int, Node *> add;

    /*  void insert_at_end(int key, int value){
        Node *temp = new Node(key, value);
        add[key] = temp;
        temp->left = last;
        last->right = temp;
        last = temp;
    }   */

    void insert_at_end(Node *temp){
        //this function is used to attach the given node at the last position
        temp->left = last;
        last->right = temp;
        last = temp;
    }

    void move_to_end(Node *temp, int value){
        //this function is used to break the linkage between nodes
        temp->data = value;
        if(temp == last){
            return;
        }
        
        if(temp == head){
            head = head->right;
            head->left = NULL;
            temp->right = NULL;
            insert_at_end(temp);
            return;
        }

        temp->left->right = temp->right;
        temp->right->left = temp->left;
        temp->right = NULL;
        temp->left = NULL;
        insert_at_end(temp);
        return;
    }

    void remove_head_node(){
        Node *temp = head;
        add.erase(head->key);
        head = head->right;
        if(head==NULL){
            last = NULL;
        } else{
            head->left = NULL;
        }
        temp->right = NULL;
        this->curr_cap -=1;
        //delete command was taking up time during online submission.
        // delete temp;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->head = NULL;
        this->curr_cap = 0;
    }
    
    int get(int key) {
        if(add.find(key) != add.end()){
            move_to_end(add[key], add[key]->data);
            return add[key]->data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(add.find(key) == add.end() and this->curr_cap == this->cap){
            remove_head_node();
        }

        if(add.find(key) != add.end()){
            move_to_end(add[key], value);
        } else {
            Node *temp = new Node(key, value);
            add[key] = temp;
            this->curr_cap +=1;
            if(head == NULL){
                head = last = temp;
            } else{
                insert_at_end(add[key]);
            }
        }
    }

    ~LRUCache(){
        if(head!=NULL){
            delete head;
        }
    }
};


int main(){

    LRUCache lru(2);
    vector<string> command = { "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> value = {{1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    // command = {"put","get","put","get","get"};
    // value = {{2,1},{2},{3,2},{2},{3}};

    
    vector<int> ans(command.size()+1, NULL);
    int i;
    for(i=0;i<command.size();i++){
        if(command[i] == "put"){
            lru.put(value[i][0], value[i][1]);
        } else{
            ans[i+1] = lru.get(value[i][0]);
        }
    }

    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}