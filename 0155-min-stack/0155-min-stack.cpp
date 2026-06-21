// class MinStack { //tc: O(1) sc: O(2*n) //good solution
// public:
//     stack<pair<int, int>> s;
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         if(s.empty()){
//             s.push({value,value});
//         }else{
//             int minVal = min(value, s.top().second);
//             s.push({value,minVal});
//         }
//     }
    
//     void pop() {
//         s.pop();
//     }
    
//     int top() {
//         return s.top().first;
//     }
    
//     int getMin() {
//         return s.top().second;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




 class MinStack { //tc: O(1) sc: O(2*n)
public:
    stack<long long> s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minVal = value;
        }else{
            if(value<minVal){
                s.push((long long) 2*value-minVal);
                minVal = value;
            }else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top()<minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};
