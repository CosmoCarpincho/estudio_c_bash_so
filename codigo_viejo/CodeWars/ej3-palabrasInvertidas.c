#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    char * sentence = "Welcome";
    //strcpy(sentence, "Welcome");

     int i;
    for (i = 0; sentence[i] != '\0'; i++ )   
    ;
  
    if (i < 5){
    // result = sentece;
    // return result;
    }
    else {

    int tam = sizeof(sentence);
    
     char * invertida = malloc(tam) ;
     int j;
     for ( j = 0; j < tam - 1; j++)
     {  
         invertida[j] = sentence[tam - j -2 ];

         printf("%c   ||    %c\n", invertida[j], sentence[tam - j -2]);
        
     }
        invertida[j] = '\0';
     

     printf("%s", invertida);
    
    }
    
    return 0;
}


// // Hasta donde arme
// //  do not allocate memory for return string
// //  assign the value to the pointer "result"

// #include <stdlib.h>

// void spin_words(const char *sentence, char *result) {
 
//   int tam = sizeof(sentence);
  
//   if (tam < 5){
     
//     result = (char *)sentence;
//   }
//   else {
    
//     char * invertida = malloc(tam) ;
    
//     int j;
//     for ( j = 0; j < tam - 1; j++)
//      {  
//          invertida[j] = sentence[tam - j -2 ];
        
//      }
//         invertida[j] = '\0';
     

//      result = invertida;
    
//     }

// }

// // ejercicio
// https://www.codewars.com/kata/5264d2b162488dc400000001/train/c