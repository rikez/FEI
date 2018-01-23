//
// Created by ealvarenga on 09/12/17.
//

#ifndef ALL_AVL_H
#define ALL_AVL_H

#include "NodeAVL.h"

namespace Structures {

    template <typename T>
    class Tree {
    private:
        NodeAVL<T>* root;

    public:
        Tree(): root(nullptr) {}

        void getBalance(NodeAVL<T>* n) {
            if( n->factor() >= 2 ){ // se o fator for maior = que 2
                if( n->right && n->right->factor() < 0 ) // e se o fator do lado direito do nó for -1
                    rightRotate(n->right); //Aplica Primeiro Right Rotate, depois Left
                leftRotate(n); //APlica apenas left se fator do nó em questão for maior = 2;
            }else if(n->factor() <= -2 ){ // Se o fator do nó for menor = -2
                if( n->left && n->left->factor() > 0 )
                    leftRotate(n->left); // APlica left rotate primeiro, depois right
                rightRotate(n); // APlica Right Rotate apenas se <= -2
            }
        }

        void adjustHeight(NodeAVL<T>* n)	{
            if(n && n->parent){
                if(n->parent->height < n->height + 1) { //se a altura do pai do nó passado for menor que a altura do filho + 1
                    n->parent->height = n->height + 1; // altura do pai do nó passado, é a do nó passado  +1
                    adjustHeight(n->parent); // chama recursivo para todos os parents
                }
            }
        }

        void leftRotate(NodeAVL<T>* n) {

        }

        void rightRotate(NodeAVL<T>* n) {
            NodeAVL<T>* curr = n;
            NodeAVL<T>* left = n->left; // pega esq do nó passado
            NodeAVL<T>* rightOfLeft =  left->right; // pega direita da esquerda
            NodeAVL<T>* parent =  curr->parent; //pega pai

            // COMEÇAM AS TROCAS
            left->right = curr; // DIREITA DA ESQUERDA é o atual
            curr->parent = left; // PAI DO ATUAL É O DA ESQUERDA

            curr->left = rightOfLeft; //ESQUERDA do ATUAL é o nó da direita dó nó esquerda
            if (rightOfLeft)
                rightOfLeft->parent = curr; // pai é o atual

            left->parent = parent; // PAI DO nó esquerdo é o
            if(parent){
                if(left->val < parent->val)
                    parent->left = left;
                else
                    parent->right = left;
            }
            else{
                root = left;
            }

            curr->height -= 2;
            adjustHeight(rightOfLeft);
            adjustHeight(curr);
            adjustHeight(left);
        }

        bool insert(T val) {
            NodeAVL<T>* n = new NodeAVL<T>();
            NodeAVL<T>* current = root;
            NodeAVL<T>* previous = nullptr;

            n->val = val;
            if(!root) {
                root = n;
                return true;
            }

            while(current) {
                previous = current;
                if(current->val > val) { // se o valor do nó atual for maior que o valor que queremos isnerir vá para leftuerda
                    current = current->left;
                } else { // se não vá para direita;
                    current = current->right;
                }
            }

            if(previous->val > val) { // insere na leftuerda
                previous->left = n; //
            } else { //insere na direita
                previous->right = n;
            }

            // seta pai
            n->parent = previous;
        }

        NodeAVL<T>* search(T val) {
            NodeAVL<T>* current = root;

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
            NodeAVL<T>* item = search(val), *parent = nullptr;

            if(!item) return false;

            if(!item->left && !item->right) { // Caso não tenha filhos direitos e leftuerdos, é a raiz, ou uma folha.
                parent = item->parent;

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
                NodeAVL<T>* tmp = item->right;

                item->val = tmp->val;
                item->left = tmp->left;

                if(item->left) item->left->parent = item;

                item->right = tmp->right;

                if(item->right) item->right->parent = item;

                delete tmp;
                return true;


            } else if(!item->right) { //Caso tenha somente na leftuerda

                NodeAVL<T>* tmp = item->left;

                item->val = tmp->val;
                item->left = tmp->left;

                if(item->left) item->left->parent = item;

                item->right = tmp->right;

                if(item->right) item->right->parent = item;

                delete tmp;
                return true;

            } else { // tem direita e leftuerda, fodeu, faz recursão adoidado!

                // O cara da direita é maior que o item, logo é maior que o item a leftuerda de item.
                NodeAVL<T>* successor = item->right;
                // Escolhe um lado do sucessor e manda ir deletando nele (Fazendo a substituição)
                // vá mais a leftuerda possível a partir do item à direita, pois ele será o sucessor do elemento q vamos deletar.
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


#endif //ALL_AVL_H
