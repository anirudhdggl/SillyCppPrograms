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
