#include "polynomial.h"




int  mult_polynomial(const POLYNOMIAL poly1, const POLYNOMIAL poly2, POLYNOMIAL poly)
{
    if (poly1->highest + poly2->highest > MAX_DEGREE)
    {
        return -1;
    }
    else
    {
        poly->highest = poly1->highest + poly2->highest;
        for (int i = 0; i < poly1->highest ; i ++)
        {
            for (int j=0; j< poly2->highest; j++)
            {
                poly->coef[i+j] += poly1->coef[i] * poly2->coef[j];
            }
        }
    }

}
