#include <iostream>
#include <cmath>

// 1/n! for n= 0 through 99
// unchanging, frequently used
const double n_fact_inv[100] = {
        1, // 1/0!
        1, // 1/1!
        0.5, // 1/2!
        0.166667, // 1/3!
        0.0416667, // 1/4!
        0.00833333, // 1/5!
        0.00138889, // 1/6!
        0.000198413, // 1/7!
        2.48016e-05, // 1/8!
        2.75573e-06, // 1/9!
        2.75573e-07, // 1/10!
        2.50521e-08, // 1/11!
        2.08768e-09, // 1/12!
        1.6059e-10, // 1/13!
        1.14707e-11, // 1/14!
        7.64716e-13, // 1/15!
        4.77948e-14, // 1/16!
        2.81146e-15, // 1/17!
        1.56192e-16, // 1/18!
        8.22064e-18, // 1/19!
        4.11032e-19, // 1/20!
        1.95729e-20, // 1/21!
        8.89679e-22, // 1/22!
        3.86817e-23, // 1/23!
        1.61174e-24, // 1/24!
        6.44695e-26, // 1/25!
        2.4796e-27, // 1/26!
        9.18369e-29, // 1/27!
        3.27989e-30, // 1/28!
        1.131e-31, // 1/29!
        3.76999e-33, // 1/30!
        1.21613e-34, // 1/31!
        3.80039e-36, // 1/32!
        1.15163e-37, // 1/33!
        3.38716e-39, // 1/34!
        9.67759e-41, // 1/35!
        2.68822e-42, // 1/36!
        7.26546e-44, // 1/37!
        1.91196e-45, // 1/38!
        4.90247e-47, // 1/39!
        1.22562e-48, // 1/40!
        2.98931e-50, // 1/41!
        7.11741e-52, // 1/42!
        1.65521e-53, // 1/43!
        3.76184e-55, // 1/44!
        8.35965e-57, // 1/45!
        1.81732e-58, // 1/46!
        3.86663e-60, // 1/47!
        8.05548e-62, // 1/48!
        1.64397e-63, // 1/49!
        3.28795e-65, // 1/50!
        6.44696e-67, // 1/51!
        1.2398e-68, // 1/52!
        2.33925e-70, // 1/53!
        4.33194e-72, // 1/54!
        7.87625e-74, // 1/55!
        1.40647e-75, // 1/56!
        2.4675e-77, // 1/57!
        4.2543e-79, // 1/58!
        7.21068e-81, // 1/59!
        1.20178e-82, // 1/60!
        1.97013e-84, // 1/61!
        3.17763e-86, // 1/62!
        5.04386e-88, // 1/63!
        7.88103e-90, // 1/64!
        1.21247e-91, // 1/65!
        1.83707e-93, // 1/66!
        2.7419e-95, // 1/67!
        4.0322e-97, // 1/68!
        5.84377e-99, // 1/69!
        8.34824e-101, // 1/70!
        1.17581e-102, // 1/71!
        1.63307e-104, // 1/72!
        2.23708e-106, // 1/73!
        3.02308e-108, // 1/74!
        4.03077e-110, // 1/75!
        5.30365e-112, // 1/76!
        6.88785e-114, // 1/77!
        8.83058e-116, // 1/78!
        1.1178e-117, // 1/79!
        1.39724e-119, // 1/80!
        1.72499e-121, // 1/81!
        2.10365e-123, // 1/82!
        2.53452e-125, // 1/83!
        3.01728e-127, // 1/84!
        3.54974e-129, // 1/85!
        4.12761e-131, // 1/86!
        4.74438e-133, // 1/87!
        5.39134e-135, // 1/88!
        6.05769e-137, // 1/89!
        6.73076e-139, // 1/90!
        7.39644e-141, // 1/91!
        8.03961e-143, // 1/92!
        8.64474e-145, // 1/93!
        9.19653e-147, // 1/94!
        9.68056e-149, // 1/95!
        1.00839e-150, // 1/96!
        1.03958e-152, // 1/97!
        1.0608e-154, // 1/98!
        1.07151e-156, // 1/99!
};

double power (double base, double exponent);
double ln (double x);
double log (double base, double x);
double exp (double power);
double pow_int (double base, int exponent);

int main ()
{
    for (int i = 0; i < 1; ++i)
    {
        double base = 0.4 * i;
        double expon = 0.7 * i;
        std::cout << power(45, 3.0/5.0) << std::endl;
        std::cout << pow(45, 3.0/5.0) << std::endl << std::endl;
    }

    std::cout << log(10, 100000) << std::endl;
    std::cout << log10(10000) << std::endl << std::endl;

    std::cout << ln(1500) << std::endl;
    std::cout << log(1500) << std::endl << std::endl;



    return 0;
}

// base^exponent, for fractional bases and exponents
// still working out how to handle a negative base to a
// fractional power
double power (double base, double exponent)
{
    // edge cases fro immediate exits
    if (exponent == 0.0)
    {
        return 1.0;
    }

    if (exponent == 1.0)
    {
        return base;
    }

    // will handle negative exponent at the end
    bool is_negative_exponent = false;
    bool is_negative_base = false;

    if (exponent < 0.0)
    {
        is_negative_exponent = true;
        exponent *= -1;
    }

    if (base < 0)
    {
        is_negative_base = true;
        base *= -1;

    }

    // break exponent into integer and fraction
    // if x has an integer part, z, and a fractional part, q, then x = z + q
    // then b^x = b^(z+q) = b^z * b^q
    int integer_exponent = (int) exponent;
    double fractional_exponent = exponent - integer_exponent;

    // use integer-power only function (squaring method, for lgn)
    // to find b^z
    double integer_part = pow_int(base, (int) exponent);

    // if c = 0, then b^q = 1
    double fractional_part = 1;

    // if power has a fractional part, q, find b^q
    if (integer_exponent != exponent)
    {
        // b^q = a^[log_a[b] * q], here as exp(ln[b] * q)
        fractional_part = ln(base) * fractional_exponent;
        fractional_part = exp(fractional_part);
    }

    // b^z * b^q = b^x
    double combined = integer_part * fractional_part;

    if (is_negative_exponent)
    {
        // b^z * b^q = b^(z + q) = b^x
        combined = 1 / combined;
    }

    if (is_negative_base)
    {

    }

    return combined;

}

