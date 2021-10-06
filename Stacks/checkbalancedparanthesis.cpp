/*r a given a string expression containing only round brackets or parentheses,
check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.*/
#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string expression) 
{
     stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i = 0; i < expression.length(); i++)  
    { 
        if (expression[i] == '(' || expression[i] == '['
            ||expression[i] == '{')  
        { 
            // Push the element in the stack 
            s.push(expression[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.empty()) 
            return false; 
  
        switch (expression[i]) { 
        case ')': 
              
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    // Check Empty Stack 
    return (s.empty()); 
}
using namespace std;

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
