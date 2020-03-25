#!/usr/bin/env python3

# So the principle of Pollard's Rho is to find an overlapping cycle between the generator and the target
# It was first explained to me as a pair of kangaroos hopping around the outback looking for eachother
# Once one kangaroo finds the footprint of the other it can follow the trail to find it home

from gmpy2 import mpz, powmod, random_state, mpz_random

q       = mpz(1019)    # modulo of finite field
q_order = mpz(1018)    # order of the field 
g       = mpz(2)       # generator in Z_q
k       = mpz(22)
n       = powmod(g, k, q)

print("b = g^k mod q = " + str(g) + "^" + str(k) + " mod " + str(q) + " = " + str(n))

def iter(triple):
    x = triple[0]
    a = triple[1]
    b = triple[2]
    if   x % 3 == 0:
        x = (x * x) % q
        a = (a * 2) % q_order
        b = (b * 2) % q_order
    elif x % 3 == 1:
        x = (x * g) % q
        a = (a + 1) % q_order
    elif x % 3 == 2:
        x = (x * n) % q
        b = (b + 1) % q_order
    return [x, a, b]

xab = [1, 0, 0]
XAB = [1, 0, 0]
i = mpz(0)

print(str(i), str(xab[0]), str(xab[1]), str(xab[2]), str(XAB[0]), str(XAB[1]), str(XAB[2]))
while i < q_order:
    i += 1
    xab = iter(xab)
    XAB = iter(XAB)
    XAB = iter(XAB)
    print(str(i), str(xab[0]), str(xab[1]), str(xab[2]), str(XAB[0]), str(XAB[1]), str(XAB[2]))
    if xab[0] == XAB[0]:
        break

