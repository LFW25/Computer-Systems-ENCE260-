# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>

typedef enum {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} Month_t;

typedef struct {
    uint8_t day;
    Month_t month;
    uint16_t year;

} Date_t;



Date_t setDate(uint8_t day, uint8_t month, uint16_t year)
{
    
    Date_t newDate = {day, month, year};
    return newDate;
}

void printDate(const Date_t* date)
{   
    char* monthName[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("%d %s %d\n", date->day, monthName[date->month], date->year);
}

int main(void) {
    Date_t date = setDate(20, 7, 1969);
    printDate(&date);
}
