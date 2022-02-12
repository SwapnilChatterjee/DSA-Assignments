int fibonacciIterative(int n){
    int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}

unsigned int fibonacciIterativeUnsigned(int n){
    unsigned int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}

long int fibonacciIterativeLong(int n){
    long int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}

unsigned long int fibonacciIterativeUnsignedLong(int n){
    unsigned long int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}

 long long int fibonacciIterativeLongLong(int n){
     long long int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}


unsigned long long int fibonacciIterativeUnsignedLongLong(int n){
    unsigned long long int tmp, a = 0,b =1; 
    for (int i = 0; i < n; i++){
        tmp = a + b;
        a = b;
        b = tmp;
    }
    return tmp;
}


int fibonacciRecursive(int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

unsigned int fibonacciRecursiveUnsigned(unsigned int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursiveUnsigned(n-1) + fibonacciRecursiveUnsigned(n-2);
}


long int fibonacciRecursiveLong(long int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursiveLong(n-1) + fibonacciRecursiveLong(n-2);
}

unsigned long int fibonacciRecursiveUnsignedLong(unsigned long int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursiveUnsignedLong(n-1) + fibonacciRecursiveUnsignedLong(n-2);
}

long long int fibonacciRecursiveLongLong(long long int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursiveLongLong(n-1) + fibonacciRecursiveLongLong(n-2);
}
 

unsigned long long int fibonacciRecursiveUnsignedLongLong(unsigned long long int n)
{
   if (n <= 1)
      return n;
      
   return fibonacciRecursiveUnsignedLongLong(n-1) + fibonacciRecursiveUnsignedLongLong(n-2);
}
 