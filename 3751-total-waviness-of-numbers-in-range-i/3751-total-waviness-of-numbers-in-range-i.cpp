class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;

        for(int num = num1; num<=num2;num++){
            int nextnext = -1;
            int next = -1;
            int tempnum = num;
            while(tempnum){
                if(nextnext == -1){
                    nextnext = tempnum % 10;
                }else if(next == -1){
                    next = tempnum % 10;
                }else{
                    int cur = tempnum%10;
                    if((cur < next && next > nextnext)||
                        (cur > next && next <nextnext))
                        waviness++;
                    nextnext = next;
                    next = cur;
                }
                tempnum /= 10;
            }
        }
        return waviness;
    }
};