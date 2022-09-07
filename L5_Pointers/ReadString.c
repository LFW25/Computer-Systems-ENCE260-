#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>

size_t readString(char* string, size_t max_string_length)
{
    int c;
    size_t i = 0;

    do {
        
        c = getchar();
        if (c != -1 && c != '\012' && i < max_string_length) {
            string[i] = c;
            i += 1;
        } 
        
    } while ((i <= max_string_length) && (c != -1) && (c != '\012'));
    string[i] = '\0';
    return i;

}

int main(void)
{
    size_t len=0;
    char string[11];
    len = readString(string, 10);
    printf("Read String (%s) of length (%zu)\n", string, len);
}
