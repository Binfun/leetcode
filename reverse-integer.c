//https://leetcode.com/problems/reverse-integer/#/solutions
int reverse(int x) {
        int r = 0;
        unsigned int max_u = -1;max_u /= 20;int max = max_u;
        unsigned int min_u = -1;int min = (min_u/2 + 1);min /= 10;
        while(x){printf("[%d]",r);
                if (r > max || r < min)
                        return 0;
                r *= 10;
                r += x % 10;
                x /= 10;
        };
        return r;
}
