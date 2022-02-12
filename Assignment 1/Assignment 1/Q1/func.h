int factorialIterative(int n){
    int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

unsigned int factorialIterativeUnsigned(int n){
    unsigned int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long int factorialIterativeLong(int n){
    long int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

unsigned long int factorialIterativeUnsignedLong(int n){
    unsigned long int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long int factorialIterativeongLong(int n){
    long  long int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

unsigned long long int factorialIterativeUnsignedLongLong(int n){
    unsigned long  long int result=1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}


int factorialRecursive(int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursive(n-1);
}


unsigned int factorialRecursiveUnsigned(unsigned int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursiveUnsigned(n-1);
}

long int factorialRecursiveLong(long int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursiveLong(n-1);
}

unsigned long int factorialRecursiveUnsignedLong(unsigned long int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursiveUnsignedLong(n-1);
}

long long int factorialRecursiveLongLong(long long int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursiveLongLong(n-1);
}


unsigned long long int factorialRecursiveUnsignedLongLong(unsigned long long int n){
    if (n == 0){
        return 1;
    }
    
    return n * factorialRecursiveUnsignedLongLong(n-1);
}

