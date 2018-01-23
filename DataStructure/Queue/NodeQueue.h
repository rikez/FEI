//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_NODEQUEUE_H
#define ALL_NODEQUEUE_H

template <typename T>
class NodeQueue;
#include "LinkedQueue.h"

namespace Structures {

    template<typename T>
    class NodeQueue {
    private:
        NodeQueue<T> *next;
        T val;

    public:
        T getValue() const {
            return val;
        }

        template <typename U> friend class LinkedQueue;
    };
}

#endif //ALL_NODEQUEUE_H
