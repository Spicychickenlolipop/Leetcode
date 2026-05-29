class Solution {
public:
    int minElement(vector<int>& numbers) {
        int size = numbers.size();
        int minimumDigitSum = INT_MAX;

        for(int index = 0; index < size; index++){
            int currentNumber = numbers[index];
            int digitSum = 0;

            while(currentNumber > 0){
                int digit = currentNumber % 10;
                digitSum += digit;
                currentNumber = currentNumber / 10;
            }

            if(digitSum < minimumDigitSum){
                minimumDigitSum = digitSum;
            }
        }

        return minimumDigitSum;
    }
};
