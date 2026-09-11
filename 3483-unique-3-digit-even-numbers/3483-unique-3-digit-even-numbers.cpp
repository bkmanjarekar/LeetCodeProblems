class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> unique3DigNum {};

        for(int i=0;i < digits.size();i++)
        {
            if(digits[i] == 0)
                continue;

            for(int j = 0;j < digits.size();j++)
            {
                if (i == j)
                    continue;

                for(int k=0; k < digits.size();k++)
                {
                    if ((j == k) || (i == k))
                        continue;

                    if(digits[k] % 2 != 0)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    unique3DigNum.insert(num);
                }
            }
        }

        return unique3DigNum.size();
    }
};