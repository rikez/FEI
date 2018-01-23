//
// Created by ealvarenga on 09/12/17.
//

#ifndef ALL_NODETREE_H
#define ALL_NODETREE_H

namespace Structures {

    template <typename T>
    class NodeTree {

    private:
        NodeTree<T>* right;
        NodeTree<T>* left;
        NodeTree<T>* derived;
        T val;

    public:
        NodeTree(): right(nullptr), left(nullptr), derived(nullptr) {}
        virtual ~NodeTree() {
            right = nullptr;
            left = nullptr;
            derived = nullptr;
        }

        template <typename U> friend class Tree<U>;

    };
}

#endif //ALL_NODETREE_H
