//
// Created by ealvarenga on 08/12/17.
//

#ifndef ALL_HASHITEM_H
#define ALL_HASHITEM_H


namespace Structures {

    template <typename K, typename V>
    class HashItem {

    private:
        K key;
        V value;

    public:

        template <typename K, typename V> friend class HashTableCollision<K,V>;
        enum class situation {free, filled , collided, killed};
        situation s = situation::free;

        HashItem(){}
        HashItem(K key, V value): key(key), value(value) {}
        HashItem(K key): key(key) {}

        bool operator ==(HashItem& other) {
            return other.key == key;
        }

        bool operator >=(HashItem& other) {
            return other.key >= key;
        }

        bool operator <=(HashItem& other) {
            return other.key <= key;
        }

        bool operator >(HashItem& other) {
            return other.key > key;
        }

        bool operator <(HashItem& other) {
            return other.key < key;
        }

    };
}

#endif //ALL_HASHITEM_H
