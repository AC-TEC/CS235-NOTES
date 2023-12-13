//!STACKS
/*

*!? CHECK OUT NEETCODE.IO STACKS QUESTIONS THAT I DID FOR EXAMPLES

HEADER: #include <stack>

?TO CREATE: std::stack<data_type> stack_name;

*LIFO : Last In First Out ( the most recently added element(last in) would be the first element that would be removed(first out) )

KEY WORDS/FUNCTIONS TO KNOW
    * POP(): used to delete/remove the most recently added element to the stack
    * Push(): Pushes an element to the end of the stack(pov: horizontal-> lying down) aka the top(pov: verticle ->standing up)
    * Top(): retrieve the most recently added element of the stack(pov: hoizontal-> the last element of the stack) (pov:verticle -> the top aka first/most top element of the stack)

!TIP: for push() we have to include either a # or string or char inside the parenthesis when pushing. for example stack.push("Hello")
!      before popping from a stack its good practice to check if the stack is empty first. example if (stack.empty()) -> dont pop or if(stack.size() != 0) -> we can pop

BIG O NOTATION: 
    Pop() = O(1) (constant time) bc dont have to iterate through stack to remove 
    Push()= O(1) (constant time) 
    Top() = O(1) (constant time)  


VIZUALIZATION:
        for me to visualize a stack(HORIZONTAL)
        [5,10] == 5 in first then 10. since 10 is last in its going to be the top element of stack aka end of stack since horizontal
        
        stack from a upward position(VERTICE)
        [10] last in so first out also 10 would be top element in stack 
        [5] 

EXTRA NOTES:
    A stack is basically just a vector. meaning we dont need to know the size of the stack. 
    It will just dynamically set new space in the stack when needed

*/