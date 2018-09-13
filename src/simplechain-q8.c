#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <string.h>
#include "validation.h"

int main (int argc, char *argv[]) {
 pid_t childpid = 0;
 int i, n, j, nchars;
 char* mybuf;
 int option;
 int errno;
 int customErrorCode = 0;
 extern char *optarg;
 static char usageError[] = "%s: Usage: %s [-n # of processes | -c number of characters]\n";

 // throw error if less than 2 arguments are passed


 // checking for options -h, -n, -p
 while ((option = getopt(argc, argv, "hpn:c:")) != -1) {
   switch (option) {
    //user asked for help
    case('h'):
      printf("Help: to run this program run the following command:\n%s -n <number of processes> -c <number of characters>\n", argv[0]);
      return 0;
    case('n'):
      if (isNumber(optarg)) {
        n = (int)strtol(optarg, NULL, 0);
      } else {
        customErrorCode = 1;
      }
      break;
    case('c'):
      if (isNumber(optarg)) {
        nchars = (int)strtol(optarg, NULL, 0);
        mybuf = malloc(sizeof(char) * (nchars+1));
      } else {
        customErrorCode = 1;
      }
      break;
    case('p'):
      // outputting a test error
      customErrorCode = 2;
      break;
    case ('?'):
      customErrorCode = 3;
      break;
   }
 }

 if (argc != 5){
   customErrorCode = 3;
 }

 switch (customErrorCode) {
    case 1:
      fprintf(stderr, "%s: Error: %s\n", argv[0], "invalid n value");
      fprintf(stderr, usageError, argv[0], argv[0]);
      exit(1);
    case 2:
      fprintf(stderr, "%s: Error: %s\n", argv[0], "test error");
      exit(1);
    case 3:
      fprintf(stderr, usageError, argv[0], argv[0]);
      exit(1);
  }


 for (i = 1; i < n; i++){
   if ( (childpid = fork()) ){
     break;
   }
 }

 for (j = 0; j < nchars; j++) {
	  scanf(" %c", &mybuf[j]);
  }
 mybuf[nchars] = '\0';
 fprintf(stderr, "i:%d process ID:%ld mybuf string:%s\n", i, (long)getpid(), mybuf);
 return 0;
}
