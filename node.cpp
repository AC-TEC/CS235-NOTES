#include "node.hpp"
//making a simple to-do list using a singly linked list

//constructor to set head to null
To_Do_List::To_Do_List() : Head_(nullptr) {}

//deconstructor to free up memory / clear the list
To_Do_List::~To_Do_List(){
    clearList();
}

//* purpose of the temorary pointer is that its what we use to traverse through the linked list think of it as the arrow in the actual diagram 
void To_Do_List::addTask(const std::string& action){
// 1.create a node pointer to point to new node
// 2.check if the Head_ node pointer is nullptr. if it is means linked list is empty so we should set the Head_ pointer to the newNode that was created
// 3.else if Head_ is not a nullptr(meaning list is not empty and already pointing to a node) 
// 4. traverse through linked list
        //set a temporary pointer to the first node (Head_) meaning we will start at the head
        //condition for while loop:  while the next node is not nullptr (means while there are nodes in the list) keep on iterating until we reach the end
        //update the current pointer to pint to the next node 
// 5. linking the node aka insertion: set the the next pointer of the last node to the newNode 
        //so current->next = newNode

    //create a new node 
    Node* newNode = new Node{action,nullptr}; //with data and not pointing to anything yet 

    //set the head pointer of linked list to a newly created node if the lists is empty/head_ node of lists does not exist.  then it makes head_ point to a newly created node
    
    if (Head_ == nullptr){ //checks if the list is empty, meaning there are no nodes in the linked list yet
        Head_  = newNode; //if it is empty make the Head_ pointer(start of the linked list) point to a new node(NewNode). which makes the new node the first and only node in the linked list
    } else {
        //if head != nullptr. meaning head_ ptr already points to something meaning list is not empty then the following code will execute
        Node* current =  Head_; //set a pointer to the first node //current is basically a temporary pointer with the purpose of using it to traverse a list.(it starts at the beginning, Head_, and then moves through each node until it reaches the end)  (basically holds the adress of the first node aka Head_)
        while(current->Next_ != nullptr){ //while the next pointer that is being pointed to is not a nullptr (meaning we will loop until we get to a node that does not point to another node. when we do get to a node that points to nullptr, it mean that we have reached the end of the linked lists)
            //so while the next pointer in the lists still points to another node continue iterating through the linked list
            current = current->Next_; //updates the current pointer to point to the next node in the list until we which a pointer that points to nullptr(aka nd of list) 
            //moves to next node. used to move the current pointer to the next node in the list 
        }
        //this part links the newnode (this is that part that will link the node to create the "linked" list)
        current->Next_ = newNode;  //this is also know as insertion //this is that part that essentially connects the nodes
        //this line used to set the Next_ pointer of the last node to point to the newNode which essentially links the last node of the linked list to the newNode
    }
}

//to print linked list
//essentially itertate through linked list
    //1. set temporary pointer(current) to head_ (means we starting at the first node)
    //2. Itertate: while temp(current) is not nullptr keep going until you reach the end of the list
    //3. print out the data/value stored in the node so temp->value_
    //4. 

void To_Do_List::printTasks() const{
    //set a temproary pointer to point at the first node(Head_)
    //temporary pointer we use to traverse through linked list

    Node* current = Head_; //make temp pointer = start of linked list(first node)
    //iteration
    //while the Next_ pointer of the current node(in this case first node) is not nullptr then we will keep on going through linked list
    while(current != nullptr){
        std::cout << current->Task_ << std::endl; //prints out the data/value stored in each node
        current = current->Next_; //update the current pointer to point to the next node in list 
    }
    //dont add current->Next_ = newNode since we are not going to be inserting a new node at the end of the list we are just printing 
}

void To_Do_List::clearList() {
    //iterate through entire list starting from the head

    while(Head_ != nullptr){
        Node* current = Head_; //current(temporary) pointer to point at head/start of linked list
        Head_ = Head_->Next_; 
        delete current;
    }
}