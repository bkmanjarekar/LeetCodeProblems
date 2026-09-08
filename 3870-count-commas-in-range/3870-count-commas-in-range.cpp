class Solution {
public:
    int countCommas(int n) {
        int comma = 0;
        
        if(n < 1000)
        {
            comma = 0;
        }
        else if(n < 1e5)
        {
            comma = n - 999;
        }
        else
        {
            comma = 99001;
        }

        return comma;
    }
};