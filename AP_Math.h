#ifndef AP_MATH_H
#define AP_MATH_H

#include <math.h>
#include <stdint.h>

#ifndef M_PI_F
#define M_PI_F 3.141592653589793f
#endif
#ifndef M_2PI_F
#define M_2PI_F (2*M_PI_F)
#endif
#ifndef PI
# define PI M_PI_F
#endif
#ifndef M_PI_2
# define M_PI_2 1.570796326794897f
#endif

static inline float constrain_float(float amt, float low, float high)
{
    // the check for NaN as a float prevents propogation of
    // floating point errors through any function that uses
    // constrain_float(). The normal float semantics already handle -Inf
    // and +Inf
    if (isnan(amt)) {
        return (low+high)*0.5f;
    }
    return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

#endif // AP_MATH_H