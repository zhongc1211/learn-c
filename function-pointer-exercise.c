    #include <stdio.h>

    void f1(int var)
    {
            printf("this is f1 and var is: %d\n", var);
    }

    void f2(int var)
    {
            printf("this is f2 and var is: %d\n", var);
    }

    void f3(int var)
    {
            printf("this is f3 and var is: %d\n", var);
    }

    int main()
    {
                /* define an array full of function pointers 
                to the above functions, that take an `int` as 
                their only argument */
        void (*pf1)(int) = &f1;
        void (*pf2)(int) = &f2;
        void (*pf3)(int) = &f3;
        void *pfs[3] = {pf1, pf2, pf3};


		int c = 0;
		while(c < 3)
		{
                        /* call the functions using the function pointers
                        of the array at index `c` with `c` as an argument */
            void (*pfx)(int);
            pfx = pfs[c];
            (pfx)(c);

			++c;
		}

	  return 0;
    }