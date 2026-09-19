class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long reverse = 0;
        if(x < 0){
            return false;
        }
        while(x != 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x = x / 10;
        }
        if(reverse == original){
            return true;
        } else {
            return false;
        }
        
    }
};