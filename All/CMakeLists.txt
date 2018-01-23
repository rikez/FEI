cmake_minimum_required(VERSION 3.8)
project(All)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES  main.cpp LES/les.cpp LES/les.h LDE/LinkedList.h LDE/Node.h  LDDE/DoublyLinkedList.h LDDE/NodeDoubly.h Core/BaseNode.h SequencialStack/Stack.h Queue/LinkedQueue.h Queue/NodeQueue.h Queue/CircularQueue.h Hash/HashTable.h Graph/Graph.h Hash/HashItem.h Hash/HashTableCollision.h Heap/PriorityQueue.h Tree/Tree.h Tree/NodeTree.h AVL/NodeAVL.h AVL/AVL.h)
add_executable(All ${SOURCE_FILES} LES/les.cpp LES/les.h LDE/LinkedList.h LDE/Node.h)