//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_CIRCULARQUEUE_H
#define ALL_CIRCULARQUEUE_H

#include <iostream>

namespace Structures {

    template<typename T>
    class CircularQueue {
    private:
        int size;
        int start;
        int end;
        T* arr;

    public:
        CircularQueue(int size): size(size + 1), arr(new T[size + 1]), start(0), end(0) {}

        virtual ~CircularQueue() {
            size = 0;
            start = 0;
            end = 0;
            delete[] arr;
        }

        bool full() {
            return (end+1) % size == start;
        }

        bool empty() {
            return start == end;
        }

        bool queue(T value) {
            if( full() ) return false;
            std::cout << "\t" << "END BEFORE: "<< end <<std::endl;
            arr[end] = value;
            end = (end + 1) % size;
            std::cout << "\t" << "END AFTER: "<< end <<std::endl;
            return true;
        }

        bool dequeue(T& val) {
            if( empty() ) return false;

            std::cout << "\t" << "START BEFORE: "<< start <<std::endl;
            val = arr[start];
            start = (start + 1) % size;
            std::cout << "\t" << "START AFTER: "<< start <<std::endl;
            return true;
        }

        void display() {
            for(int i=start; (i+1) % size != end; i=(i+1)%size ) {
                std::cout << "\t" << "[" << i << "] =>" <<'\t' <<arr[i]<< std::endl;
            }
        }

    };
}

#endif //ALL_CIRCULARQUEUE_H
