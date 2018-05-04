def loop(n,depth):
    """generates numbers containing "depth" primes, up to n"""
    if depth==0:            #generates the powers of two
        num1=1    
        while num1<n/2:
            num1*=pr[0]
            yield num1
    else:
        for i in loop(n,depth-1):           #generates all numbers containing the first n prime numbers
            num_depth=i                     #number containing all previous primes
            while num_depth<n/pr[depth]:
                num_depth*=primes[depth]            #successively multiplies the nth prime
                yield num_depth

def admissiblenums(n=1e9):
    """generates a set of all admissible numbers not exceeding 1e9"""
    admissibleset=set()
    for i in range(len(pr)):
        nth_admissible_prime=set(loop(n,i))
        admissibleset|=nth_admissible_prime     #union of admissibles up to nth prime   
    return admissibleset


def pseudofortunate(n):
    """returns the pseudofortunate number of n
    (the difference between n, and the first prime larger than or equal to n)"""
    prime_candidate=n+3#defined as prime larger than n+1, so starting the search for a prime at n+3, since admissible numbers are always even
    while True:
        if is_prime(m):
            return prime_candidate-n        #returns the difference(pseudo-fortunate number) if prime_candidate is prime
        prime_candidate+=2      #check odd numbers
t1=time()
primes=generate_primes(24)      #the primes less than 24, since the primorial needs to be less than 1e9
pseudofortunates=set()      
for i in admissiblenums():
    pseudofortunates.add(pseudofortunate(i))    #adds psuedo-fortunate numbers to set
print (sum(pseudofortunates))     #sum of unique pseudo-fortunate numbers
t2=time()
print t2-t1
