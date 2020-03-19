# index-calculus
 _(attacking the discrete logarithm problem - a crypto hobby to pass the time during COVID-19 shelter-in-place)_

## Prerequisites
We're going to be using `gmpy2` for accelerated arbitrary precision arithmentic, which wants to have `gmp`, `mpfr`, and `libmpc` installed. I also threw in `mpc` as well. Oh, and `python`

`> brew install gmp mpfr libmpc mpc python`
`> pip3 install gmpy2`

For good measure do an update for pip packages because you probably forgot to lately:
`alias pipdate3='pip3 list --outdated --format=freeze | grep -v '\''^\-e'\'' | cut -d = -f 1  | xargs -n1 pip3 install -U` >> `.zshrc`

`> pipdate3`


## Plan of Attack
1. Get packages installed and repo checked in
2. Test out mpz and modular arithmetic operations
3. Implement a baby-town-frolics problem
  - Generate problem parameters with a small prime
  - Implement something like Pollard Rho (Baby Step Giant Step?)
4. Do the actual thing
  * Generate problem parameters with a large prime
  * Create relation generator
    * Build factor base
    * Smoothness check
    * Choose and make a sieve (NFS?)
    * Factor and store relation
    * (bonus) Parallelize relation generator
  * Create or borrow matrix solver
  * ...
  * Solve discrete logarithm in subexponential complexity
