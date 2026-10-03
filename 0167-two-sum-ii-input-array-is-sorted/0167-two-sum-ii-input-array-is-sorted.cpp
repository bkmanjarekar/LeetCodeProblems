class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ind(2, 0);

        for(int i=0; i < numbers.size(); i++)
        {
            int f = target-numbers[i];

            if (i != 0) {
                auto it = std::lower_bound(numbers.begin(), numbers.begin() + i, f);

                // lower_bound returns the first element >= target, so check for exact match
                if (it != numbers.begin() + i && *it == f)
                {
                    ind[0] = i + 1;
                    ind[1] = it - numbers.begin() + 1;
                    break;
                }
            }

            auto it1 = std::lower_bound(numbers.begin() + i + 1, numbers.end(), f);
            if (it1 != numbers.end() && *it1 == f)
            {
                ind[0] = i + 1;
                ind[1] = it1 - numbers.begin() + 1;
                break;
            }

        }
        return ind;
    }
};