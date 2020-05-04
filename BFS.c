#include <stdio.h>
char*graph[] = {
   {'A','B','C'},
   {'B','A','C','D'},
   {'C','A','D','E'},
   {'D','B','E','F'},
   {'E','C','D'},
   {'F','D'}
};
int colsize[] = {3, 4, 4, 4, 3 , 2};
int main ()
{
    printf("hello BFS\r\n");
}
