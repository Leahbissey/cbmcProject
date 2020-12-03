#include "sds.c"


int main() 
{

  sds sdsString = sdsnew("Hello World!"); 
  sdsString = sdscat(sdsString, "hi"); 
  char cString[80] = "Hello World!hi";

  int i; 
  for(i = 0; i < strlen(sdsString); i++)
  {
    assert(cString[i] == sdsString[i]);  
  }

  return 0; 
}
