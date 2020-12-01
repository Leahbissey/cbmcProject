#include "sds.c"


int main() 
{
sds sdsString = sdsnew("Hello World!");

char cString[] = "Hello World!"; 


int i; 
for(i = 0; i < strlen(cString); i++)
{
assert(cString[i] == sdsString[i]);

}


sdsfree(sdsString);

return 0;
}
