/*
 * The function provides the RHS of the following system of two 
 * first order differential equations, which describe 
 * the structure of a white dwarf star
 *
 *   m' = r^2*p
 *   p' = (-3*m*p*sqrt(1+p^(2/3))) / (r^2*p^(2/3))
 *
 * Here m is the dimensionless mass of the star, 
 * p (rho) is the dimensionless density, 
 * and r is the dimensionless radius of the star
 * 
 */

#include <stdio.h>
#include <math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

int
func (double r, const double y[], double f[], void *params)
{
    /*
     * y[0] - mass, m
     * y[1] - density, p
     * 
     */

    if (y[1] > 0)
    {
        double c0 = *(double *) params;

        f[0] = r * r * y[1];
        if (r > 0.00001)
        {
            f[1] = -3 * y[0] * y[1] * sqrt (1 + pow (y[1], 2. / 3)) / (r * r * pow (y[1], 2./3));
        }
        else
        {
            f[1] =
                -4 * M_PI * r * c0 * y[1] * sqrt (1 + pow (y[1], 2. / 3)) / (pow (y[1], 2./3));
        }
    }
    else
    {
        f[0] = 0.;
        f[1] = 0.;
    }
    return GSL_SUCCESS;
}