// ln(x) = 2 * inf(SIGMA)i=0 of
// ([x - 1] / [x + 1])^(2i + 1) over
//          [2i + 1]         for x > 0
// approximates at <terms> sums of the infinite series

/* Proof:
 * lnx = 2 SIGMA [([x-1] / [x+1])^(2i-1)] / (2i+1)  // d/dx
 * 1/x = 2 SIGMA ([x-1] / [x+1])^(2i) * (2/[x+1]^2) // * (x+1)^2
 * (x+1)^2/x = 4 SIGMA ([x-1]/[x+1])^2i // y = ([x-1]/[x+1])^2
 * (x+1)^2/x = 4 SIGMA y^i // geometric
 * (x+1)^2/x = 4 * 1/(1-y) // y = ([x-1]/[x+1])^2
 * (x+1)^2/x = 4 * 1/[1 - ([x-1]/x+1)^2] // [x-1]/[x+1] = 1 - 2/[x+1]
 * (x+1)^2/x = 4 * 1/[1-(1-2/[x+1])^2] // expand square
 * (x+1)^2/x = 4 * 1/[1-(1-4/[x+1]+4/[x+1]^2)] // distribute negative
 * (x+1)^2/x = 4 * 1/[1-1+4/[x+1]-4/[x+1]^2] // 1-1 = 0, combine fractions
 * (x+1)^2/x = 4 * 1/[(4[x+1]-4)/([x+1]^2) // fraction out 4
 * (x+1)^2/x = 4 * 1/[4(x+1-1)/([x+1]^2) // 1-1 = 0, reciprocal
 * (x+1)^2/x = 4 * ([x+1]^2)/(4x) // true
 */
double ln (double x)
{

    // edge cases, immediate exits
    if (x == 1.0)
    {
        return 0.0;
    }

    // lnx infinite summation approximation
    int terms = 100000;
    double result = 0;
    double num = (x - 1) / (x + 1);

    for (int i = 0; i < terms; ++i)
    {
        //denominator and power
        int denom_power = (2 * i) + 1;
        //numerator
        double numerator = pow_int(num, denom_power);
        //one term
        result += numerator / denom_power;
    }

    result *= 2;

    return result;
}

// log_b(x) = log_a(x) / log_a(b), where a log_a is any log
// doesn't currently work well. Unsure why
double log (double base, double x)
{
    // edge cases
    if (x == 1.0)
    {
        return 0.0;
    }

    if (base == x)
    {
        return 1.0;
    }

    return ln(x) / ln(base);
}


// exp(x) = inf(SIGMA)i=0 of { [x^i] * [1/i!] }

/*
 * Proof:
 *
 * inf(SIGMA)i=0 of {d^n/dy^n f(a) (x-a)^n / n!} = f(x)
 *
 * f(x) = f(a) + int/a to x\ { f'(t_1) dt_1} // or
 * f(x) = f(a) + int/a to x\ { f'(a) dt_1 +
 *          int/a to x\ int/a to t_1\
 *          {f''(t_2) dt_2 dt_1
 *
 * and so on
 *
 * we need f(x) represented as f(a), not f(t),
 * so we would need an infinite number of terms to exactly
 * equal f(x), to rewrite this sequence in Sigma notation:
 *
 * int/a to x\ { f'(a) dt_1 } // f'(a) is constant
 * f'(a) * int/a to x\ { dt_1 } // elementary integral
 * f'(a) * t /a to x\ // plug in bounds
 * f'(a) * (x - a)
 *
 * int/a to x\ int/a to t_1\ {f''(a) dt_2 dt_1 // f''(a) is constant
 * f''(a) int/a to x\ (t_1 - a) dt_1 =
 * f''(a)*(x-a)^2 / 2
 *
 * int/a to x\ int/a to t_1\ int/a to t_2\ f'''(a) dt_3 dt_2 dt_1 =
 * f'''(a)*(x-a)^3 / (2 * 3)
 * d^3/dy^3 f(a) * (x-a)^3 / 3!
 *
 * exp(0) = 1, so with a=0, exp(x) = inf(SIGMA)i=0 x^n / n!
 */

// approximates at <terms> sums
double exp(double power)
{
    int terms = 100;

    double result = 0;

    for (int i = 0; i < terms; ++i)
    {
        //taylor series of exp(x)
        result += pow_int(power, i) * n_fact_inv[i];
    }

    return result;
}

// base^exponent for integer exponents
// uses a squaring method, closer to O(lgn) than O(n)
double pow_int(double base, int exponent)
{
    double result = 1;
    double curr_val = base;

    while (exponent > 0)
    {
        if (exponent % 2)
        {
            result *= curr_val;
            --exponent;
        }
        else
        {
            curr_val *= curr_val;
            exponent /= 2;
        }
    }

    return result;
}