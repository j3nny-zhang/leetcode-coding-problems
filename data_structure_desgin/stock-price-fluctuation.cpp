/*
You are given a stream of records about a particular stock. Each record contains a timestamp and the corresponding 
price of the stock at that timestamp.

Unfortunately due to the volatile nature of the stock market, the records do not come in order. Even worse, some records may be incorrect.
Another record with the same timestamp may appear later in the stream correcting the price of the previous wrong record.

Design an algorithm that:

Updates the price of the stock at a particular timestamp, correcting the price from any previous records at the timestamp.
Finds the latest price of the stock based on the current records. The latest price is the price at the latest timestamp recorded.
Finds the maximum price the stock has been based on the current records.
Finds the minimum price the stock has been based on the current records.
Implement the StockPrice class:

StockPrice() Initializes the object with no price records.
void update(int timestamp, int price) Updates the price of the stock at the given timestamp.
int current() Returns the latest price of the stock.
int maximum() Returns the maximum price of the stock.
int minimum() Returns the minimum price of the stock.

*/

class StockPrice {
    unordered_map<int, int> timeStamps; // {timestamp, stock price}
    int latest = 0; // keep track of the latest timestamp

    priority_queue<pair<int, int>> PQ_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ_MIN;

public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        latest = max(latest, timestamp);

        // update prices set
        PQ_MAX.push({price, timestamp});
        PQ_MIN.push({price, timestamp});
        timeStamps[timestamp] = price;
    }
    
    int current() {
        return timeStamps[latest];
    }
    
    int maximum() {
        while (timeStamps[PQ_MAX.top().second] != PQ_MAX.top().first) { // incorrect value
            // need the heap to match the key, value pair in our map
            PQ_MAX.pop();
        }

        return PQ_MAX.top().first;
    }
    
    int minimum() {
        while (timeStamps[PQ_MIN.top().second] != PQ_MIN.top().first) { // incorrect value
            // need the heap to match the key, value pair in our map
            PQ_MIN.pop();
        }

        return PQ_MIN.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
