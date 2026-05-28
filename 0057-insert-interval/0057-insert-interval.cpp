class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool insert = false;
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];

            if (insert == false && start >= newInterval[0]) {
                res.push_back(newInterval);
                insert = true;
            }

            res.push_back(intervals[i]);
        }
        // edge case if interval is empt newinterval will never add
        if(insert==false ) {
            res.push_back(newInterval);
            
        }
        
        vector<vector<int>> res2;

        int n1 = res.size();

        int start1 = res[0][0];
        int end1 = res[0][1];

        for (int i = 1; i < n1; i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];
            // merge
            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
            }
            // before updating store the correct ans
            else {
                res2.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        // before finishing store the last interval which has no onw to compare
        res2.push_back({start1, end1});
        return res2;
    }
};