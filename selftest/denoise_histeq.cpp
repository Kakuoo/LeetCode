#include <bits/stdc++.h>
using namespace std;

#define KERNEL_SIZE 7
typedef unsigned char Item;

void _MedianFilter(const Item *srcImage, Item *dstImage, int width, int height)
{
    //   Move window through all elements of the srcImage
    for (int m = 1; m < height - 1; ++m)
    {
        for (int n = 1; n < width - 1; ++n)
        {
            //   Pick up window elements
            int k = 0;
            Item window[KERNEL_SIZE * KERNEL_SIZE];
            for (int j = m - 1; j < m + 2; ++j)
                for (int i = n - 1; i < n + 2; ++i)
                    window[k++] = srcImage[j * width + i];

            //   Order elements (only half of them)
            for (int j = 0; j < (KERNEL_SIZE * KERNEL_SIZE / 2 + 1); ++j)
            {
                //   Find position of minimum Item
                int min = j;
                for (int l = j + 1; l < KERNEL_SIZE * KERNEL_SIZE; ++l)
                    if (window[l] < window[min])
                        min = l;

                //   Put found minimum Item in its place
                const Item temp = window[j];
                window[j] = window[min];
                window[min] = temp;
            }

            //   Get dstImage - the middle Item
            dstImage[(m - 1) * (width - 2) + n - 1] = window[4];
        }
    }
}

void MedianFilter(Item *srcImage, Item *dstImage, int width, int height)
{
    //   Check arguments
    if (!srcImage || width < 1 || height < 1)
        return;
    //   Allocate memory for signal extension
    Item *extension = new Item[(width + 2) * (height + 2)];

    //   Check memory allocation
    if (!extension)
        return;

    //   Create srcImage extension
    for (int i = 0; i < height; ++i)
    {
        memcpy(extension + (width + 2) * (i + 1) + 1,
               srcImage + width * i,
               width * sizeof(Item));
        extension[(width + 2) * (i + 1)] = srcImage[width * i];
        extension[(width + 2) * (i + 2) - 1] = srcImage[width * (i + 1) - 1];
    }

    //   Fill first line of srcImage extension
    memcpy(extension,
           extension + width + 2,
           (width + 2) * sizeof(Item));

    //   Fill last line of srcImage extension
    memcpy(extension + (width + 2) * (height + 1),
           extension + (width + 2) * height,
           (width + 2) * sizeof(Item));

    //   Call median filter implementation
    _MedianFilter(extension, dstImage ? dstImage : srcImage, width + 2, height + 2);

    //   Free memory
    delete[] extension;
}


int denoise_histeq(const Item *srcImage,
                   Item *dstImage, int width, int height)
{
    _MedianFilter(srcImage, dstImage, width, height);
}
