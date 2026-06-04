class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int low=0, high=n-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(a[guess]==target)
            return guess;

            if(a[guess]>a[n-1]){
                if(a[guess]<target)
                low=guess+1;
                else{
                    if(a[0]>target)
                    low=guess+1;
                    else
                    high=guess-1;
                }
            }
            else{
                if(a[guess]>target){
                    high=guess-1;
                }
                else{
                    if(a[n-1]<target)
                    high=guess-1;
                    else
                    low=guess+1;
                }
            }
        }
        return -1;
    }
};