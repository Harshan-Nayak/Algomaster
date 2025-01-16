class BrowserHistory {
public:
    int pos = 0;
    vector<string> vec;
    BrowserHistory(string homepage) { vec.push_back(homepage); }

    void visit(string url) {
        int size = vec.size();
        int n = size - pos;
        n -= 1;
        while (n--) {
            vec.pop_back();
        }
        vec.push_back(url);
        pos++;
    }

    string back(int steps) {
        if (pos < steps) {
            steps = pos;
        }
        pos -= steps;
        return vec[pos];
    }

    string forward(int steps) {
        int size = vec.size();
        if (pos + steps >= size) {
            pos = size - 1;
        } else {

            pos += steps;
        }
        return vec[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */