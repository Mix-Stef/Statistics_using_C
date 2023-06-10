* Linear Congruent Generator: It is an algorithm that generates a sequence of pseudo-random numbers. The generator is defined by the recurrence relation: $$X_{n+1} = (\alpha X_{n} + \beta) \mod m$$ for $n \geq 0$. m is called the "modulus", $\alpha$ the "multiplier", $\gamma$ the "increment" and  $X_{0}$ the "seed".

* Box-Muller Transform: It is a sample method for generating independent, normally distributed  random numbers. The source of the randomness is a pair of independent samples, $U_1$ and $U_2$, chosen from the uniform distribution on (0, 1). It can be proven that the numbers $$Z_0 = \sqrt{-2 \ln U_1} \cos(2\pi U_2)$$ and $$Z_1 = \sqrt{-2 \ln U_1} \sin(2\pi U_2)$$ is a pair of independent random variables with a standard normal distribution. Implementation of the Box-Muller transform can be found in the sample_normal.c file.


