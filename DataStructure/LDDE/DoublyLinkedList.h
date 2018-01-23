//
// Created by ealvarenga on 07/12/17.
//

#ifndef ALL_DOUBLYLINKEDLIST_H
#define ALL_DOUBLYLINKEDLIST_H

#include "NodeDoubly.h"

namespace Structures {

    template<typename T>
    class DoublyLinkedList {
    private:
        NodeDoubly<T>* first;
        NodeDoubly<T>* last;
        int size;

    public:
        DoublyLinkedList(): first(nullptr), size(0) {};
        virtual ~DoublyLinkedList() {
            NodeDoubly<T>* pointer = first;
            NodeDoubly<T>* next = nullptr;

            while(pointer) {
                next = pointer->next;
                delete pointer;
                pointer = next;
            }

            first = nullptr;
            last = nullptr;
            size = 0;
        }

        bool push(T value) {
            NodeDoubly<T>* freshNode = new NodeDoubly<T>();
            freshNode->content = value;

            NodeDoubly<T>* current = first;
            NodeDoubly<T>* prev = nullptr;

            while(current && current->content < value) { // Inserindo ordenado.
                prev = current;
                current = current->next;
            }

            freshNode->next = current;
            freshNode->previous = prev;

            if(prev) { // Se houver o anterior do atual, o próximo do anterior será o valor que vamo inserir
                prev->next = freshNode;
            } else { // se não tiver anterior a ele, sabemos que é o primeiro;
                first = freshNode;
            }

            if(current) { // se o atual existir, o anterior a ele é o novo nó que estamos inserindo
                current->previous = freshNode;
            } else { //se não houver o atual, ele é o último nó
                last = freshNode;
            }

            size++;
            return true;
        }

        bool remove(int index) {
            NodeDoubly<T>* current = first;
            NodeDoubly<T>* prev = nullptr;

            int i = 0;
            while(current && i < index) { // Enquanto existir um atual e o índice desejado  for maior que o contador
                prev = current;
                current = current->next;
                i++;
            }

            if(!current) return false; // se não tem o atual, não achamos o elemento a ser removido.

            if(prev) // se tem o anterior ao atual, vamos fazer o reapontamento, pois o próximo dele será o próximo do atual;
                prev->next = current->next;
            else //
                first = current->next;

            if(current->next) // se o pŕoximo do atual existir, o anterior do próximo será o anterior
                current->next->previous = prev;
            else // se não o último será o anterior
                last = prev;

            //deleta o atual, no índice que queremos.
            delete current;
            size--;
            return true;
        }


        const NodeDoubly<T>* search(T value) {
            NodeDoubly<T>* current = first;

            while(current && current->content <= value) {
                if(current->content == value) // O(n), até achar valor.
                    return current;

                current = current->next;
            }

            return nullptr;
        }

        void display() {
            NodeDoubly<T>* current = first;
            int i = 0;
            while(current) {
                std::cout << "\t" << "[" << i << "] =>" <<'\t' << current->content << std::endl;
                current = current->next;
                i++;
            }
        }
    };

}



#endif //ALL_DOUBLYLINKEDLIST_H
