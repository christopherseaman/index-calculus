#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char** argv) {
	mpz_t base, p, product, temp, exponent;
	gmp_randstate_t state;
	unsigned int bound, i;
	if (argc > 1){
		bound = atoi(argv[1]);
	} else {
		bound = 10000;
	}
	
	unsigned int factor[bound];
	mpz_init_set_ui(base, 5);
	mpz_init_set_str(p, "3217014639198601771090467299986349868436393574029172456674199", 10);
	mpz_init_set_ui(product, 1);
	mpz_init(exponent);
	gmp_randinit_default(state);
	mpz_urandomm(exponent, state, p);
	
	/* Set up the Factor Base */
	factor[0] = 2;
	mpz_init_set_ui(temp, factor[0]);
	for (i = 1; i < bound; i++){
		mpz_nextprime(temp, temp);
		factor[i] = mpz_get_ui(temp);
	}
	
	/* Set up the product of the factor base */
	for (i = 0; i < bound; i++){
		mpz_set(temp, p);
		while(mpz_cmp_ui(temp, factor[i]) > 0){
			mpz_mul_ui(product, product, factor[i]);
			mpz_tdiv_q_ui(temp, temp, factor[i]);
		}
	}
	gmp_printf("product: %Zd\n", product);
	
	
	mpz_powm(temp, base, exponent, p);
	while(mpz_divisible_p(product, temp) == 0){
		mpz_urandomm(exponent, state, p);
		gmp_printf("%Zd\n", exponent);
		mpz_powm(temp, base, exponent, p);
	}
	gmp_printf("%Zd\t%Zd\n", exponent, temp);
	
	return 0;
}