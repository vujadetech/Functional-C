//#ifndef __CH_2__
//#define __CH_2__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { toupee, bald, mohawk, johnnyUnidas } tonsoral;
typedef double (*int_to_double_fn)( int );
typedef void   (*int_to_void_fn)  ( int );
typedef int    (*int_to_int_fn)   ( int );
typedef void   (*int_to_void_fn)  ( int ); // not working yet

int x = 0xC, y = 0b101, z = -3, w = 10 ;

// **************************
// ****** from stack exchange *******
typedef int (*two_var_func) (int, int);
typedef int (*one_var_func) (int);

int add_int (int a, int b) {
    return a + b;
}

one_var_func partial (two_var_func f, const int a) {
    int g (int b) { return f (a, b); }
    return g;
}

one_var_func partial2 (two_var_func f, int b) {
    int g (int a) {
        return f (a, b);
    }
    return g;
}

one_var_func compose( one_var_func f, one_var_func g ) {
  int h (int x) { return f(g(x)); }
  return h; }

// **************************

bool zeroQ( int k ) { return (bool) !k ; }
int sgn( int k ) { return zeroQ(k) ? 0 : abs(k) / k; }
bool evenQ( int x ) { return (bool) (x % 2); }
bool oddQ( int x ) { return !evenQ( x ); }
bool dividesQ( int k, unsigned long int n ) { return zeroQ(n % k); }

int sq( int x ) { return x * x; }
int twoTimes(int x ) { return x + x; }
int id_int( int x ) { return x; }
// void * sq_i2void( int x ) { return (int*)(x * x); }
int doItTwice_i2i ( int_to_int_fn f, int x ) { return f(f(x)); }
int quartic( int x ) { return doItTwice_i2i( sq, x ); }
int fourth( int x ) { return compose(sq, sq)(x); }
// int cube( int x ) { return sq_i2void(x); }
/* int_to_int_fn compose( int_to_int_fn f ) {
  // int g( int x ) { return f(f(x)); }
  // return &g; }
  int_to_int_fn g(int x) { return f(f(x)) ;};
  return g; }
*/

//int h( int x ) { return compose(id_int)(x); }

double int2real( int x ) { return x; } // cast to double is automatic
double sum( int i, int n, int_to_double_fn f ) {
  return i > n ? 0.0 : f( i ) + sum( i+1, n, f ); }

int euclid( int m, int n ) {
  if ( n > 0 ) return euclid( n, m % n );
  return m; }

int gcd( int m, int n ) {
  switch( n ) {
    case 0:   return m;
    default:  return gcd( n, m % n ); } }

int power( int n, int p ) {  // using the "indian algorithm"
  /// todo: refactor so it's tail recursive
  if (zeroQ( n )) return 0 ; // 0^p is 0
  if (zeroQ( p )) return 1 ; // n^0 is 1
  return oddQ( p ) ? n * power( n-1, p ) : sq(power( n, p/2 )) ; }

int fac_accu( int n, int acc ) {
  while ( n > 1 )  {
    acc *= n; n--; } // could do just "acc *= n--;"" but that violates rules of decency
  return acc; }

int main() {
  printf("heyy\n");
  printf("euclid(%d, %d) = %d\n", x, y, euclid( x, y ));
  printf("sgn %d = %d\n", z, sgn( z ));
  printf("fac_u %d = %d\n", w, fac_accu( w, 1 ));
  // printf("sum  = %f\n", sum( 1, 4, sq ));
  printf("gcd(%d, %d) = %d\n", x, y, gcd( x, y ));

  printf("h(%d) = %d\n", x, id_int(x) );

  int a = 1;
  int b = 2;
  printf ("%d\n", add_int (a, b));
//   printf ("%d\n", partial (add_int, a) (b));
  // int add5( int x ) { return partial( add_int, 5 )(x) ; }
  one_var_func add5b = partial( add_int, 5 );

  // printf("add 5 to %d = %d\n", x, add5(x) );

  printf("add 5b to %d = %d\n", x, add5b(x) );
  printf("fourth( %d ) = %d\n", x, fourth(x) );
}

//#endif
