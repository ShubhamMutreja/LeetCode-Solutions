class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> s;
    int size;
    RandomizedSet() {
        this->size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) != s.end())
            return false;
        s.insert(val);
        this->size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
            s.erase(val);
            this->size--;
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(size == 0)
            return NULL;
        auto it = s.begin();
        int r = rand() % size;
        advance(it,r);
        return *it;
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
