class KthLargest {
public:
    // Min-heap to store the K largest elements.
    // The smallest of these K elements (the K-th largest overall) will be at the top.
    priority_queue<int, vector<int>, greater<int>> pq;
    int K; // To store k

    KthLargest(int k, vector<int>& nums) {
        K = k; // Store k
        
        // Process all initial elements to build the initial min-heap of size K
        for (int num : nums) {
            pq.push(num);
            // Maintain the size of the heap to be at most K
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        // Always add the new value
        pq.push(val);
        
        // If the size exceeds K, remove the smallest element (the one at the top)
        if (pq.size() > K) {
            pq.pop();
        }
        
        // Special case: If the heap is still empty after the initial setup 
        // and add() is called, this will crash. The problem constraints usually 
        // guarantee k >= 1 and eventually enough elements, but a check is safest.
        if (pq.empty()) {

             return -1;
             }

        return pq.top();
    }
};

