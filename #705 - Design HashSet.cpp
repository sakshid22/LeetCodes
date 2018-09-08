//705

class MyHashSet {
    
    vector <bool> hashSet;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
      
       for(int i=0; i<=1000000 ; i++)
          hashSet.push_back(false);
    }
    
    void add(int key) {
          hashSet[key] = true;
    }
    
    void remove(int key) {
          hashSet[key] = false;  
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
         return hashSet[key];  
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */