```c
int romanToInt(char* s) {
    int r = 0;
    do {
        switch (s[0]) {
            case 'I':
                if (s[1] == 'V') {
                    s += 2;
                    r += 4;
                }
                else if (s[1] == 'X') {
                    s += 2;
                    r += 9;
                }
                else {
                    s += 1;
                    r += 1;
                }
                break;
            case 'X':
                if (s[1] == 'L') {
                    s += 2;
                    r += 40;
                }
                else if (s[1] == 'C') {
                    s += 2;
                    r += 90;
                }
                else {
                    s += 1;
                    r += 10;
                }
                break;
            case 'C':
                if (s[1] == 'D') {
                    s += 2;
                    r += 400;
                }
                else if (s[1] == 'M') {
                    s += 2;
                    r += 900;
                }
                else {
                    s += 1;
                    r += 100;
                }
                break;
            case 'V':
                s += 1;
                r += 5;
                break;
            case 'L':
                s += 1;
                r += 50;
                break;
            case 'D':
                s += 1;
                r += 500;
                break;
            case 'M':
                s += 1;
                r += 1000;
                break;
            default:
                return -1;                
        }
    }
    while (s[0]);
    return r;
}
```
