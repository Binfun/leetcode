//https://leetcode.com/problems/valid-parentheses/#/description
bool isValid(char* s) {
        if (strlen(s) & 1)
                return false;
        int flag_len = strlen(s) + 1;//strlen(s)/2 + 2; //1 is the first void, 1 is the last for overflow
        char *pre_flag = malloc(flag_len);
        *pre_flag = 0;
        int cnt = 0;
        while(*s){ //&& cnt < flag_len - 1){
                switch (*s){
                        case '(':
                        case '[':
                        case '{':
                                pre_flag[++cnt] = *s;
                                break;
                        case ')':
                                if (pre_flag[cnt] != '(')
                                        return false;
                                cnt--;
                                break;
                        case ']':
                                if (pre_flag[cnt] != '[')
                                        return false;
                                cnt--;
                                break;
                        case '}':
                                if (pre_flag[cnt] != '{')
                                        return false;
                                cnt--;
                                break;
                        default:
                                break;

                }
                s++;
        }
        free(pre_flag);
        if (cnt == 0)
                return true;
        return false;
}
