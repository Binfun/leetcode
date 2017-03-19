char* longestPalindrome(char* s) {
        int len  = strlen(s);
        int start, l, r;
        int max_len = 0, max_left = 0;
        for (start = 0; start < len && len - start > max_len/2;){
                l = r = start;
                while (r < len - 1 && s[r + 1] == s[r])
                        r++;
                start = r + 1;
                while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1]){
                        l--;r++;
                }
                if (r - l + 1 > max_len){
                        max_len = r - l + 1;
                        max_left = l;
                }
        }
        s[max_left + max_len] = '\0';
        return &s[max_left];
}
