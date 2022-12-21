#include <stdlib.h>
#include <stdio.h>
#include "header.h"
void main() {
int x=0;
do{
x=choose_ex();
if(x==1)
start_ex(ex1,x);
if(x==2)
start_ex(ex2,x);
}while(x!=0);
}