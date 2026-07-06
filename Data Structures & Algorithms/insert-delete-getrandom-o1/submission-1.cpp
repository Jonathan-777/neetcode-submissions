#include <random>
#include <iterator>
class RandomizedSet {
public:
        unordered_set<int> us;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        return us.insert(val).second;
        
    }
    
    bool remove(int val) {
        int size = us.size();
        us.erase(val);
        if(size != us.size())return true;
        return false;
    }
    
    int getRandom() {

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, us.size()-1);
        int random_index = dis(gen);

        auto it = next(us.begin(), random_index);

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