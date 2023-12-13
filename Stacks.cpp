//!STACKS
/*
Header: #include <stack>

To create: std::stack<data_type> stack_name;

?LIFO : Last In First Out ( the most recently added element(last in) would be the first element that would be removed(first out) )

*KEY WORDS/FUNCTIONS TO KNOW
    * POP(): used to delete/remove the most recently added element to the stack
    * Push(): Pushes an element to the end of the stack(pov: horizontal-> lying down) aka the top(pov: verticle ->standing up)
    * Top(): retrieve the most recently added element of the stack(pov: hoizontal-> the last element of the stack) (pov:verticle -> the top aka first/most top element of the stack)


Big o notation 
    Pop() = O(1) (constant time) bc dont have to iterate through stack to remove 
    Push()= O(1) (constant time) 
    Top() = O(1) (constant time)  


A stack is basically just a vector. meaning we dont need to know set the size of the stack. 
It will just dynamically set new space in the stack when needed
*/