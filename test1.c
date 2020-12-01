#include "sds.c"


int sdsLength(char* mystring)
{

 return sdslen(mystring);
}

int cLength(char *mystring2)
{

return strlen(mystring2); 

}


int main() 
{
sds sdsString = sdsnew("Hello World!");

int sdsLengthFun1 = sdsLength(sdsString);


char cString[] = "Hello World!"; 

int CLengthFun2 = cLength(cString);
int sdsLengthFun2 = cLength(sdsString); 


assert(sdsLengthFun1 == CLengthFun2 && sdsLengthFun1 == sdsLengthFun2); 


sdsfree(sdsString);

return 0;
}
