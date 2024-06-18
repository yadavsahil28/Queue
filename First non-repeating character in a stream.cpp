class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char, int> m;
		    queue<char> q;
		    string ans;
		    
		    for(int i=0; i<A.size(); i++){
                char ch = A[i];
                m[ch]++;
                q.push(ch);
                
                while(!q.empty()){
                    if(m[q.front()]>1){
                        q.pop();
                    }
                    else{
                        ans += q.front();
                        break;
                    }
                }
                
                if(q.empty()){
                    ans += '#';
                }
		    }
		    return ans;
		}
};
