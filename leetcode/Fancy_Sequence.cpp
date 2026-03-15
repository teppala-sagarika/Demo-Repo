// ────────────────────────────────────────────────────────────
// Problem : Fancy Sequence
// Platform: LeetCode
// URL     : https://leetcode.com/problems/fancy-sequence/submissions/1948850133/?envType=daily-question&envId=2026-03-15
// Language: cpp
// Date    : 3/15/2026, 12:52:24 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(op)
// Space Complexity: O(N)
// Notes           : binary expo + fermat's theorem
// ────────────────────────────────────────────────────────────

class Fancy {
public:
    long long M=1e9+7;

    vector<long long> seq;
    long long add=0;
    long long mult=1;

    //Binary Exponentiation for Fermat's Little Theorem -> pow(mul,M-2)
    long long power(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=power(a,b/2);
        long long res=(half*half)%M;
        if(b%2==1){
            res=(res*a)%M;
        }
        return res;
    }
    Fancy() {
        
    }
    
    void append(int val) {
        long long x=((val-add)%M+M)* power(mult,M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add=(add+inc)%M;
    }
    
    void multAll(int m) {
        mult=(mult*m)%M;
        add=(add*m)%M;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()){
            return -1;
        }
        return (seq[idx]*mult+add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */