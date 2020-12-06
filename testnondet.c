#include "sds.c"

int main() 
{

char cString[15];

int i; 
for(i = 0; i < 15; i++)
{
 cString[i] = nondet_uchar();  

}

sds sdsString = sdsnew(cString); 

int i; 
for(i = 0; i < 15; i++)
{
  assert(cString[i] == sdsString[i]);

}

sdsfree(sdsString);

return 0;
}
