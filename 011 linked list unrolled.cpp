#include <iostream>


template <typename T>
struct Node {
    T data;
    Node<T>* prev; // 指向前一个node，block内的第一个node指向block中的最后一个node
};

template <typename T>
struct Block {
    Block<T>* next;
    Node<T>* head;
    int nodes; 
};

template <typename T>
struct List {
    Block<T>* head;
    int blockSize;
};

template <typename T>
Node<T>* NewNode(T data) {
    Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
    node->data = data;
    node->prev = NULL;
    return node;
}

template <typename T>
Block<T>* NewBlock() {
    Block<T>* block = (Block<T>*)malloc(sizeof(Block<T>));
    block->next = NULL;
    block->head = NULL;
    block->nodes = 0;
    return block;
}

template <typename T>
List<T>* NewList(int blockSize) {
    List<T>* list = (List<T>*)malloc(sizeof(List<T>));
    list->head = NULL;
    list->blockSize = blockSize;
    return list;
}

#define OUT

template <typename T>
void Search(List<T>* list, int k, OUT Block<T>** block, OUT Node<T>** node) {
    // find the block
    int i = k / list->blockSize;
    Block<T>* currentBlock = list->head;
    while(i--) {
        currentBlock = currentBlock->next;
    }

    // find the node
    i = currentBlock->nodes - k % list->blockSize;
    Node<T>* currentNode = currentBlock->head;
    while(i--) {
        currentNode = currentNode->prev;
    }

    *block = currentBlock;
    *node = currentNode;
}

/**
 * 将block末尾超出blockSize的node移入下一个block
 */
template <typename T>
void Shift(List<T>* list, Block<T>* block) {

    Block<T>* currentBlock = block;

    while (currentBlock->nodes > list->blockSize) {
        if (!currentBlock->next) {
            Block<T>* newBlock = NewBlock<T>();
            
            Node<T>* currentBlockHead = currentBlock->head;
            Node<T>* currentBlockLast = currentBlockHead->prev;
            Node<T>* currentBlockLastPrev = currentBlockLast->prev;
            
            currentBlockHead->prev = currentBlockLastPrev;
            currentBlock->next = newBlock;
            newBlock->head = currentBlockLast;
            currentBlockLast->prev = currentBlockLast;
            
            currentBlock->nodes --;
            newBlock->nodes ++;
        } else {
            Block<T>* nextBlock = currentBlock->next;

            Node<T>* currentBlockHead = currentBlock->head;
            Node<T>* currentBlockLast = currentBlockHead->prev;
            Node<T>* currentBlockLastPrev = currentBlockLast->prev;

            Node<T>* nextBlockHead = nextBlock->head;
            Node<T>* nextBlockLast = nextBlockHead->prev;

            currentBlockHead->prev = currentBlockLastPrev;
            nextBlock->head = currentBlockLast;
            currentBlockLast->prev = nextBlockLast;
            nextBlockHead->prev = currentBlockLast;

            currentBlock->nodes --;
            nextBlock->nodes ++;
        }

        currentBlock = currentBlock->next;
    }
}

template <typename T>
void Insert(List<T>* list, T data, int k) {
    Node<T>* newNode = NewNode(data);
    if (k == 0) {
        if (!list->head) {
            list->head = NewBlock<T>();
        }

        Block<T>* block = list->head;
        
        if (!block->head) {
            block->head = newNode;
            newNode->prev = newNode;
        } else {
            Node<T>* head = block->head;
            Node<T>* last = head->prev;
            block->head = newNode;
            newNode->prev = last;
            head->prev = newNode;
        }

        block->nodes ++;
        Shift(list, block);
    } else {
        Block<T>* prevNodeBlock = NULL;
        Node<T>* prevNode = NULL;
        Search(list, k - 1, &prevNodeBlock, &prevNode);
        Node<T>* prevNextNode = prevNodeBlock->head;
        while (prevNextNode->prev != prevNode) {
            prevNextNode = prevNextNode->prev;
        }
        prevNextNode->prev = newNode;
        newNode->prev = prevNode;

        prevNodeBlock->nodes ++;
        Shift(list, prevNodeBlock);
    }
}

int main(int argc, char** argv) {

    List<int>* list = NewList<int>(3);
    
    const int n = 5;

    for (int i = 0; i < n; ++i) {
        Insert(list, i, i);
    }

    for (int i = 0; i < n; ++i) {
        Block<int>* block = NULL;
        Node<int>* node = NULL;
        Search(list, i, &block, &node);

        printf("%d ", node->data);
    }
    printf("\n");

}