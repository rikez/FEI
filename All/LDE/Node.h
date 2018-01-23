//
// Created by ealvarenga on 07/12/17.
//

#ifndef ALL_NODE_H
#define ALL_NODE_H

#include "LinkedList.h"

namespace Structures {

    template <typename T>
    class Node {


    private:
        Node<T>* next;
        T content;
        template <typename U> friend class LinkedList;

    public:


        Node(): next(nullptr) {};

        virtual ~Node() {

        }

        int getContent()const {
            return content;
        }


    };
}

#endif //ALL_NODE_H
