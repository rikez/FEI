//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_LINKEDQUEUE_H
#define ALL_LINKEDQUEUE_H

#include <iostream>
#include "NodeQueue.h"

namespace Structures {
    template <typename T>
    class LinkedQueue { // FIFO (FIrst In First Out)

    private:
        NodeQueue<T>* first;
        NodeQueue<T>* last;
        int size;

    public:

        LinkedQueue() : first(nullptr), last(nullptr), size(0){}

        bool queue(T val) {
            NodeQueue<T>* node = new NodeQueue<T>();
            node->val = val;
            node->next = nullptr;

            if(!first) // se não tem primeiro ele é o primeiro
                first = node;
            else
                last->next = node;// se não ele é o último

            last = node;// se não ele é o último
            size++;

            return true;

        }

        bool dequeue(T& val) {
            if(!first) return false;

            NodeQueue<T>* auxNode = first->next;
            val = first->val;
            delete first;
            if(auxNode)
                first = auxNode;
            else
                last = nullptr;

            return true;
        }

        void display() {
            NodeQueue<T>* auxNode = first;
            int i = 0;
            while(auxNode) {
                std::cout << "\t" << "[" << i << "] =>" <<'\t' << auxNode->val << std::endl;
                auxNode = auxNode->next;
                i++;
            }
        }


    };
}

#endif //ALL_LINKEDQUEUE_H
