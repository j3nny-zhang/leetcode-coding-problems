class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       // klogk with maxheap
       int n = matrix.size();
       priority_queue<int> pq;

       for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (pq.size() == k) {
                    if (pq.top() > matrix[i][j]) {
                        pq.pop();
                    } else {
                        continue;
                    }
                }

                pq.push(matrix[i][j]);
            }
       } 

       return pq.top();
    }
};
