#include <stdbool.h>
#include <stdint.h>


bool isValid(uint8_t *ipv4_header,uint32_t sender, uint32_t receiver,uint16_t providedcheck);

bool is_local_address(uint8_t *ipv4_header, uint32_t address, uint32_t subnet_mask); 

bool isPart(uint32_t address,uint32_t sender, uint32_t subnet_mask);


