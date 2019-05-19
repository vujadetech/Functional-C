#include <stdio.h>
#include <stdlib.h>

// typedef enum { false = 0, true = 1 } bool;
typedef enum { false, true } bool;
typedef enum { toupee, bald, mohawk, johnnyUnidas } tonsoral;
typedef double (*int_to_double_fn)( int );
typedef void (*int_to_void_fn)( int );

int x = 0xC, y = 0b101, z = -3, w = 10 ;

bool zeroQ( int k ) { return (bool) !k ; }
int sgn( int k ) { return zeroQ(k) ? 0 : abs(k) / k; }
bool evenQ( int x ) { return (bool) (x % 2); }
bool oddQ( int x ) { return !evenQ( x ); }
int sq( int x ) { return x * x; }
// double sq( int x ) { return x * x; }
bool dividesQ( int k, unsigned long int n ) { return zeroQ(n % k); }

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
  if (zeroQ( n )) return 0 ; // 0^p is 0
  if (zeroQ( p )) return 1 ; // n^0 is 1
  return oddQ( p ) ? n * power( n-1, p ) : sq(power( n, p/2 )) ; }

int fac_accu( int n, int acc ) {
  while ( n > 1 )  {
    acc *= n; n--; }
  return acc;                  }

int main() {
  printf("heyy\n");
  printf("euclid(%d, %d) = %d\n", x, y, euclid( x, y ));
  printf("sgn %d = %d\n", z, sgn( z ));
  printf("fac_u %d = %d\n", w, fac_accu( w, 1 ));
  // printf("sum  = %f\n", sum( 1, 4, sq ));
  printf("gcd(%d, %d) = %d\n", x, y, gcd( x, y )); }
