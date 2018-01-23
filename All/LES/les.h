//
// Created by ealvarenga on 07/12/17.
//

#ifndef ALL_LES_H
#define ALL_LES_H

namespace Structures {

    template<typename T>
    class les {

    private:
        int size;
        int capacity;
        T *buffer;

    public:
        les(int n);

        virtual ~les();

        bool push(T value);

        bool remove(int index);

        bool removeByValue(T value);

        T search(int index);

        int searchByValue(T value);

        void display();

    };
}


#endif //ALL_LES_H
