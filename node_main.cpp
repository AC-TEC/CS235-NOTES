#include "node.hpp"
//making a simple to-do list using singly linked lists

int main(){
    //create a To_Do_List object to test functions
    To_Do_List list;
    std::cout << "***TO DO LIST***" << std::endl;
    list.addTask("Do Bed");
    list.addTask("Brush Teeth");
    list.addTask("Wash face");

    list.printTasks();
}