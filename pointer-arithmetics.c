    #include <stdio.h>
	
    int main() {
    	int intarray[5] = {10,20,30,40,50};
        //-----------------------^
        int *pointer = &intarray[2];
        printf("pointer: %d at %p\n",*pointer,pointer);

        // Array of 3 pointers
        int *parray[3];
        int *new_pointer = pointer;
        // Copy last three addresses of intarray into parray
        // Use parray and pointer
        int i;
        for (i = 0; i < 3; i++) {
            // Insert code here
            parray[i] = new_pointer;
            new_pointer ++;
            printf("pointer: %d at %p\n",*new_pointer,new_pointer);

        }

        // Test code
        for (i = 0; i < 3; i++) {
            if (parray[i] == &pointer[i]) {
                printf("Matched!\n");
            } else {
                printf("Fail\n");
            }
        }

        return 0;
    }