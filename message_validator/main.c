#include <stdio.h>
#include "message_validator.h"


int main(void)
{

    //char *input="$303,0,720P120\n";

    char *input = "$211,1.111,2.234234,+8.111\n";
if (initialize_message_validator() == 0){  //did everything initialize properly ?
    print_matches(input);
    terminate_message_validator();


}


}

