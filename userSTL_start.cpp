/*************************************************************************
** Author : Salvatore DiMaggio
** Program : hw5, q1-6
** Date Created : November 30, 2021
** Date Last Modified : December 12, 2021
** Usage : No command line arguments
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "userSTL_start.h"
using namespace std;

struct Profile
{
    string fullname;
    string state;
    bool operator==( Profile rhs)
    {if (fullname==rhs.fullname) return true; return false; }

    bool operator!=(Profile rhs)
    {if (fullname!=rhs.fullname) return true; return false; }

};
ostream& operator<< (ostream &out, Profile &user)
{
    out << user.fullname<<"--" <<user.state;
    return out;
}
//define the function below to find a given Profile for which only name is provided. This function should return
//true or false. If it finds the given name, it should also change the value of the second parameter as it's
//passed by reference.
bool searchDeque(deque<struct Profile> *pq, Profile &president);
int main() {
    queue <Profile> pQueue;
    deque <Profile> pDeque;
    Profile temp;
    string line;
    MyList<Profile> pMylist;
//this part is just informative. If you wanna practice how sstream and getline works
    string test = "truck	car";
    string token;
    stringstream ss(test);
    getline(ss, token, '\t');
    cout<<token<<endl;
    getline(ss, token, '\t');
    cout<<token<<endl;

    //let's practice file I/O
    ifstream file("presidentsWstates.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, temp.fullname, '\t');
            getline(ss, temp.state, '\t');
            pMyList.insertHead( temp);
            //use push for your queue to insert president Profiles.
            //use push_front for your deque to insert president Profiles

        }
    }

    cout<<"Printing queue members by using pop and front***********************"<<endl;
//use a while loop by using front and pop function to both empty and print your President profiles.
    while (!Mylist.empty()) {
        cout << ' ' << MyList.top();
        MyList.pop();
    }



    cout<<"Printing deque members with iterator***********************"<<endl;
//use an iterator print your President profiles.
    deque<Profile>::iterator dIter;





//use a for loop which works with indices to print your President profiles.
    cout<<"Printing deque members with indices***********************"<<endl;


//Uncomment below to when you have your search function ready

temp.fullname = "Gerald R. Ford";
if(searchDeque(pDeque, temp))
  cout<<"found:"<<temp<<endl;
else
  cout<<"not found: "<<temp<<endl;

    return 0;
}

bool searchDeque(deque<struct Profile> *pq, Profile &president)
{
    deque<Profile>* here = (deque<struct Profile> *) pq;

    if (here == NULL)  {
        return false;
    }
    else {
        while (here->getData( ) != president && here->getLink( ) != NULL)
            here = here->getLink( );

        if (here->getData( ) == president)
            return true;
        else
            return false;
    }
}

template<class T>
void insertHead(Node<T>*& head, const T& theData) {
    head = new Node<T>(theData, head);
}

template<class T>
void display(Node<T>*head) {
    Node<T>*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->getData()<<endl;
        temp = temp->getLink();
    }
}

template<class T>
void insert(Node<T>* afterMe, const T& theData) {
    afterMe->setLink(new Node<T>(theData, afterMe->getLink( )));
}

template<class T>
void deleteNode(Node<T>* before) {
    Node<T> *discard;
    discard = before->getLink( );
    before->setLink(discard->getLink( ));
    delete discard;
}
template<class T>
T deleteHead(Node<T>*& head) {
    Node<T> *discard;
    discard = head;
    head = head->getLink( );
    delete discard;
}

template<class T>
bool search(Node<T>* head, const T& target) {
    Node<T>* here = head;

    if (here == NULL)  {
        return false;
    }
    else {
        while (here->getData( ) != target && here->getLink( ) != NULL)
            here = here->getLink( );

        if (here->getData( ) == target)
            return true;
        else
            return false;
    }
}