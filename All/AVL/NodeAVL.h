//
// Created by ealvarenga on 09/12/17.
//

#ifndef ALL_NODEAVL_H
#define ALL_NODEAVL_H

namespace Structures {

    template <typename T>
    class NodeAVL {



    public:

        int height;
        T val;
        NodeAVL<T>* right;
        NodeAVL<T>* left;
        NodeAVL<T>* parent;

        int factor() {
            int heightLeft = left ? left->height : -1;
            int heightRight = right ? right->height : -1;

            return heightRight - heightLeft;
        }


    };
}

#endif //ALL_NODEAVL_H
