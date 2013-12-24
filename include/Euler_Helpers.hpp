#ifndef _EULER_HELPERS_H
#define _EULER_HELPERS_H

int ldf( int k, int n){
	if( n % k == 0) return k;
	if( k*k > n) return n;
	return ldf(k+1, n);
}

int ld(int n){
	return ldf(2, n);
}

#endif