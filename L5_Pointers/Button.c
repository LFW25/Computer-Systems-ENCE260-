#   include <stdint.h>
#   include <stdbool.h>
#   include <stdio.h>
#   include <ctype.h>

typedef struct {
    uint16_t x, y, width, height;
    void (*buttonFunc)(void);
} Button_t;

Button_t button_init(uint16_t x, uint16_t y, uint16_t width, uint16_t height, void (*buttonFunc)(void))
{
    Button_t newButton = {x, y, width, height, buttonFunc};
    return newButton;
}

void button_click(Button_t* button)
{
    (*(button->buttonFunc))();
}

void clickFunc(void)
{
    puts("Button Clicked!");
}



int main(void)
{
    Button_t button = button_init(480, 320, 64, 32, &clickFunc);
    button_click(&button);
}
