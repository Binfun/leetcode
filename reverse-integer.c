//https://leetcode.com/problems/reverse-integer/#/solutions
int reverse(int x) {
        int p_n = 0, r = 0;
        unsigned int stad = -1;stad /= 20;
        if (x > 0)
                p_n = 1;
        else
                x = -x;
        if (x < 0)
                return 0;//except the 0x80000000
        while(x){
                if ((r) > stad)
                        return 0;
                r *= 10;
                r += x % 10;
                x /= 10;
        };
        if (p_n) 
                return r;
        else
                return -r;
}
