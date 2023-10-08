//Time-Based-Key-Value-Store
//Question Link :- https://leetcode.com/problems/time-based-key-value-store/description/

/*
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
    }
    
    string get(string key, int timestamp) {
        
    }
};

 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
*/

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) {
            return "";
        }
        
        auto& values = data[key];
        auto it = upper_bound(values.begin(), values.end(), make_pair("", timestamp), 
                               [](const pair<string, int>& a, const pair<string, int>& b) {
                                   return a.second < b.second;
                               });
        
        if (it == values.begin()) {
            return "";
        }
        return (it - 1)->first;
    }
    
private:
    map<string, vector<pair<string, int>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */