class MinStack {
public:
    
    /** initialize your data structure here. */
    stack<long long int> st;
    long long int minSf;
    MinStack() {    }
    void push(int x) {
        if(st.empty())
        {
            st.push(x);
            minSf = x;
            return;
        }
        if(x < minSf)
        {
            st.push((x-minSf) + x);
            minSf = x;
        }
        else
        {
            st.push(x);
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top() < minSf)
            minSf = (minSf - st.top()) + minSf;
        st.pop();
    }
    
    int top() {
        if(st.top() < minSf)
            return minSf;
    
        return st.top();
        
    }
    
    int getMin() {
        return minSf;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
