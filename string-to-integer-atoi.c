int myAtoi(char* str) {
        int positive = 1;
        int r = 0, temp;
        while(*str == ' ')
                str++;
        if (*str == '+' || *str == '-'){
                positive = (*str == '+');
                str++;
        }
        while (*str){
                if (*str >= '0' && *str <= '9'){
                        if (!positive){
                                if (r < ((int)((unsigned int)~0>>1) + 1)/10)
                                        return ((unsigned int)~0>>1) + 1;
                                r *= 10;
                                r -= *str - 0x30;
                        }
                        else{
                                if (r > (int)((unsigned int)~0>>1)/10)
                                        return (unsigned int)~0>>1;
                                r *= 10;
                                r += *str - 0x30;
                        }
                }else
                        break;
                str++;
        }
        if (r > 0 && !positive)
                return ((unsigned int)~0>>1) + 1;
        else if (r < 0 && positive)
                return (unsigned int)~0>>1;
        return r;
}

