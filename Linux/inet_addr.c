#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  
  // inet_addr
  char *addr1 = "1.2.3.4";
  char *addr2 = "1.2.3.256";

  unsigned long conv_addr;
  conv_addr = inet_addr(addr1);
  printf("Network ordered integer addr: %#lx \n", conv_addr);
  conv_addr = inet_addr(addr2);
  printf("Network ordered integer addr: %#lx \n", conv_addr);
  
  // inet_aton
  char *addr = "127.232.124.79";
  struct sockaddr_in addr_inet;

  if(!inet_aton(addr, &addr_inet.sin_addr)){
    printf("Error");
  } else {
    printf("Network ordered integer addr: %#x \n", addr_inet.sin_addr.s_addr);
  }

  // inet_ntoa
  // return value is char*, so copy it!
  struct sockaddr_in inaddr1, inaddr2;
  char *str_ptr;
  char str_arr[20];

  inaddr1.sin_addr.s_addr = htonl(0x1020304);
  inaddr2.sin_addr.s_addr = htonl(0x1010101);

  str_ptr = inet_ntoa(inaddr1.sin_addr);
  strcpy(str_arr, str_ptr);
  printf("str_ptr: %s \n", str_ptr);


  str_ptr = inet_ntoa(inaddr2.sin_addr);
  printf("str_ptr: %s \n", str_ptr);
  printf("str_arr: %s \n", str_arr);


  
  return 0;
}
