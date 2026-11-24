class MinStack {
public:
    stack<long long>st;
    long long int minValue;
    // here special key is these formula
    // val' = 2 * val - minVal (that why we using long, multiple with 2 with int)
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minValue = value;
        }else{
            if(value < minValue){
                // push here value dash
                st.push((long long)2*value -  minValue);
                minValue = value;
            }else{
               st.push(value); 
            }
        }
    }
    
    void pop() {
        // when i we pop then we want change min value
        if(st.top() < minValue){
            // we have dash value 
            // we have value (here value equal to minValue)
            minValue = 2*minValue - st.top();
        }
        st.pop();
    }
    
    int top() {
        // here logic is when i pop the modify value the how we know that is modified with
        // formula
        // simple mathmatical concept is 
        // minValue is alway greater then is pushed because
        // minValue = -3 
        // and St.top() = -4
        // when our minValue is greater than the expected value then we the formaula
        if(st.top() < minValue){
            return minValue;
        }else{
            return st.top();
        }

    }
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */