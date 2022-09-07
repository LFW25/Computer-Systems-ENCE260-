//rect.c

#include <stdint.h>
#include <math.h>
#include "rect.h"

void rect_set(Rect_t* rect, uint32_t width, uint32_t height)
{
    rect->width = width;
    rect->height = height;
}

uint32_t rect_area(const Rect_t* rect)
{
    uint32_t area = (rect->width * rect->height);
    return area;
}

uint32_t rect_perimeter(const Rect_t* rect)
{
    uint32_t peri = (2*(rect->width) + 2*(rect->height));
    return peri;
}
