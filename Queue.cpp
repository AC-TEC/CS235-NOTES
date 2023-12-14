//!QUEUES
/*
?Header:
    #include <queue>

?Declare: 
    std::queue<DataType> queue_name;

?FIFO: First In First Out
    Example: 
        Add(1)
            [1] -first in
        Add(2)
            [1,2]
        Add(3)
            [1,2,3]
        remove()
            [2,3] -first one gets removes

?Basic operations:
    push(value) - adds element to back of list (adding a person to end of line)
    pop()       - removes the first element added to list (FIFO) (serving food to first person in line)
    front()     - returns value of first element without removing it.
    empty()     - tells you if the queue is empty or not


?Extra:
If you want to access the last element in the queue, you would need to dequeue elements one by one until you reach the last one.
    example:
    #include <queue>
    int main() {
    std::queue<int> myQueue;

    myQueue.push(42);
    myQueue.push(17);
    myQueue.push(99);

    Dequeue elements until you reach the last one
    while (myQueue.size() > 1) {
        myQueue.pop();
    }

    Now myQueue.front() contains the last element
    std::cout << "Last element: " << myQueue.front() << "\n";
    }


?BIG O NOTATION:
    ENQUEUE AKA push(value) = O(1) (constant time)
    DEQUEUE aka pop()       = O(1) (constant time)

*/

//*example:
#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> rideQueue;

    rideQueue.push("Alice");
    rideQueue.push("Bob");
    rideQueue.push("Charlie");

    std::cout << "Front of the line: " << rideQueue.front() << std::endl;

    rideQueue.pop();

    std::cout << "Now, front of the line: " << rideQueue.front() << std::endl;

    return 0;
}
    //output
        //Front of the line: Alice
        //Now, front of the line: Bob




//*other example

#include <string>

int main() {
    // Declare a queue for our music playlist
    std::queue<std::string> musicPlaylist;

    // Add songs to the playlist
    musicPlaylist.push("Song 1 - Happy Tune");
    musicPlaylist.push("Song 2 - Summer Vibes");
    musicPlaylist.push("Song 3 - Relaxing Melody");

    // Print the current playlist
    std::cout << "Current Playlist:\n";
    while (!musicPlaylist.empty()) {
        std::cout << "- " << musicPlaylist.front() << "\n"; // Display the song at the front
        musicPlaylist.pop(); // Remove the song from the playlist
    }

    // Check if the playlist is empty
    if (musicPlaylist.empty()) {
        std::cout << "The playlist is empty.\n";
    }

    return 0;
}
//output: everything that we have in push




//*Example of queue implemented as a singly linked list


// Node represents each element in the linked list
template <typename T> //using a template so we can add whatever type of data(int,char,string,etc)
struct Node {
    T data;
    Node* next;
    
    //constructor to set the data and next pointer to nullptr
    Node(const T& newData) : data(newData), next(nullptr) {}
};

// Queue implemented using a linked list
template <typename T>
class LinkedListQueue {
private:
    Node<T>* front; // Front of the queue aka head_ptr
    Node<T>* rear;  // Rear of the queue aka tail_ptr

public:
//constructor to set head and tail pointers to nullptr
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue: Add an element to the rear of the queue
    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value); //create a new node already set the data and next pointer in constructor in strcut node
        if (isEmpty()) { //when queue is empty
            front = rear = newNode; //make the head and tail pointer point to the new node we added
        } else { //when queue is not empty 
            rear->next = newNode;  //update the tail pointer to the newNode 
            rear = newNode;     //sets/connects the tail_pointer to the newNode
        } 
    }

    // Dequeue: Remove the element from the front of the queue
    void dequeue() {
        if (isEmpty()) { //when queue is empty
            std::cerr << "Cannot dequeue from an empty queue.\n";
            return;
        } //3 lines below when queue is not empty 
        Node<T>* temp = front; //make a temporary pointer(current) point to the front(head) node of the queue
        front = front->next;  //set the head pointer of the queue to the next node in the queue)list now next node is the new head
        delete temp; //removes the node that was a the front aka the head node(start of queue) since that is what temp was pointer to 
        
        if (front == nullptr) {
            rear = nullptr; // If the queue is empty after dequeue
        }
    }

    // Front: Get the element at the front of the queue
    T frontElement() const {
        if (isEmpty()) {
            std::cerr << "The queue is empty.\n";
            // You might want to handle this differently in your application
            return T();
        }
        return front->data; //return the data stored at the head_ptr aka the head/start of the queue(list)
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr; //when the front(head_ptr) does not point to a node means we have no nodes in the queue(linked list)
    }
};

int main() {
    LinkedListQueue<int> myQueue;

    myQueue.enqueue(42);
    myQueue.enqueue(17);
    myQueue.enqueue(99);

    std::cout << "Front element: " << myQueue.frontElement() << "\n"; //42

    myQueue.dequeue(); //remove 42

    std::cout << "Front element after dequeue: " << myQueue.frontElement() << "\n"; //17

    return 0;
}



