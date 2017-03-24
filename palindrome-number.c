//https://leetcode.com/problems/palindrome-number/#/solutions
bool isPalindrome(int x) {
        int y = 0;
        if (x < 0)
                return 0;
        if (x && x%10 == 0)
                return 0;
        while (x > y){
                y = y*10 + x%10;
                x /= 10;
        }
        return x == y || x == y/10;
}

