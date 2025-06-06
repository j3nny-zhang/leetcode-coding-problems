/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
 

Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]
*/

class MovingAverage {
    int window;
    queue<int> q;
    double sum = 0;
public:
    MovingAverage(int size) {
        this->window = size;
    }
    
    double next(int val) {
        if (q.size() == window) {
            sum -= q.front();
            q.pop();
        }

        sum += val;
        q.push(val);

        return (sum / q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
