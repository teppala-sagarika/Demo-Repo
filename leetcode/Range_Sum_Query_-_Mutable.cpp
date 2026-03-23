// ────────────────────────────────────────────────────────────
// Problem : Range Sum Query - Mutable
// Platform: LeetCode
// URL     : https://leetcode.com/problems/range-sum-query-mutable/submissions/1956676644/
// Language: cpp
// Date    : 3/23/2026, 5:58:36 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(log n) for update
// Space Complexity: O(4n)
// Notes           : Seg Tree => inside = return val, outside = -inf , partial overlap = check left+ryt
// ────────────────────────────────────────────────────────────

class NumArray {
public:
    vector<int> seg;
    int n;
    //build
    void buildTree(vector<int> &nums,int pos,int l,int r){
        if(l==r){
            seg[pos]=nums[l];
            return;
        }
        int m=(l+r)/2;
        buildTree(nums,2*pos+1,l,m);
        buildTree(nums,2*pos+2,m+1,r);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    //update
    void SegUpdate(int pos,int l,int r,int idx,int val){
        //outside / no overlap 
        if(idx<l || idx>r){
            return;
        }
        //inside / tot overlap
        if(idx==l && idx==r){
            seg[pos]=val;
            return;       
        }
        //partial overlap
        int m=(l+r)/2;
        SegUpdate(2*pos+1,l,m,idx,val);
        SegUpdate(2*pos+2,m+1,r,idx,val);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    //range 
    int SegRange(int qlow, int qhigh, int l, int r, int pos){
        if (qlow <= l && qhigh>= r){ // total overlap
            return seg[pos];
        }
        if (qlow > r || qhigh < l) { // no overlap
            return 0;
        }
        // partial overlap
        int mid = l+(r-l)/2;
        return (SegRange(qlow, qhigh, l, mid, 2*pos+1) + SegRange(qlow, qhigh, mid+1, r , 2*pos+2));
    }

    NumArray(vector<int>& nums) {
           if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*n,0); 
            buildTree(nums, 0, 0, n-1); 
        }
    }
    
    void update(int index, int val) {
        if(n==0) return;
        SegUpdate(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return SegRange(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */