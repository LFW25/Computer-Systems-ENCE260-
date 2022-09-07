#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <ctype.h>

void readString(char* string, size_t max_string_length)
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
    
}

FILE* openInputFile(char* filename)
{
    FILE* inFile;
    char mode[] = "r";
    inFile = fopen(filename, mode);
    if (inFile == NULL) {
        printf("Input file can't be opened\n");
    }
    return inFile;
}

FILE* openOutputFile(char* filename)
{
    FILE* outFile;
    char mode[] = "w";
    outFile = fopen(filename, mode);
    if (outFile == NULL) {
        printf("Output file can't be opened\n");
    }
    return outFile;
}

int main(void)
{
    char inFileName[81];
    char outFileName[81];
    FILE* inFile;
    FILE* outFile;    

    readString(inFileName, 80);
    readString(outFileName, 80);
    
    inFile = openInputFile(inFileName);
    outFile = openOutputFile(outFileName);

    if (inFile != NULL && outFile != NULL) {
        char c;
        size_t i = 0;
        bool nextCap = 0;
        do {
            c = getc(inFile);

            if (c != -1) {

                if (i == 0) {
                    putc(toupper(c), outFile);
                } else {

                    if (isspace(c) != 0) {
                        nextCap = 1;
                        putc(c, outFile);
                        
                    } else if (nextCap == 1) {
                        putc(toupper(c), outFile);
                        nextCap = 0;

                    } else {
                        putc(tolower(c), outFile);

                    }
                }
                i += 1;
            }

        } while (c != -1);
    }
    if (inFile != NULL) {
        fclose(inFile);
    }
    if (outFile != NULL) {
        fclose(outFile);
    }

}
