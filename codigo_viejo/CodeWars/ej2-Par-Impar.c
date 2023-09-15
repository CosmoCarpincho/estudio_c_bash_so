#include <string.h>

int main(int argc, char const *argv[])
{
    // char * resultado; 
  
    // char even [5];
    // strcpy(even, "Even");
  
    // resultado = even;
  
    // printf("%s", resultado);

    int number = -1;

    if (number < 0)
    {
       number *= -1; // number = number * -1
    }
    

    if (number % 2 == 0){
        printf("The number is even.");
    }

    if (number % 2 == 1){
        printf("The number is odd.");
    }

    return 0;
}
