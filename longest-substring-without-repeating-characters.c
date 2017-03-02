//https://leetcode.com/problems/longest-substring-without-repeating-characters/?tab=Solutions
int lengthOfLongestSubstring(char* s) {
        int i, j, l = 0, start = 0;
        for (i = 0; i < strlen(s); i++){
                for (j = start; j < i; j++){
                        if (s[i] == s[j]){
                                l = i - start > l ? i - start : l;
                                start = j + 1;
                        }
                }
        }
        return (i - start > l ? i - start : l);
}
