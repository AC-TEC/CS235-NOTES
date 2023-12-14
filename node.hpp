#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>
//making a simple to-do list using singly linked lists

//create node 
struct Node{
    std::string Task_;  //hold value(data)
    Node* Next_;        //node pointer named next (a pointer that is able to point to another node address)
};

//make a to-list class with functions
class To_Do_List{

    private:
        Node* Head_; //pointer to the beginning of the linked list
    //we want to keep this private because we dont want to change adress/value it points to
    //bc it is the starting point of out linked list

    public:
    //*constructors
        To_Do_List();  //A constructor to set Head_ as nullptr
        ~To_Do_List(); //A destructor to free memory when it goes out of scope (will free memeory automatically so once i make this then i no longer have to use this code again basically)
        //we use this since everytime we create a new node ("new") is dynamically allocating memory, if we dont free this memory or goes out of scope we will have memory leaks == problems in the code

    //?function

        void addTask(const std::string& action); //const == dont modify value & = work with o.g value
        //here is where we connect each node to essentially create a linked list

        void printTasks() const;
        //we will traverse the linked list and print out the value/data stored in each node

        void clearList();
        //to clear grocery list memory. aka delete/clear whole list
};
#endif


