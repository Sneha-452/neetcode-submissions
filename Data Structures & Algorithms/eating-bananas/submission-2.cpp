class Solution {
public:
 bool ispossible(vector<int>& arr , int banana , int k){
      int hour =  0;
      for(int i = 0 ; i < arr.size() ; i++){
           hour += arr[i]/banana ; 
          
          if(arr[i] % banana != 0){
              hour ++;
          }
      }
        return (hour<= k) ? true : false;
      
  }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 ; 
        int end = *max_element(piles.begin() , piles.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(ispossible(piles , mid , h)){
                end = mid;
            }
            else{
                start = mid +1 ;
            }
            
        }
        return start ;
        
    }
};
