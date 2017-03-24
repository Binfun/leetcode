//https://leetcode.com/problems/longest-common-prefix/#/solutions
char* longestCommonPrefix(char** strs, int strsSize) {
        if (strs == NULL || *strs == NULL)
                return "";

        char* r = malloc(strlen(*strs) + 1);
        int i, j, l = strlen(*strs) + 1;
        int temp;

        strcpy(r, *strs);
        for (i = 1; i < strsSize; i++){
                temp = 0;
                for (j = 0; j < strlen(*strs) + 1; j++){
                        if (strs[i][j] == r[j]){
                                temp++;
                        }else{
                                break;
                        }
                }
                if (l > temp)
                        l = temp;
        }

        r[l] = 0;
        return r;
}

