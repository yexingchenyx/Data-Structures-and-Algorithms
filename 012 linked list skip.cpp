#include <iostream>

// 有序列表，不允许重复key

template <typename KT, typename DT>
struct Node {
    KT key;
    DT data;
    Node<KT, DT>** forward; // 存放level，0为最下边间隔最小
};

template <typename KT, typename DT>
struct List {
    Node<KT, DT>* head; // head不存放数据
    int levelMaxSize; // 最大允许层数
    int levelSize; // 当前层数
};

template <typename KT, typename DT>
Node<KT, DT>* NewNode(KT key, DT data, int levelMaxSize) {
    Node<KT, DT>* node = (Node<KT, DT>*)malloc(sizeof(Node<KT, DT>));
    node->key = key;
    node->data = data;
    node->forward = (Node<KT, DT>**)malloc(levelMaxSize * sizeof(Node<KT, DT>*));
    for (int i = 0; i < levelMaxSize; ++i) {
        node->forward[i] = NULL;
    }
    return node;
}

template <typename KT, typename DT>
List<KT, DT>* NewList(int levelMaxSize) {
    List<KT, DT>* list = (List<KT, DT>*)malloc(sizeof(List<KT, DT>));
    list->head = NewNode(KT(-1), DT(), levelMaxSize);
    list->levelMaxSize = levelMaxSize;
    list->levelSize = 0;
    return list;
}

int RandLevelSize(int levelMaxSize) {
    int levelSize = 1;
    while (rand() % 2) {
        levelSize ++;
    }

    return levelSize < levelMaxSize ? levelSize : levelMaxSize;
}

template <typename KT, typename DT>
void Insert(List<KT, DT>* list, KT key, DT data) {
    Node<KT, DT>** update = (Node<KT, DT>**)malloc(list->levelMaxSize * sizeof(Node<KT, DT>*));
    for (int i = 0; i < list->levelMaxSize; ++i) {
        update[i] = list->head;
    }
    
    Node<KT, DT>* current = list->head;
    for (int i = list->levelSize - 1; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    if (current->forward[0] && current->forward[0]->key == key) {
        current->forward[0]->data = data;
    } else {
        int newLevelSize = RandLevelSize(list->levelMaxSize);
        
        list->levelSize = newLevelSize;

        Node<KT, DT>* newNode = NewNode(key, data, list->levelMaxSize);
        for (int i = 0; i < list->levelSize; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    free(update);
}

template <typename KT, typename DT>
void Delete(List<KT, DT>* list, KT key) {
    Node<KT, DT>** update = (Node<KT, DT>**)malloc(list->levelMaxSize * sizeof(Node<KT, DT>*));
    for (int i = 0; i < list->levelMaxSize; ++i) {
        update[i] = list->head;
    }
    
    Node<KT, DT>* current = list->head;
    for (int i = list->levelSize - 1; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    if (current->forward[0] && current->forward[0]->key == key) {
        
        Node<KT, DT>* deleteNode = current->forward[0];

        for (int i = 0; i < list->levelSize; ++i) {
       
            if (update[i]->forward[i] != deleteNode) {
                break;
            }

            update[i]->forward[i] = deleteNode->forward[i];
        }
        
        free(deleteNode->forward);
        free(deleteNode);
        
        for (int i = list->levelSize - 1; i >= 0; --i) {
            if (!list->head->forward[i]) {
                list->levelSize --;
            }
        }

        free(update);
    } else {
        free(update);
        return;
    }

}

template <typename KT, typename DT>
Node<KT, DT>* Search(List<KT, DT>* list, KT key) {
    Node<KT, DT>* current = list->head;
    
    for (int i = list->levelSize - 1; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }

    if (current->forward[0] && current->forward[0]->key == key) {
        return current->forward[0];
    } else {
        return NULL;
    }
}

int main(int argc, char** argv) {
    List<int, int>* list = NewList<int, int>(5);

    Insert(list, 1, 1);

    Insert(list, 0, 0);

    Insert(list, 3, 3);
    
    Insert(list, 4, 4);
    
    Insert(list, 5, 5);
    
    Insert(list, 2, 2);

    Delete(list, 0);

    Delete(list, 5);

    Delete(list, 3);

    Node<int, int>* current = list->head->forward[0];
    while (current) {
        printf("%d ", current->data);
        current = current->forward[0];
    }
    printf("\n");

    Node<int, int>* node = Search<int, int>(list, 2);
    if (node) {
        printf("%d\n", node->data);
    }

}