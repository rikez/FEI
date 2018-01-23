//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_BASENODE_H
#define ALL_BASENODE_H

namespace Structures {

    template <typename T>
    class BaseNode {

    public:
        virtual ~BaseNode() {}


    private:
        BaseNode<T>* next;
        T content;
    };
}


#endif //ALL_BASENODE_H
