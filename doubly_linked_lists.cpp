//!Doubly linked list

/*
Node:
    contains
    1. data/value
    2. pointer to next node in the doubly linked list
    3. pointer to previous node

Doubly linked list:
    Definition: A doubly linked list is a type of linked list where each node contains a data part and two pointers - one pointing to the next node (like in a singly linked list) and another pointing to the previous node.
    vizualize:  Imagine a row of cars where each car has a front and a back. In a doubly linked list, each "car" (node) not only knows what's in front of it but also what's behind it.
    Similar to linked list. Difference is that we are also able to traverse backwards. Also a doubly linked list takes up more memory than a linked list

*/

//*Example

#include <iostream>
#include <string>

//create a node
struct Doubly_Node{
    std::string value;  //data
    Doubly_Node* Next_ptr;  //pointer to next node
    Doubly_Node* Prev_ptr;  //pointer to previous node
};


class doubly_linked_list{
    private:
        Doubly_Node* Head_ptr; //we will set this to null at the constructor 

    public:
        //constrcutor to initialize Head_ptr to nullptr
        doubly_linked_list() : Head_ptr(nullptr){}

        //function to add items to list
        void add_items(const std::string& add_item){
            //create a new node
            Doubly_Node* new_item_node = new Doubly_Node {add_item,nullptr,nullptr}; //value,next_ptr,prev_ptr //set value.set pointer to null
            
            //check if list is empty. if it is then make the New Doubly_Node the head aka start of the list
            if(Head_ptr == nullptr){
                //make the Head_ptr point to the new node created
                Head_ptr = new_item_node;
            } else { 
                //when we already have the starting node of the linked list
                //make a temporary pointer which we will use to traverse list, make it point to the aka cause we want to start at the beginning
                Doubly_Node* current = Head_ptr;
                
                //iterate through the doubly linked list
                while(current->Next_ptr != nullptr){
                    current = current->Next_ptr; //update the current pointer to point to the next node (head->next_node)
                }
                //link the current pointer to the new node that we created
                current->Next_ptr = new_item_node; //linking the current node to the next node (essentially creating the linked list)

                //set the previous pointer of the new node to the current(in this case head which is what current is pointing to)
                new_item_node->Prev_ptr = current; //creating the backwards link from the new Node to the previous node which the current pointer is pointing to right now. (essentially creating the doubly linked list) 
                //essentially sets previous pointer of new node to the head node(aka what "current" is pointing to)
            }
        }

        /*
        example
            add_items(A);
                code:
                    new_item_node = [A,nullptr]
                    if(statement){
                        head_ptr = new_item_node;  //?head_ptr -> [A,nullptr]
                    }

            add_items(B);
                code:
                    new_item_node = [B,nullptr]
                    
                    if(statement){
                        !skip if code block bc head_ptr points to a node already
                    } else {
                        Doubly_node* current = Head_ptr //? current points to [A,nullptr] node
                                                                                                                                        [value,next_ptr,prev_ptr = null]
                        while(current->next_ptr != nullptr){   //!skips this block since current->next of the head_ptr points to null ([A,nullptr,nullptr])
                            current = current->next; 
                        }
                            !links the current node to the next/new node we added    [node A]->[node B]
                            current->next_ptr = new_item_node; links the next_ptr of head_ptr(which is null bc [A,Null]) to the new pointer we added. so [A,null] is now [A,&nodeB,null]->[B,nullptr,nulptr]
                            
                            !link the new node to the previous node         [Node A] ->[Node B]
                                                                                    <-
                            new_item_node->prev_ptr = current; sets the prev_pointer of the new node to the previous node. so the new node now also points to the previous pointer, which is head 

                                ?rn current = head_ptr = [nodeA,&nodeB,nullptr] . so now [nodeB, nullptr, &nodeA] 

                                [nodeA,&nodeB,nullptr] -> <-[nodeB, nullptr, &nodeA] 
                                                                nullptr since this is last node it wont point to a next node since there isnt one yet 
                    }
        */

       //print essentiall same this do tmr 12/13/23

};