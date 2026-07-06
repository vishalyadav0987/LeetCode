class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(
            nums.begin(), nums.end(), [](const string &x, const string &y) {
                string a = x;
                string b = y;
                // removing leading zeros
                while (a.size() > 1 && a[0] == '0')
                    a.erase(0, 1);
                while (b.size() > 1 && b[0] == '0')
                    b.erase(0, 1);

                // checking size of string
                if (a.size() != b.size()) {
                    return a.size() > b.size();
                }

                // lexicographical comparison
                return a > b;
            });
        return nums[k-1];
    }
};