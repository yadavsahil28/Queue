class ProductOfNumbers {
public:
    vector<int> q;
    ProductOfNumbers() {
        q.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            q.clear();
            q.push_back(1);
        }
        else q.push_back(q.back()*num);
    }
    
    int getProduct(int k) {
        int n = q.size();

        if(k >= n) return 0;        
        
        int ans = q.back()/q[n-k-1];
                      
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
