#ifndef LinkedList_h //if Linked list is not defined
#define LinkedList_h // define it

#if (ARDUINO >= 100) // if adruino not defined
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
template<class T> //datatype of T
struct Node{
  T Xpos;
  T Ypos;
  Node<T> *next;
};
template <typename T>
class LinkedList {
  protected:
    int _size;
    Node<T> *head;
    Node<T> *tail;

  public:
    LinkedList();
    ~LinkedList();

    int Size();

    void addNode(int index,T x,T y);

    void removeNode(int index);

    void printList();
  
};
#endif
