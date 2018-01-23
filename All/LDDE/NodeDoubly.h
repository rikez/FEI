//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_NODEDOUBLY_H
#define ALL_NODEDOUBLY_H


#include "../Core/BaseNode.h"

namespace Structures {

    template <typename T>
    class NodeDoubly {

    private:
        NodeDoubly<T>* next;
        NodeDoubly<T>* previous;
        T content;
        template <typename U> friend class DoublyLinkedList;

    public:

        NodeDoubly(): next(nullptr), previous(nullptr) {};

        virtual ~NodeDoubly() {
            next = nullptr;
            previous = nullptr;
        }

        int getContent()const {
            return content;
        }


    };
}

#endif //ALL_NODEDOUBLY_H
