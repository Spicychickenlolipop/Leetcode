class Solution {
public:
    int fun(int m, int n, int guess){
        int count = 0;
        for(int i=1;i<=m;i++){
            count += min(guess/i,n);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int res =-1;
        while(low<=high){
            int guess = low+(high-low)/2;
            int cnt = fun(m,n,guess);
            if(cnt<k){
                low = guess+1;
            }else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};