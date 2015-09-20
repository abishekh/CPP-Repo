#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <analyser.h>
#include <string.h>

int main() {
  // call a function in another file




//uint32_t address=0x0A000001; //10.0.0.1  //Debugging
/*
	source address is : 0xac1402fd  => 172.20.2.253
	destination address is : 0xac140006 => 172.20.0.6
*/



//Test case 1 
printf("%s\n","############################");
printf("%s\n","Test case 1.");
uint8_t ipv4_header1[20] ={ 0x45, 0x00, 0x00, 0x44, 0xad, 0x0b, 0x00, 0x00, 0x40, 0x11, 0x72,0x72, 0xac, 0x14, 0x02, 0xfd, 0xac, 0x14, 0x00, 0x06};
uint32_t address=0xC0A80001; //172.20.4.253
uint32_t subnet=0xFFFFFFE0; //255.255.255.224
is_local_address(ipv4_header1,address,subnet);
memset(ipv4_header1, 0x00, sizeof ipv4_header1);
printf("%s\n","############################");
 
 //Test case 2
printf("%s\n","Test case 2.");
uint8_t ipv4_header2[20]={ 0x45, 0x00, 0x00, 0x44, 0xad, 0x0a, 0x00, 0x00, 0x40, 0x11, 0x00, 0x00, 0xac, 0x14, 0x02, 0xfd, 0xac, 0x14, 0x00, 0x06};
uint32_t address2=0xC0A80001; //172.20.4.253
uint32_t subnet2=0x80000000; // 	128.0.0.0
is_local_address(ipv4_header2,address2,subnet2);
memset(ipv4_header2, 0x00, sizeof ipv4_header2);
printf("%s\n","############################");

//Test case 3
printf("%s\n","Test case 3.");
 uint8_t ipv4_header4[20] ={ 0x45, 0x00, 0x00, 0x44, 0xad, 0x0b, 0x00, 0x00, 0x40, 0x11, 0x72,0x72, 0xac, 0x14, 0x02, 0xfd, 0xac, 0x14, 0x00, 0x06};
uint32_t address3=0xA9FEE901; //169.254.233.1
uint32_t subnet3=0x80000000; // 	128.0.0.0
is_local_address(ipv4_header1,address3,subnet3);
memset(ipv4_header4, 0x00, sizeof ipv4_header4);
printf("%s\n","############################");

  //Test case 4
printf("%s\n","Test case 4.");
uint8_t ipv4_header3[20]={ 0x45, 0x00, 0x00, 0x44, 0xad, 0x0b, 0x00, 0x00, 0x40, 0x11, 0x0b, 0xfd, 0xac, 0x14, 0x02, 0xfd, 0xac, 0x14, 0x00, 0x06};
uint32_t address4=0xC0A80001; //172.20.4.253
uint32_t subnet4=0xFF800000; //255.128.0.0
is_local_address(ipv4_header3,address4,subnet4);
memset(ipv4_header3, 0x00, sizeof ipv4_header3);
printf("%s\n","############################");


return(0);
}
