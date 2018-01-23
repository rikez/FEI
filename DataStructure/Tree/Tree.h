//
// Created by ealvarenga on 09/12/17.
//

#ifndef ALL_TREE_H
#define ALL_TREE_H

#include "NodeTree.h"

namespace Structures {

    template <typename T>
    class Tree {
    private:
        NodeTree<T>* root;

    public:
        Tree(): root(nullptr) {}

        bool insert(T val) {
            NodeTree<T>* n = new NodeTree<T>();
            NodeTree<T>* current = root;
            NodeTree<T>* previous = nullptr;

            n->val = val;
            if(!root) {
                root = n;
                return true;
            }

            while(current) {
                previous = current;
                if(current->val > val) { // se o valor do nó atual for maior que o valor que queremos isnerir vá para esquerda
                    current = current->left;
                } else { // se não vá para direita;
                    current = current->right;
                }
            }

            if(previous->val > val) { // insere na esquerda
                previous->left = n; //
            } else { //insere na direita
                previous->right = n;
            }

            // seta pai
            n->derived = previous;
        }

        NodeTree<T>* search(T val) {
            NodeTree<T>* current = root;

            while(current) {

                if(current->val == val) return current;

                if(current->val > val) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            return nullptr;

        }

        bool remove(T val) {
            NodeTree<T>* item = search(val), *parent = nullptr;

            if(!item) return false;

            if(!item->left && !item->right) { // Caso não tenha filhos direitos e esquerdos, é a raiz, ou uma folha.
                parent = item->derived;

                if(!parent) {
                    root = nullptr;
                    delete item;
                    return true;
                }

                if(parent->val > val) { // se ele for
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }

                delete item;

                return true;

            } else if(!item->left) { // Caso tenha somente na direita
                NodeTree<T>* tmp = item->right;

                item->val = tmp->val;
                item->left = tmp->left;

                if(item->left) item->left->derived = item;

                item->right = tmp->right;

                if(item->right) item->right->derived = item;

                delete tmp;
                return true;


            } else if(!item->right) { //Caso tenha somente na esquerda

                NodeTree<T>* tmp = item->left;

                item->val = tmp->val;
                item->left = tmp->left;

                if(item->left) item->left->derived = item;

                item->right = tmp->right;

                if(item->right) item->right->derived = item;

                delete tmp;
                return true;

            } else { // tem direita e esquerda, fodeu, faz recursão adoidado!

                // O cara da direita é maior que o item, logo é maior que o item a esquerda de item.
                NodeTree<T>* successor = item->right;
                // Escolhe um lado do sucessor e manda ir deletando nele (Fazendo a substituição)
                // vá mais a esquerda possível a partir do item à direita, pois ele será o sucessor do elemento q vamos deletar.
                while(successor && successor->left) successor = successor->left;

                // Armazena o value pois ele vai para o item
                T value = successor->val;
                remove(value);

                // Pronto!
                item->val = value;
                return true;
            }
        }

    };
}

#endif //ALL_TREE_H
