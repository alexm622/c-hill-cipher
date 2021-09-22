#include <stdio.h>
#include <stdlib.h>


#include <encoding.h>

int main(int argc, char const *argv[])
{
    int size = charStringSize("abcd");
    printf("the size of that chararray is %i\n", size);
    char* testSequence = "abcdz ";
    int* charIntArray = encode(testSequence);
    size = charStringSize(testSequence);
    for(int i = 0;i < size; i++){
        printf("[%i],", charIntArray[i]);
    }

    printf("\n");
    int decodeMe[5] = {1,2,3,4,26};
    
    char * charstr = decode((int*)decodeMe, 5);
    printf("the decoded int array is: %s\n", charstr);
    
    free(charstr);
    free(charIntArray);
    
    return 0;
}
