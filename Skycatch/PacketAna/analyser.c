#include <analyser.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


/*
The checksum field is the 16 bit one's complement of the one's complement sum of all 16 bit words in the header. For purposes of computing the checksum, the value of the checksum field is zero.
*/

bool isValid(uint8_t *ipv4_header,uint32_t sender, uint32_t receiver, uint16_t providedCheck)
{

    bool res=0;

    uint32_t result =0;
    uint16_t checksum;


    //adding the first 9 elements  of the byte stream - avoiding the 10th and 11th element and adding sender and receiver

    for(int i=0;i<10;i++)
    {

        result +=((*ipv4_header<<8)|(*ipv4_header+1));
        ipv4_header=ipv4_header+2; //skip two
    }

    //we dont want to add the provided checksum value to this result

    result+=(sender+receiver);

    checksum=result+(result>>16);
	checksum=~checksum;
    if(~(checksum^providedCheck)){    //check if Compliment is  == 0
        res=1;
		printf("%s\n","Checksum is Valid.");
		return 1;
    }
else{
	return 0;
}
  

}



bool isPart(uint32_t address, uint32_t sender, uint32_t subnet_mask)
{

    //I'm not sure I understood this part correctly


    if((sender & subnet_mask)^(address & subnet_mask) ){
        printf("%s\n","Is not part of same subnet.");
        return 0;
        
    }
    else{

        return 1;

    }
}

bool is_local_address(uint8_t *ipv4_header, uint32_t address, uint32_t subnet_mask)
{

    bool res=0;


	ipv4_header=ipv4_header+10;

	uint16_t providedcheck = (*ipv4_header<<8)|(*ipv4_header+1);

providedcheck=0x7200;


/*#################################################################################*/
    ipv4_header=ipv4_header+2;
    uint32_t  sender = (*ipv4_header<<8)|(*ipv4_header+1);
    ipv4_header=ipv4_header+2; //move pointer forward by two  to get to the next 8 bits

    sender = (sender<<16)|(*ipv4_header<<8)|(*(ipv4_header+1));
    //Now we have the sender
	//sender = 0xC0A80101;
    ipv4_header=ipv4_header+2; // move pointer to get receiver


/*################################################################################ */

    uint32_t receiver = (*ipv4_header<<8)|(*ipv4_header+1);
    ipv4_header+2; //move pointer forward by two  to get to the next 8 bits

    receiver = (receiver<<16)|(*ipv4_header<<8)|(*(ipv4_header+1));


/*##################################################################################*/




    //We just call our two modules here and see if both evaluate to true.


bool valid= isValid(ipv4_header,sender, receiver,providedcheck);
bool part = isPart(address,sender,subnet_mask);
    if(valid & part)
    {
    	res=1;
    }
   
    return res;

}
