#include <map>
#include <string>
#include <utility>

using namespace std;

class TimeMap {
public:
    map<pair<string, int>, string> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[{key, timestamp}] = value;
    }

    string get(string key, int timestamp) {
        auto it = m.upper_bound({key, timestamp});

        if (it == m.begin()) {
            return "";
        }

        --it;

        if (it->first.first == key) {
            return it->second;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new
**/