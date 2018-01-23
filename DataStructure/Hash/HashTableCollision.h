//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_HASHTABLECOLLISION_H
#define ALL_HASHTABLECOLLISION_H

#include "HashItem.h"

namespace Structures {

    template <typename K, typename V>
    class HashTableCollision {
    private:
        HashItem<K,V> * table;
        int size;
        int count;

    public:
        HashTableCollision(int size) : table(new HashItem<K, V>[size]), size(size), count(0) {

        }

        int hash(K key) {
            return key % size;
        }

        int reHash(int k, int idx) {
            return (k + incFunc(idx)) % size;
        }

        int incFunc(int p) {
            return p + p;
        }

        bool insert(K key, V value) {
            if (count == size) {
                return false;
            }

            int pos = hash(key); // Gera um hash que será posição
            int idx = 1; // começa no índice 1
            while (table[pos].s != HashItem<K, V>::situation::free &&
                   table[pos].s != HashItem<K, V>::situation::killed) { // se não estiver disponível && não tiver tido colisão

                if (table[pos].s == HashItem<K, V>::situation::filled) // se estiver preenchido
                    table[pos].s = HashItem<K, V>::situation::collided; // COLIDE
                pos = reHash(hash(key), idx++); // FAZ REHASH para achar nova posição
            }

            if (table[pos].s == HashItem<K, V>::situation::free) { // se estiver disponícel, preenche
                table[pos].s = HashItem<K, V>::situation::filled;

            } else if (table[pos].s == HashItem<K, V>::situation::killed) { //se ja sofreu colisão antes, volta para colidido
                table[pos].s = HashItem<K, V>::situation::collided;

            }
            table[pos].key = key;
            table[pos].value = value;
            count++;

            return true;
        }

        bool search(K key, V &v) {
            int pos = hash(key);// faz hash para achar posição
            int idx = 1;
            while (table[pos].key != key && (
                    table[pos].s == HashItem<K, V>::situation::collided ||
                    table[pos].s == HashItem<K, V>::situation::killed)
                    ) { // enquanto a chave não for a desejada e situação for colidido || já foi colidido antes.
                pos = reHash(hash(key), idx++); //Aplica rehash, pois se está colidido ou morto, significa que foi aplicado rehash.
            }
            if (table[pos].key == key) {
                v = table[pos].value;
                return true;
            } else {
                return false;
            }
        }

        virtual ~HashTableCollision() {
            delete[] table;
        }
    };
}

#endif //ALL_HASHTABLECOLLISION_H
