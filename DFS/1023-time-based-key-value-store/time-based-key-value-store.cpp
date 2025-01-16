#include <map>
#include <string>
#include <utility>

using namespace std;

class TimeMap {
public:
    // Map to store key -> {timestamp, value} pairs
    map<pair<string, int>, string> m;

    TimeMap() {}

    // Set a key-value pair with a timestamp
    void set(string key, string value, int timestamp) {
        m[{key, timestamp}] = value;
    }

    // Get the value for a key at a specific timestamp
    string get(string key, int timestamp) {
        // Create a pair to search for the upper bound
        auto it = m.upper_bound({key, timestamp});

        // Check if we can retrieve a valid value
        if (it == m.begin()) {
            return ""; // No valid timestamp found
        }

        --it; // Move to the largest timestamp <= given timestamp

        if (it->first.first == key) {
            return it->second; // Return the corresponding value
        }

        return ""; // No valid value found
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key, value, timestamp);
 * string param_2 = obj->get(key, timestamp);
 */
