#include <stdio.h>
#include <gmp.h>

int main (int argc, const char * argv[]) {
	mpz_t base, p, min, cutoff[87], five[87];
/*	mpz_init_set_str(base, "244241057144443665472449725715508406620552440771362355600491", 10);*/ /* 5^a */
	mpz_init_set_str(base, "794175985233932171488379184551301257494458499937502344155004", 10); /* 5^b */
/*	mpz_init_set_str(base, "1", 10);*/
	mpz_init_set_str(p, "3217014639198601771090467299986349868436393574029172456674199", 10);
	mpz_init_set(min, base);
	long i, k, bound;
	k = 0;
	bound = 100000000;
	
	for (i = 0; i < 87; i++){
		mpz_init_set(cutoff[i], p);
		mpz_init_set_ui(five[i], (unsigned int) 1);
		int j;
		for (j = 0; j <= i; j++){
			mpz_fdiv_q_ui(cutoff[i], cutoff[i], 5);
			mpz_mul_ui(five[i], five[i], (unsigned int) 5);
		}
	}
	
	gmp_printf("Base * 5^%d =\t%Zd\n", k, base);
	
	for(i = 0; i < bound; i++){
		int j;
		for (j = 0; j < 87; j++){
			if (mpz_cmp(base, cutoff[j]) > 0){
				mpz_mul(base, base, five[j]);
				mpz_tdiv_r(base, base, p);
				k = k + j + 1;
				break;
			}
		}
		if ((mpz_cmp(min, base) > 0)){
			mpz_set(min, base);
			gmp_printf("Base * 5^%d =\t%Zd\n", k, base);
		}
	}
	
	return 0;
}