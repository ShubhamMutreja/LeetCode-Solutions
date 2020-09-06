class MedianFinder {
public:
    /** initialize your data structure here. */
    double median;
    priority_queue<double> s;
    priority_queue<double,vector<double>,greater<double>> g;
    MedianFinder() {
        this->median = 0;
        //g.clear();
        //s.clear();
    }
    
    void addNum(int x) {
        if(g.size() < s.size())
        {
            if(x < this->median)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }
            this->median = (s.top() + g.top())/2.0;
        }
        else if(g.size() > s.size())
        {
            if(x > this->median)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
            {
                s.push(x);
            }
            this->median = (s.top() + g.top())/2.0;
        }
        else
        { 
            if (x < this->median) 
            { 
                s.push(x); 
                this->median = (double)s.top(); 
            } 
            else
            { 
                g.push(x); 
                this->median = (double)g.top(); 
            } 
        } 
        
        
    }
    
    double findMedian() {
        return this->median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
