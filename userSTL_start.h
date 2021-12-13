/*************************************************************************
** Author : Salvatore DiMaggio
** Program : hw5, q1-6
** Date Created : November 30, 2021
** Date Last Modified : December 12, 2021
** Usage : No command line arguments
*/

#ifndef HW5_USERSTL_START_H
#define HW5_USERSTL_START_H

template< class T >
class Node {
public:
    Node(const T& theData, Node<T>* theLink)
            : data(theData), link(theLink){}
    Node<T>* getLink( ) const { return link; }
    const T& getData( ) const { return data; }
    void setData(const T& theData) { data = theData; }
    void setLink(Node<T>* pointer) { link = pointer; }
    friend class MyList;
private:
    T data;
    Node<T> *link;
};

template< class T > void insertHead( Node< T >*& head, const T& theData);
template<class T> void insert(Node<T>* afterMe, const T& theData);
template<class T>  T deleteNode(Node<T>* before);
template<class T> void deleteHead(Node<T>*& head);
template<class T> bool search(Node<T>* head, const T& target);
template<class T> void display (Node<T>* head);
template<class T> bool searchDeque(std::deque<struct Profile> *pq, Profile &president);

template< class T >
class MyList {
public:
    MyList();
    MyList(const T& theData, Node<T>* theLink)
            : data(theData), link(theLink){}
    Node<T> *head;
};

#endif //HW5_USERSTL_START_H
