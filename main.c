#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int main() {
    int low, high;

    printf("Enter lower bound: ");
    scanf("%d", &low);
    printf("Enter upper bound: ");
    scanf("%d", &high);

    printf("\nPrime numbers between %d and %d:\n", low, high);
    printf("----------------------------------------\n");

    int count = 0;
    for (int i = low; i <= high; i++) {
        if (isPrime(i)) {
            printf("%4d", i);
            count++;
            if (count % 10 == 0)
                printf("\n");
        }
    }

    printf("\n----------------------------------------\n");
    printf("Total prime numbers found: %d\n", count);

    return 0;
}
```

**Sample Output:**
```
Enter lower bound: 50
Enter upper bound: 100

Prime numbers between 50 and 100:
----------------------------------------
  53  59  61  67  71  73  79  83  89  97
----------------------------------------
Total prime numbers found: 10
```

---

**How the Sieve of Eratosthenes Works:**
```
Start: Mark all numbers 2 to N as prime
  2   3   4   5   6   7   8   9  10  11  12 ...

Step 1 (i=2): Mark multiples of 2
  2   3   X   5   X   7   X   9   X  11   X ...

Step 2 (i=3): Mark multiples of 3
  2   3   X   5   X   7   X   X   X  11   X ...

Step 3 (i=5): Mark multiples of 5
  2   3   X   5   X   7   X   X   X  11   X ...

Remaining unmarked numbers are PRIME ✓
