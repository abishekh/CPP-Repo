#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <analyser.h>



int main() {
  // call a function in another file
 uint8_t ipv4_header[20] ={ 0x45, 0x00, 0x00, 0x44, 0xad, 0x0b, 0x00, 0x00, 0x40, 0x11, 0x72,
  0x72, 0xac, 0x14, 0x02, 0xfd, 0xac, 0x14, 0x00, 0x06};

uint32_t address=0xC0A80001; //172.20.4.253
uint32_t subnet=0xFFFFFFE0; //255.255.255.224


//uint32_t address=0x0A000001; //10.0.0.1
/*
	source address is : 0xac1402fd  => 172.20.2.253
	destination address is : 0xac140006 => 172.20.0.6
*/


if(is_local_address(ipv4_header,address,subnet))
{
	printf("%s\n","Passed both conditions.");

}
else{

printf("%s\n","One or Both conditions not met. Check input.");

}

  return(0);
}
