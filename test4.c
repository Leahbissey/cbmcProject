#include <string.h>
#include <stdio.h>

void concatenate(char p[]) 
{

   char q[] = "World!\0";
   int c, d; 
   c = 0; 
   while(p[c] != '\0') {
      c++;         
    }

    d = 0;    
    while(q[d] != '\0') {
    
      p[c] = q[d]; 
      d++; 
      c++;
 
    }
     p[c] = '\0';

}

int main() 
{

     char cString1[20] = "Hello ";
     strcat(cString1, "World!\n"); 
     printf("%s", cString1);

     char cString2[20] = "Hello ";
     concatenate(cString2); 
     printf("%s", cString2); 


     int i; 
     for(i = 0; i < strlen(cString2); i++)
     {
       assert(cString1[i] == cString2[i]);

     }

assert(0);
return 0; 
}
