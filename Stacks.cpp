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

ITERATE:
    To itertate through a stack its different than a list or vector. A stack does not provide direct access to its elements in this way.
    (for example in array you can do array[i] in a for loop to iterate) in a stack you can't do that

    *Need to use a while loop to iterate a stack


EXTRA NOTES:
    A stack is basically just a vector. meaning we dont need to know the size of the stack. 
    It will just dynamically set new space in the stack when needed

*/



#include <iostream>
#include <stack>
//example of a simple stack


int main(){
//created stack 
std::stack<int> example_stack; 

//add elements to stack
                        //verticle
example_stack.push(1);  //  5 (top of stack) since 5 was added last
example_stack.push(2);  //  4
example_stack.push(3);  //  3
example_stack.push(4);  //  2
example_stack.push(5);  //  1   
//Horizontal: [1,2,3,4,5] top of stack = 5 since added last/recently added


//*TRAVERSE THROUGH A STACK
//print elements of stack before poping an element 

std::cout << "stack before popping " << std::endl;
while(example_stack.size() != 0){
    //will repeat until stack is empty
    std::cout << example_stack.top() << " ";; //print top element of stack
    example_stack.pop(); //remove the top element of stack to get to the next element/top element of stack
}
// OUTPUT: [5,4,3,2,1]

std::cout << std::endl;


//add elements to stack again since we popped them for printing
example_stack.push(1);  
example_stack.push(2);  
example_stack.push(3);  
example_stack.push(4);  
example_stack.push(5);  


example_stack.pop(); //remove top/recently most added element of stack.  removed: 5


std::cout << "stack after popping: " << std::endl;
//print stack after poping element
while(!example_stack.empty()){
    std::cout << example_stack.top() << " ";;
    example_stack.pop();
}

//OUTPUT: [4,3,2,1]

}

