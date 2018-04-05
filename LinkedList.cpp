#include "LinkedList.h"
template<typename T>
LinkedList<T>::LinkedList(){
    _size = 0;
    head = NULL;
    tail = NULL;  
}
template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T> *temp1;
    Node<T> *temp2;
    while(_size>2){
      temp1 = head->next;
      temp2 = temp1->next;
      delete temp1;
      head -> next = temp2;
      _size --;
    }  
    if(tail!=NULL){
       delete tail;  
    }
    if(head !=NULL){
        delete head;  
    }
}
template<typename T>
int LinkedList<T>::Size(){
    return _size;  
}
template<typename T>
void LinkedList<T>::addNode(int index,T x,T y){
   Node<T> *iterator = head;
   int i = 0;                           //keeps track of where the iterator is
   while(i!=index-1){                   //move the iterator to the pos before the insertion point
      iterator = iterator->next;
      i++; 
   }
   Node<T> *temp = iterator->next;      //keep track of what the new node->next will be
   Node<T> newNode;                     
   newNode->Xpos=x;                     //new nodes Xpos
   newNode->Ypos=y;                     //new nodes Ypos
   iterator->next=newNode;              //link the new node
   newNode->next=temp;
   _size++;                             //increase size of linked list
}
template<typename T>
void LinkedList<T>::removeNode(int index){
  Node<T> *iterator;
  int i = 0;                          //keep track of where the iterator is
  while(i!=index-1){                  //move the iterator to index-1
    iterator = iterator->next;
    i++;  
  }
  Node<T> *temp1=iterator->next;      //the node to be deleted
  Node<T> *temp2 = temp1->next;       //the node to link to iterator after delete
  delete temp1;
  _size--;                            //decrease the size of the list
  iterator->next=temp2;               //link the iterator to the node after the deleted one
}
template<typename T>
void LinkedList<T>::printList(){
  int i = 0;
  Node<T> *iterator = head;
  Serial.print("Listsize: ");
  Serial.println(_size);
  for(i=0;i<_size;i++){
      Serial.print("Node[");  
      Serial.print(i);
      Serial.print("]: Xpos: ");
      Serial.print(iterator->Xpos);
      Serial.print(" Ypos: ");
      Serial.println(iterator->Ypos);
  }
}
//still need bounds checks 

