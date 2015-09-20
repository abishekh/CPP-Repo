#include <analyser.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


/*
The checksum field is the 16 bit one's complement of the one's complement sum of all 16 bit words in the header. For purposes of computing the checksum, the value of the checksum field is zero.
*/


/*****************************************************************************
    Function Name   : isValid
    Date        : Sep. 2015
    Remarks: Used to check if the checksum is valid
******************************************************************************
    Input: uint8_t*, uint32_t,uint32_t,uint16_t - byte array, senders address, receivers address, the provided checksum
    Output: bool
*****************************************************************************/

bool isValid(uint8_t *ipv4_header,uint32_t sender, uint32_t receiver, uint16_t providedCheck)
{
    bool res=false;
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
    if(~(checksum^providedCheck)){    //check if Compliment is  == 0. We are doing NOT(checksum XOR providedcheck) (XNOR)comparison.  
        printf("%s\n","Checksum is Valid. ");
       res= true;
       checksum=0;
       providedCheck=0;
       result=0;

    }
    else{
        printf("%s\n","Checksum is Invalid. ");
        checksum=0;
        providedCheck=0;
        result=0;
        
    }
    return res;
}


/*****************************************************************************
    Function Name   : isPart
    Date        : Sep. 2015
    Remarks: Used to check if the address is part of the same subnet as the sender
******************************************************************************
    Input: uint32_t, uint32_t, uint32_t - The address to check, the senders address, the subnetmask
    Output: bool
*****************************************************************************/
bool isPart(uint32_t address, uint32_t sender, uint32_t subnet_mask)
{ //I'm not sure I understood this part correctly

    if((sender & subnet_mask)^(address & subnet_mask) ){   // Logic : (sender AND subnetmask) XOR (address AND subnetmask) - if the results are different they arent part of the same subnet
        printf("%s\n","Is not part of same subnet.");
        return false;
    }
    else{
        return true;
    }
}

/*****************************************************************************
    Function Name   : is_local_address
    Date        : Sep. 2015
    Remarks: Checks if checksum is valid and address is part of same subnet
******************************************************************************
    Input: uint8_t *, uint32_t, uint32_t
    Output: bool
*****************************************************************************/

bool is_local_address(uint8_t *ipv4_header, uint32_t address, uint32_t subnet_mask)
{
    bool res=false;

    //Filtering out the provided checksum
    ipv4_header=ipv4_header+10;
    uint16_t providedcheck = (*ipv4_header<<8) | (*ipv4_header+1);
   // printf("%s%d\n","Provided check is ",providedcheck);
   // providedcheck=0xfb00;  //For Debugging

    /*#################################################################################*/
    //Filtering out the sender's address
    ipv4_header=ipv4_header+2;
    uint32_t  sender = (*ipv4_header<<8)|(*ipv4_header+1);
    ipv4_header=ipv4_header+2; //move pointer forward by two  to get to the next 8 bits
    sender = (sender<<16)|(*ipv4_header<<8)|(*(ipv4_header+1)); 
    //Now we have the sender
    //sender = 0xC0A80101;
    ipv4_header=ipv4_header+2; // move pointer to get receiver
   
    /*################################################################################ */
    //Filtering out the receiver's address
    uint32_t receiver = (*ipv4_header<<8)|(*ipv4_header+1);
    ipv4_header+2; //move pointer forward by two  to get to the next 8 bits
    receiver = (receiver<<16)|(*ipv4_header<<8)|(*(ipv4_header+1));

    /*##################################################################################*/

    //We just call our two modules here and see if both evaluate to true.
    bool valid= isValid(ipv4_header,sender, receiver,providedcheck);
    bool part = isPart(address,sender,subnet_mask);

    if(valid && part){
    	printf("%s\n","Passed both conditions.");
        res=true;
    }
    else{
    	printf("%s\n","One or Both conditions not met. Check input!");
    }

  
    return res;

}
