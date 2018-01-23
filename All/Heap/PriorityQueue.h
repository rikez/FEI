//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_PRIORITYQUEUE_H
#define ALL_PRIORITYQUEUE_H

#include <vector>
#include <algorithm>

namespace {

    template<typename T>
    class PriorityQueue {
    public:

        bool insert( T val ) {
            arr.push_back(val);
            heapify();
        }

        void heapify() {
            int size = arr.size();
            for(int i = lastParent(size); i >=0; i--)
                siftUp(i);
        }

        void siftUp(int idx) {
            int size = arr.size();
            int left = left(idx);
            int right = right(idx);
            int choosen = left;
            if(right < size && arr[right] > arr[left]){ // se o filho esquerdo for menor que o tamanho do array e o valor do filho direito for maior que o esquerdo
                choosen = right;
            }

            if(arr[choosen] > arr[idx]){ // valor da direita ou da esquerda for maior que de seu papa;
                swap(arr[choosen], arr[i]); //troca os valores
                siftUp(choosen);
            }
        }

        void siftDown(int idx) {
            int size = arr.size();
            int left = left(idx);
            int right = right(idx);
            int choosen = left;
            if(right < size && arr[right] > arr[left]){ // se o filho esquerdo for menor que o tamanho do array e o valor do filho direito for maior que o esquerdo
                choosen = right;
            }

            if(arr[choosen] < arr[idx]){ // valor da direita ou da esquerda for maior que de seu papa;
                swap(arr[choosen], arr[i]); //troca os valores
                siftUp(choosen);
            }
        }

        void removeMax(){
            // [ex: [1, 2, 3, 4, 5]
            //arr[0] = arr[4]
            //arr[0] = 5 arr[4] = 5;
            //pop back => [5, 2, 3, 4]
            // roda sift para consertar.
            int tam = arr.size();
            arr[0] = arr[tam-1];
            arr.pop_back();
            siftUp(0);
        }



    private:
        vector<T> arr;

        int left(int idx) {
            return 2*idx+1;
        }

        int right(int idx) {
            return 2*idx+2;
        }

        int parent(int idx) {
            return (idx-1)/2;
        }

        int lastParent(int idx) {
            return arr.size()/2 - 1;
        }


    };

}

#endif //ALL_PRIORITYQUEUE_H
