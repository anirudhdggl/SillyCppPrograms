#include<bits/stdc++.h>

using namespace std;

template<typename key, typename value>

class Node {
      public:
      key k;
      value v;
      Node *next;
      bool isSet;

      Node() {
            this->isSet = false;
            this->next = NULL;
      }

      Node(key k, value v) {
            this->k = k;
            this->v = v;
            this->isSet = true;
            this->next = NULL;
      }

      Node(key k) {
            this->k = k;
            this->isSet = true;
            this->next = NULL;
      }
};

template<typename key, typename value>

class Map {
      public:
      Node<key,value> *arr[599];
      int size = 599;

      Map() {
            Node<key,value> *node = new Node<key,value> ();
            for(int i = 0; i < size; i++) {
                  this->arr[i] = node;
            }
      }

      int findIndex(key k) {
            int sum = 0;
            for(int i = 0; i < k.size(); i++) {
                  sum += (int)k[i];
            }
            return sum % 599;
      }

      void insert(key k, value v) {
            int index = this->findIndex(k);
            Node<key,value> *node = new Node<key,value> (k,v);
            if(this->arr[index]->isSet) {
                  Node<key,value> *traverse = this->arr[index];
                  while(traverse->next) {
                        if(traverse->k == node->k) return;
                        traverse = traverse->next;
                  }
                  if(traverse->k == node->k) {
                        traverse->v = node->v;
                  }
                  else
                        traverse->next = node;
            }
            else {
                  this->arr[index] = node;
            }
      }

      void showMap() {
            for(int i = 0; i < this->size; i++) {
                  Node<key,value> *node = this->arr[i];
                  cout<<"["<<i<<"] ---> ";
                  cout<<node->k<<" | "<<node->v;
                  while(node->next) {
                        cout<<" ---> ";
                        node = node->next;
                        cout<<node->k<<" | "<<node->v;
                  }
                  cout<<endl;
            }
      }

      value find(key k) {
            int index = this->findIndex(k);
            bool found = false;
            value val;
            Node<key,value> *node = this->arr[index];
            while(node->next && !found) {
                  if(node->k == k) {
                        found = false;
                        return node->v;
                  }
                  node = node->next;
            }
            if(!found) {
                  if(node->k == k) {
                        return node->v;
                  }
            }
            
            exit(1);
      }
};

