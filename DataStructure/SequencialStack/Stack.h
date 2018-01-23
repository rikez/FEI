//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_STACK_H
#define ALL_STACK_H

namespace Structures {

    template <typename T>
    class Stack { //LIFO

    private:
        T* array;
        int top;
        int size;

    public:

        Stack(int size): array(new T[size]), size(size), top(0) {}

        virtual ~Stack() {
            size = 0;
            top = 0;
            delete[] array;
        }

        bool push(T value) {
            if(top == size) return false; // Pilha no limite.

            array[top] = value;
            top++;
            return true;
        }

        bool pop(T& val) {
            if(top == 0) return false;

            top--;
            array[top];
            val = array[top];
            return true;
        }

        void display() {
            for(int i = top-1; i >= 0; i--) {
                std::cout << "\t" << "[" << i << "] =>" <<'\t' << array[i] << std::endl;
            }
        }


    };
}

#endif //ALL_STACK_H
