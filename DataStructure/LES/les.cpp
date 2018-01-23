#include "les.h"
#include <iostream>

namespace Structures {

    template<typename T>
    les<T>::les(int n): buffer(new T[n]), size(0), capacity(n) {}

    template<typename T>
    les<T>::~les() {}

    template<typename T>
    bool les<T>::push(T value) {
        if (capacity == size) return false; //** Se a capacidade do array for atingida

        int i;

        for (i = 0; i < size && buffer[i] < value; i++); //* Inserção ordenada, portanto vamos achar a posição

        for (int j = size; j > i; j--) {
            buffer[j] = buffer[j - 1]; // vai reposicionando os elementos de trás para frente
        }

        buffer[i] = value;
        size++;
        return true;
    }

    template<typename T>
    bool les<T>::remove(int index) {
        if (index > (size - 1) || index < 0) throw "Index out of bounds error";

        for (int i = index; i < (size - 1); i++) { //size +1, pois poderia estourar uma exception no último elemento pois no i+1 não teria nada.
            buffer[i] = buffer[i+1]; // Atual(começa no indice, que é o que queremos remover) é igual ao próximo, portanto é sobreescrito
        }

        size--;
        return true;
    }

    template<typename T>
    bool les<T>::removeByValue(T value) {
        int index = search(value);
        if (index == -1) return false;

        return les<T>::remove(index);
    }

    template<typename T>
    T les<T>::search(int index) {
        if (index < 0 || index >= size) return -1;

        return buffer[index];

    }



    template<typename T>
    int les<T>::searchByValue(T value) {
        if (size == 0) return -1;

        for (int i = 0; i < size; i++) {
            if (buffer[i] == value)
                return i;
        }

        return -1;
    }

    template<typename T>
    void les<T>::display() {
        for(int i = 0; i < size; i++) {
            std::cout << "\t" << "[" << i << "] =>" <<'\t' << buffer[i] << std::endl;
        }
    }
}



