SignMag_t signMag_read(void)
{
    char c;
    bool isNeg = 0;
    uint8_t i = 0;
    uint64_t num = -1;

    c = getchar();
    if (isdigit(c) || ((c == '-') || (c == '+'))) {
        printf("First char is a digit or a valid prefix.\n");
        i++;
        if (c == '-') {
            isNeg = 1;
        }
    }

    while (((isdigit(c)) || (c == '-') || (c == '+')) && (i > 0)) {
        printf("Old Number: %ld\n", num);
        printf("Digit: %c\n", c);
        if (num == -1) {
            printf("This must be the first digit or the prefix.\n");
            num = 0;
        }
        if (isdigit(c)) {
            printf("This is a digit!\n");
            num = (c - '0') + (10 * num);
            printf("New Number: %ld\n", num);
        } else {
            printf("This is a prefix.\n");
        }
        c = getchar();
        i++;
    }
    printf("While loop has exited.\n");
    if (num == -1) {
        num = 0;
        isNeg = 1;
        printf("It has detected that the program is invalid.\n");
    } else if (num > 65535) {
        printf("Overflow.\n");
        num = 65535;
    }
    
    SignMag_t newMag;
    newMag = signMag_init(isNeg, num);
    return newMag;
}