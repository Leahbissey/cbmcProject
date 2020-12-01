#include "sds.c"

sds sdsCat(sds mystring1) 
{

mystring1 = sdscat(mystring1, " hi"); 
return mystring1;
}

const char * cCat(char *mystring1)
{

char cstring[] = " hi"; 
 int c, d;
   
   c = 0;
 
   while (mystring1[c] != '\0') {
      c++;      
   }
 
   d = 0;
 
   while (cstring[d] != '\0') {
      mystring1[c] = cstring[d];
      d++;
      c++;    
   }
 
mystring1[c] = '\0';

return mystring1;
}

int main() 
{

sds sdsString = sdsnew("Hello World!"); 
char cString[80] = "Hello World!";

sds newStringSdsFun = sdsCat(sdsString); 
const char* newStringCFun = cCat(cString); 
const char* newStringSdsCFun = cCat(sdsString); 

printf("%s", newStringCFun);
int i; 
for(i = 0; i < strlen(newStringSdsFun); i++)
{
assert(newStringSdsFun[i] == newStringCFun[i] && newStringSdsFun[i] == newStringSdsCFun[i]); 

}

return 0; 
}
