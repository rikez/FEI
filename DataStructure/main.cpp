#include <iostream>

#include "LES/les.cpp" // Gambeta, pois clion não cria link entre .cpp e .h
#include "LDE/LinkedList.h" // Gambeta, pois clion não cria link entre .cpp e .h
#include "LDDE/DoublyLinkedList.h" // Gambeta, pois clion não cria link entre .cpp e .h
#include "SequencialStack/Stack.h"
#include "Queue/LinkedQueue.h"
#include "Queue/CircularQueue.h"

using namespace std;
using namespace Structures;


int main() {

    cout << "-----------------------------------" << endl;

    cout << "(LES) implementation" << endl;
    les<int> l(10);
    l.push(1);
    l.push(50);
    l.push(10);
    l.push(0);
    l.push(10);
    l.push(9);
    l.push(8);
    l.remove(0);
    l.display();
    cout << "(LES) Search By Value => " << l.searchByValue(50) << endl;

    cout << "-----------------------------------" << endl;

    cout << "(LDE) implementation" << endl;
    LinkedList<int> lde;
    lde.push(1);
    lde.push(50);
    lde.push(10);
    lde.push(0);

    lde.remove(1);
    lde.display();
    const Node<int>* node = lde.search(10);
    cout << "(LDE) Search By Value => " << node->getContent() << endl;

    cout << "-----------------------------------" << endl;

    cout << "(LDDE) implementation" << endl;
    DoublyLinkedList<int> ldde;
    ldde.push(1);
    ldde.push(50);
    ldde.push(10);
    ldde.push(0);
    ldde.remove(1);

    ldde.display();
    const NodeDoubly<int>* nodeDoubly = ldde.search(10);
    cout << "(LDDE) Search By Value => " << nodeDoubly->getContent() << endl;

    cout << "-----------------------------------" << endl;

    cout << "(SequencialStack) implementation" << endl;
    Stack<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(110);
    stack.push(20);
    stack.push(12);
    stack.push(0);
    int value;
    stack.pop(value);
    stack.pop(value);

    stack.display();
    cout << "(SequencialStack) Search By Value => " << value << endl;

    cout << "-----------------------------------" << endl;


    cout << "(LinkedQueue) implementation" << endl;
    LinkedQueue<int> linkedQueue;
    linkedQueue.queue(1);
    linkedQueue.queue(2);
    linkedQueue.queue(3);
    linkedQueue.queue(4);
    linkedQueue.queue(5);
    linkedQueue.queue(110);
    linkedQueue.queue(20);
    linkedQueue.queue(12);
    linkedQueue.queue(0);
    int value_two;
    linkedQueue.dequeue(value_two);
    linkedQueue.dequeue(value_two);

    linkedQueue.display();
    cout << "(LinkedQueue) Search By Value => " << value_two << endl;

    cout << "-----------------------------------" << endl;

    cout << "(CircularQueue) implementation" << endl;
    CircularQueue<int> circularQueue(10);
    circularQueue.queue(1);
    circularQueue.queue(2);
    circularQueue.queue(3);
    circularQueue.queue(4);
    circularQueue.queue(5);
    circularQueue.queue(110);
    circularQueue.queue(20);
    circularQueue.queue(12);
    circularQueue.queue(0);
    int value_three;
    circularQueue.dequeue(value_three);
    circularQueue.dequeue(value_three);

    circularQueue.display();
    cout << "(CircularQueue) Search By Value => " << value_three << endl;

    cout << "-----------------------------------" << endl;

    return 0;
}