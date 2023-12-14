//! NODES AND LINKED_LIST
/*
HELPFUL VIDEOS:
    Neetcode.io Singly Linked lists video
    https://www.youtube.com/watch?v=o5wJkJJpKtM
    https://www.youtube.com/watch?v=HKfj0l7ndbc&t=448s


Nodes:
    Meaning: Individual element in a linked list.
    -Made as its own class or struct
    -A node has a value (data_type = value)and a pointer for to connect to the next node(Node* Next)

Linked Lists:
    Meaning: A sequence of connected nodes.
    
    To Setup:
        1. Make sure you created a NODE struct/class
        2. As a private data memeber need to make a Node* pointer that pointer to the "Head"(this will keep track of the start of the linked lists)
        3. make a constructor to initialize the head pointer to nullptr  
        4. then you can make a function to insert,remove or print info of the node from the linked list

        !To Insert,remove or print a node in a linked list you would have to traverse through it unless you already have a pointer that points to the last node/position of the node in the linked list 

    Insert Node:
        1.Make a new node(make sure it store you data, points to nullptr)
        2.check if the list is empty by making if statement that checks if Head(ptr) points to null condition = if( head==nulltptr), if it is empty make the Head_ pointer(start of the linked list) point to a new node(NewNode). which makes the new node the first and only node in the linked list
        3.else (when list in not empty so head(ptr) != null) here is where you traverse and add a node/link/connect a new node to the list at your desired position typically the end of the list 
            -you create a temproary pointer(typically called current). Temporary pointer is what you will use to traverse list(if you dont use it and use head ptr instead you will then end up losing the location of the head/start of the list). The current pointer helps you implement the logic for traversing the linked list.
                You can use a while loop to iterate through the list, updating the current pointer in each iteration until you reach the end.
            -make a while loop to traverse condition = (current->next != nullptr). while the next pointer that is being pointed to is not a nullptr (meaning we will loop until we get to a node that does not point to another node. when we do get to a node that points to nullptr, it mean that we have reached the end of the linked lists)
            -inside while loop update the current pointer to point to the next node in list. current = current->next. moves to next node. used to update the current pointer to the next node in the list 
        4.outside of the while loop we connect the current node to the new node essentially creating the linked list
            -So, current->next = newNode; means that you are updating the next pointer of the current node to point to the new node. In other words, you are linking the current node to the new node, effectively adding the new node to the list after the current node.

    Print node:
    essentially itertate through linked list
    1. set temporary pointer(current) to head_ (means we starting at the first node)
    2. Itertate: while temp(current) is not nullptr keep going until you reach the end of the list
    3. print out the data/value stored in the node so current->value
        -we dont do current->next  newNode bc we are not linking a new node to list we just priniting data


    Remove node:
    1.Check if List is Empty:
    If the linked list is empty (head is nullptr), there is nothing to remove.
    
    2.Special Case: Removing the Head:
    If the node to be removed is the head, update the head pointer to point to the next node (or nullptr if it's the only node).
    
    3.General Case: Traverse and Remove:
    Use a temporary pointer (current) to traverse the list until you find the node to remove.
    Keep track of the previous node while traversing (previous), as you need to update its next pointer.
    Update Pointers to Remove Node:

    Once you find the node to remove, update the next pointer of the previous node to skip the current node.
    Delete the node you want to remove (free the memory).



    BIG O NOTATION:
        Insert Node = O(1) (constant time) if you dont have a pointer already that points to where you want to place the node
        Remove Node = O(1) (constant time) same as above
        Print Node  = O(n) (linear time) bc have to traverse through the linked list and then print the data from the node

?Example: check out node.cpp and node.hpp and node_main.cpp

*/



//! BELOW EXAMPLE

#include <iostream>
#include <string>


struct Node{
    std::string value;
    Node* Next_ptr;
};


class linked_list{
    private:
        Node* Head_ptr;

    public:
        //construtor to initialize head to null
        linked_list() : Head_ptr(nullptr){}

        //function to add items to linked list
        void add_items(const std::string& item_added){
            //create a pointer to a new node (value,pointer to next node)
            Node* newNode = new Node{item_added,nullptr};

            //where we add to linked list
            //check if list is empty first
            if(Head_ptr == nullptr){ //if head does not pointer to a node then make it point to new node(essentially makeing the newNode the start of the linked list)
                Head_ptr = newNode;
            } else{ //if Head_ptr does already point to a node(meaning list is not empty) we will add on to the linked list(insert a new node)
                //create a temporary pointer to traverse through linked list
                Node* current = Head_ptr; //make current head_ptr bc we want to start from beginning of linked list
                //itertate
                while(current->Next_ptr != nullptr){ //traverse until we reach a node that points to null (node that points to null means we have reach end of linked list)
                    current = current->Next_ptr; //update the current pointer to point to the next node in list basically moving us to the next node
                }
                //link the current pointer to the new node that we have
                    current->Next_ptr = newNode; //linking the current node to the next/new node to list creating the linked list
            }
        }

        //function to print items(data) in our linked list
        void print_list() const{
            //make temporary pointer to help us traverse
            Node* current = Head_ptr; //to start at beggining
            //traverse
            while(current != nullptr){ //since we already made linked list we will traverse only using current 
            //print out data/value stored in node
                std::cout << current->value << std::endl;
            //move on to the next node
                current = current->Next_ptr;
            }
        }
};


int main(){
    //testing this shit out

    //create a linked_list object
    linked_list list;

    //add items to linked list
    list.add_items("Andy");
    list.add_items("Antony");
    list.add_items("Lesly");

    //print items from linked list
    std::cout << "Printing from linked list" << std::endl;
    list.print_list();
}





