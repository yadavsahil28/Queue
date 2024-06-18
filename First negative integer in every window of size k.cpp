vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    vector<long long> ans;
    deque<long long> q;
    for(int i=0; i<K; i++){
        if(A[i] < 0){
            q.push_back(i);
        }
    }
    if(!q.empty()){
        ans.push_back(A[q.front()]);
    }
    else{
        ans.push_back(0);
    }
    for(int i=K; i<N; i++){
        
        if((!q.empty()) && q.front() < i-K+1){
            q.pop_front(); 
        }
        
        if(A[i] < 0){
            q.push_back(i);
        }
        
        if(!q.empty()){
            ans.push_back(A[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    
    return ans;
 }
