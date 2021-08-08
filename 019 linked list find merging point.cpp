#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>


struct Node {
    Node* next;
};


Node* BruteForce(Node* head1, Node* head2) {
    Node* t1 = head1;
    while (t1)
    {
        Node* t2 = head2;
        while (t2)
        {
            if (t2 == t1) {
                return t1;
            }

            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return NULL;
}


Node* HashTable(Node* head1, Node* head2) {
    std::set<Node*> lut;

    Node* t1 = head1;
    while (t1)
    {
        lut.insert(t1);
        t1 = t1->next;
    }
    
    Node* t2 = head2;
    while (t2)
    {
        if (lut.count(t2)) {
            return t2;
        }
        t2 = t2->next;
    }

    return NULL;   
}


Node* Stack(Node* head1, Node* head2) {
    std::stack<Node*> l1, l2;

    Node* t = head1;
    while (t) {
        l1.push(t);
        t = t->next;
    }

    t = head2;
    while (t)
    {
        l2.push(t);
        t = t->next;
    }

    t = NULL;

    while (~l1.empty() && ~l2.empty())
    {
        Node* n1 = l1.top();
        Node* n2 = l2.top();

        if (n1 == n2) {
            t = n1;
            l1.pop();
            l2.pop();
        } else {
            break;
        }
    }
    
    return t;      
}

Node* ByFindFirstRepeat(Node* head1, Node* head2) {
    std::vector<Node*> l;

    Node* t = head1;
    while (t)
    {
        l.push_back(t);
        t = t->next;
    }

    t = head2;
    while (t)
    {
        l.push_back(t);
        t = t->next;    
    }

    for (int i = 0; i < l.size() - 1; ++i) {
        for (int j = i + 1; j < l.size(); ++j) {
            if (l[i] == l[j]) {
                return l[i];
            }
        }
    }

    return NULL;
}


Node* BySortAndSearch(Node* head1, Node* head2) {
     std::vector<Node*> l;
     Node* t = head1;
     while (t)
     {
         l.push_back(t);
         t = t->next;
     }

    std::sort(l.begin(), l.end());

    t = head2;
    while (t) {
        // search t in the sorted array l using binary search(here using loop)
        for (int i = 0; i < l.size(); ++i) {
            if (t == l[i]) {
                return t;
            }
        }
        t = t->next;
    }

    return NULL;
}

Node* FindIntersectingNode(Node* head1, Node* head2) {
    int l1 = 0;
    Node* t = head1;
    while (t)
    {
        l1 ++;
        t = t->next;
    }

    int l2 = 0;
    t = head2;
    while (t)
    {
        l2 ++;
        t = t->next;
    }

    Node* long_head;
    Node* short_head;
    int diff;

    if (l1 < l2) {
        long_head = head2;
        short_head = head1;
        diff = l2 - l1;
    } else {
        long_head = head1;
        short_head = head2;
        diff = l1 - l2;
    }

    for (int i = 0; i < diff; ++i) {
        long_head = long_head->next;
    }

    while (long_head && short_head)
    {
        if (long_head == short_head) {
            return long_head;
        }

        long_head = long_head->next;
        short_head = short_head->next;
    }
    
    return NULL;
}

int main(int argc, char** argv) {


    Node* head1 = (Node*)malloc(sizeof(Node));
    Node* n11 = (Node*)malloc(sizeof(Node));

    Node* head2 = (Node*)malloc(sizeof(Node));
    Node* n21 = (Node*)malloc(sizeof(Node));
    Node* n22 = (Node*)malloc(sizeof(Node));

    Node* n3 = (Node*)malloc(sizeof(Node));
    Node* n4 = (Node*)malloc(sizeof(Node));

    head1->next = n11;
    n11->next = n3;

    head2->next = n21;
    n21->next = n22;
    n22->next = n3;

    n3->next = n4;
    n4->next = NULL;

    Node* merging_point = BruteForce(head1, head2);
    printf("Brute force: %d %d\n", n3, merging_point);

    merging_point = NULL;
    merging_point = HashTable(head1, head2);
    printf("Hash table: %d %d\n", n3, merging_point);

    merging_point = NULL;
    merging_point = Stack(head1, head2);
    printf("Stack: %d %d\n", n3, merging_point);

    merging_point = NULL;
    merging_point = ByFindFirstRepeat(head1, head2);
    printf("By find first repeat: %d %d\n", n3, merging_point);

    merging_point = NULL;
    merging_point = BySortAndSearch(head1, head2);
    printf("By sort and search: %d %d\n", n3, merging_point);

    merging_point = NULL;
    merging_point = FindIntersectingNode(head1, head2);
    printf("Efficient approach: %d %d\n", n3, merging_point);

    // free all nodes
}