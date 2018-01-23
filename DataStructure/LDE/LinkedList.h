//
// Created by ealvarenga on 07/12/17.
//

#ifndef ALL_LINKEDLIST_H
#define ALL_LINKEDLIST_H

#include "Node.h"
namespace Structures {

    template<typename T>
    class LinkedList {
    private:
        Node<T>* first;
        int size;

    public:
        LinkedList(): first(nullptr), size(0) {};
        virtual ~LinkedList() {}

        bool push(T value) {
            Node<T>* freshNode = new Node<T>();
            freshNode->content = value;

            Node<T>* current = first;
            Node<T>* prev = nullptr;

            while(current && current->content < value) {
                prev = current;
                current = current->next;
            }

            freshNode->next = current;

            if(prev)
                prev->next = freshNode;
            else
                first = freshNode;

            size++;
            return true;
        }

        bool remove(int index) {
            Node<T>* current = first;
            Node<T>* prev = nullptr;

            int i = 0;
            while(current && i < index) {
                prev = current;
                current = current->next;
                i++;
            }

            if(!current) return false;

            if(prev)
                prev->next = current->next;
            else
                first = current->next;

            delete current;
            return true;
        }


        const Node<T>* search(T value) {
            Node<T>* current = first;

            while(current && current->content <= value) {
                if(current->content == value)
                    return current;

                current = current->next;
            }

            return nullptr;
        }

        void display() {
            Node<T>* current = first;
            int i = 0;
            while(current) {
                std::cout << "\t" << "[" << i << "] =>" <<'\t' << current->content << std::endl;
                current = current->next;
                i++;
            }
        }
    };

}



#endif //ALL_LINKEDLIST_H
