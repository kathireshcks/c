#include <stdio.h>
#include <string.h>


int digitValue(char c){
   int value=0;
     switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case '\0': value = 0; break;
         default: value = -1;
    }

    return value;
}


int main(){

    char rn[1000];
    int i=0;
    long int number =0;
  
   
    scanf("%s",rn);
  
    while(rn[i]){
       
         if(digitValue(rn[i]) >= digitValue(rn[i+1]))
             {
             	
             number = number + digitValue(rn[i]);
         }
         else{
             number = number + (digitValue(rn[i+1]) - digitValue(rn[i]));
             i++;
         }
         i++;
    }
       
    printf("%ld",number);
    return 0;
}


