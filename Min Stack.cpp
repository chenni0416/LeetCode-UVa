struct node {
        int val;
        int mn;
    };
class MinStack {
public:
    int curr_mn;
    stack<node> sk;
    MinStack() {

    }
    
    void push(int value) {
        curr_mn = sk.empty() ? value : min(value, sk.top().mn);
        node nd = {value, curr_mn};
        sk.push(nd);
    }
    
    void pop() {
        sk.pop();
    }
    
    int top() {
        return sk.top().val;
    }
    
    int getMin() {
        return sk.top().mn;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
//  