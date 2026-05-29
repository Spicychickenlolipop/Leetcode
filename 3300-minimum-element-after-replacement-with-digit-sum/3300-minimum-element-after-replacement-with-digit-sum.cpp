class Solution {
public:
    int minElement(vector<int>& numbers) {
        int size = numbers.size();
        vector<int> digitSums;

        for(int index = 0; index < size; index++){
            int currentNumber = numbers[index];
            int sumOfDigits = 0;

            while(currentNumber > 0){
                int digit = currentNumber % 10;
                sumOfDigits += digit;
                currentNumber = currentNumber / 10;
            }

            digitSums.push_back(sumOfDigits);
        }

        sort(digitSums.begin(), digitSums.end());

        return digitSums[0];
    }
};