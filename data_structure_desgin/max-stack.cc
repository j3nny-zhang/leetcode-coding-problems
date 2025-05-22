/*
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, 
only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

*/

class MaxStack {
    // use ordered set to allow for finding elements, while finding the max easily
    set<pair<int, int>> maintainMax; // {value, id}
    set<pair<int, int>> maintainStack; // {id, value}
    int id = 0;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        maintainMax.insert({x, id});
        maintainStack.insert({id, x});
        id += 1;
    }
    
    int pop() {
        auto p = *maintainStack.rbegin(); // biggest id so far -> ie most recent
        maintainStack.erase(p);

        maintainMax.erase({p.second, p.first});
        return p.second;
    }
    
    int top() {
        return maintainStack.rbegin()->second;
    }
    
    int peekMax() {
        return maintainMax.rbegin()->first;
    }
    
    int popMax() {
        auto p = *maintainMax.rbegin();
        maintainMax.erase(p);

        maintainStack.erase({p.second, p.first});
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
