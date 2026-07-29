class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
         if(a.size() > b.size()){
            return findMedianSortedArrays(b , a);
        }
        
        int m = a.size(); 
        int n = b.size(); 
        
        int l = 0 ; 
        int r = m ;
        
        
        while(l <= r){
           int px = l + (r - l) / 2;
            int py = (m+n+1)/2-px;
            
            
            int x1 = (px == 0 ) ? INT_MIN : a[px-1];
            int x2 = (py == 0 ) ? INT_MIN : b[py-1];
            
            int x3 =   (px == m) ? INT_MAX :a[px];
            int x4 =  (py == n) ? INT_MAX : b[py];
            
            
            if(x1 <= x4 && x2 <= x3){
                if((m+n)%2 == 1){
                    return max(x1 , x2);
                }
                return (max(x1 , x2) + min(x3 , x4))/2.0;
            }
            
            
            if(x1>x4){
                r = px -1 ;
            }
            else {
                l = px +1 ;
            }
        }
        
        return -1 ; 
    }
};
