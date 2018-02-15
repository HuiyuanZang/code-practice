#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_DEGREE   100
typedef struct {
    int coeff[MAX_DEGREE];
    unsigned int hightest;
} *POLYNOMIAL;




#ifdef __cplusplus
}
#endif
#endif

