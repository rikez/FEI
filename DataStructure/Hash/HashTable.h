#include "../LDE/LinkedList.h"
#include "./HashItem.h"

#ifndef ALL_HASHTABLE_H
#define ALL_HASHTABLE_H



namespace Structures {

    template <typename K, typename V>
    class HashTable {
    private:
        int max;
        int size;

        LinkedList<HashItem<K,V>>* buf;

        int hash(K key) {
            return key % size;
        }

    public:
        HashTable(int max): size(0), max(max), buf(new LinkedList<HashItem<K,V>>[max]){}

        virtual ~HashTable() {
            delete[] buf;
        }

        bool add(K key, V value) {
            if(size == max) return false;

            HashItem<K, V> hashItem(key, value);

            buf[hash(key)].push(hashItem);
            size++;

            return true;
        }

        bool remove(K key) {
            if(size == 0)
                return false;

            HashItem<K, V> hashItem(key);

            buf[hash(key)].remove(key);

            return true;
        }

    };
}

#endif //ALL_HASHTABLE_H
