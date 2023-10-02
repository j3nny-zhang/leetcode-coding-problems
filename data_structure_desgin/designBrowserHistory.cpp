/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward 
in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, 
you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, 
you will forward only x steps. Return the current url after forwarding in history at most steps.
*/


class BrowserHistory {
    vector<string> backward;
    vector<string> front;
public:
    BrowserHistory(string homepage) {
        backward.push_back(homepage);
    }
    
    void visit(string url) {
        backward.push_back(url);
        if (front.size()!= 0) {
            front.clear();
        }
    }
    
    string back(int steps) {
        if (steps > backward.size()) steps = backward.size();
        while (steps > 0) {
          string url = backward.back();  
          backward.pop_back();
          front.push_back(url);
          steps -= 1;
        }
        if (backward.size() == 0) {
            string url = front.back();
            front.pop_back();
            backward.push_back(url);
        }
        return backward.back();
    }
    
    string forward(int steps) {
        if (steps > front.size()) steps = front.size();
        while (steps > 0) {
            string url = front.back();
            front.pop_back();
            backward.push_back(url);
            steps -= 1;
        }
        return backward.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
