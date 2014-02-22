#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void revstring(char s[]);

int main(void){
  char buffer[255];
  int b;
  int n;
  /*read the base and integer from standard input
    and call the itob function*/
  scanf("%d %d", &b, &n);
  itob(n, buffer, b);
  printf("%s\n", buffer);

  return 0;
}

void itob(int n, char s[], int b){
  /*function only handles numbers up to base 36*/
  if ( b<2 || b>36){
    exit(0);
   }
  int i;
  int num;
  static char intToString[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (i=0; n>0; i++){
    num=n%b;
    s[i]=intToString[num];
    n= n/b;}
  s[i] = '\0';
  /* at this point, the converted number needs to be
     reversed in order to be correct*/
  revstring(s);
}
/*this function takes the converted number and reverses
  it so it is in the correct order*/
void revstring(char s[]) {
  int c,i,j;
  for (i=0, j=strlen(s)-1; i<j; i++, j--){
    c =s[i];
    s[i] = s[j];
    s[j]=c;
  }
}
