/* ---------------------------------------------------------------------------
** message_validator.c
**
** DESCRIPTION: This file contains the message validator functions that enable intended parsing behavior to take place.
**
** The REGEX are stored as array elements according to their corresponding message ID.
**
** Author: Abishek Hariharan
** -------------------------------------------------------------------------*/

#include <message_validator.h>
#include <stdio.h>
#include <string.h> //For strlen
#include <stdlib.h>


const char* message_expression_series100[N_MESSAGES_S100] ={

    "^(\\$100[\r\n])$",

    "^((\\$101)[\r\n])$",

    "^((\\$102)[\r\n])$",

    "^((\\$103)[\r\n])$",

    "^((\\$104)[\r\n])$"

};

const size_t capture_groups_s100[N_MESSAGES_S100] ={
    3,
    3,
    3,
    3,
    3
};


const char* message_expression_series200[N_MESSAGES_S200] = {

    "^((\\$200)[\r\n])$",
    "^((\\$201)[\r\n])$",
    "^((\\$202)[\r\n])$",
    "^((\\$203)[\r\n])$",
    "^((\\$204)[\r\n])$",
    "^((\\$205)[\r\n])$",
    "^((\\$206)[\r\n])$",
    "^((\\$207)[\r\n])$",
    "^((\\$208)[\r\n])$",
    "^((\\$209)[\r\n])$",
    "^((\\$210)[\r\n])$",
    "^((\\$211)[,]([0-9]*\\.[0-9]+)[,]([0-9]*\\.[0-9]+)[,]([+-]?[0-9]*\\.[0-9]+)[\r\n])$",
    "^((\\$212)[,]([LRUDlrudX])[\r\n])$",
    "^((\\$213)[\r\n])$",
    "^((\\$214)[\r\n])$",
    "^((\\$215)[\r\n])$",
    "^((\\$216)[,]([012345])[\r\n]+)$",
    "^((\\$217)[\r\n])$",
    "^((\\$218)[\r\n])$"
};

const size_t capture_groups_s200[N_MESSAGES_S200] ={
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    6,
    4,
    3,
    3,
    3,
    4,
    3,
    3
};


const char* message_expression_series300[N_MESSAGES_S300] = {

    "^((\\$300)[\r\n])$",
    "^((\\$301)[\r\n])$",
    "^((\\$302)[,](180|0)[\r\n])$",
    "^((\\$303)[,](0|180)[,](720P120|1080P60|4K30)[\r\n])$",
    "^((\\$304)[\r\n])$",
    "^((\\$305)[\r\n])$",
    "^((\\$306)[\r\n])$",
    "^((\\$307)[\r\n])$",
    "^((\\$308)[\r\n])$",
    "^((\\$309)[\r\n])$",
    "^((\\$310)[\r\n])$",
    "^((\\$311)[\r\n])$",
    "^((\\$312)[\r\n])$",
    "^((\\$313)[\r\n])$",
    "^((\\$314)[\r\n])$",
    "^((\\$315)[\r\n])$",
    "^((\\$316)[\r\n])$",
    "^((\\$317)[\r\n])$",
    "^((\\$318)[\r\n])$",
    "^((\\$319)[\r\n])$",
    "^((\\$320)[,]([0-9]{10})[,](UTC)[-+]([0-9]|[1][0-2]))$",                  //2 payloads but 6 groups
    "^((\\$321)[\r\n])$",
    "^((\\$322)[,]([1-9]|(1|2)[1-9]|30)[,](3|5|10)[\r\n])$",                   //2 payloads but 6 groups
    "^((\\$323)[\r\n])$",
    "^((\\$324)[\r\n])$",
    "^((\\$325)[,]([A-Z]{5})[\r\n])$",                                        // 1 Payload 4 groups
    "^((\\$326)[\r\n])$",
    "^((\\$327)[\r\n])$",
    "^((\\$328)[\r\n])$",
    "^((\\$329)[\r\n])$",
    "^((\\$330)[\r\n])$"

};

const size_t capture_groups_s300[N_MESSAGES_S300]={

    3,
    3,
    4,
    5,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    6,
    3,
    6,
    3,
    3,
    4,
    3,
    3,
    3,
    3,
    3

};


int compile_regex_series100(){

    //We run a check to see if the provided regexs in the header file are valid and can be compiled.


    for(int i=0;i<N_MESSAGES_S100;i++){

        int status = regcomp(&(compiled_messages_series100[i]),message_expression_series100[i],REG_EXTENDED);

        //Did the given expression compile successfully?
        if(status !=0 ){
            char error_msg100[MAX_ERRORS_MSG];
            regerror(status,&compiled_messages_series100[i],error_msg100,MAX_ERRORS_MSG);

            //For debug we use Printf otherwise on system we need to log

            printf("Regex error Compiling '%s': %s\n",message_expression_series100[i],error_msg100);
            return 1;

        }

    } //For-loop ends

    return 0;

}  //compile_regex_series100 ends



int compile_regex_series200(){

    //We run a check to see if the provided regexs in the header file are valid and can be compiled.


    for(int i=0;i<N_MESSAGES_S200;i++){


        int status = regcomp(&(compiled_messages_series200[i]),message_expression_series200[i],REG_EXTENDED);
        //Did the given expression compile successfully?
        if(status!=0){
            char error_msg200[MAX_ERRORS_MSG];
            regerror(status,&compiled_messages_series200[i],error_msg200,MAX_ERRORS_MSG);

            //For debug we use Printf otherwise on system we need to log

            printf("Regex error Compiling '%s': %s\n",message_expression_series200[i],error_msg200);
            return 1;

        }

    } //For-loop ends

    return 0;

}  //compile_regex_series200 ends


int compile_regex_series300(){

    //We run a check to see if the provided regexs in the header file are valid and can be compiled.


    for(int i=0;i<N_MESSAGES_S300;i++){

        int status = regcomp(&compiled_messages_series300[i],message_expression_series300[i],REG_EXTENDED);
        //Did the given expression compile successfully?
        if(status!=0){
            char error_msg300[MAX_ERRORS_MSG];
            regerror(status,&compiled_messages_series300[i],error_msg300,MAX_ERRORS_MSG);

            //For debug we use Printf otherwise on system we need to log

            printf("Regex error Compiling '%s': %s\n",message_expression_series300[i],error_msg300);
            return 1;

        }

    } //For-loop ends

    return 0;

}  //compile_regex_series300 ends



/*
 *
 * Parse message checks the input string to see if it conforms to any of the compiled
 * regular expressions - if it does, it outputs the message ID (100 series | 200 series | 300 series)
 *
 * If the input string does not conform it will return a 0
 *
 * The payloads will be inserted into the groupArray and will have to retrieved and
 * type-casted accoording to their individual requirements.
 *
 */



int parse_message(char *inputString){

    volatile unsigned int msg_id=0;

    //100 Section
   for (int n_msg100=0;n_msg100<N_MESSAGES_S100;n_msg100++){                //For each message in the 100 series.
    for (int m1=0;m1<MAX_MATCHES;m1++){                                     // This second loop runs exactly once but is there to maintain readabilty and sanity

        if(regexec(&(compiled_messages_series100[n_msg100]),inputString,capture_groups_s100[n_msg100],groupArray,0)==0)
        {
            msg_id=100+n_msg100;
            printf("Matched %d\n",msg_id);
            break; // Break on the first match AKA look no further.
        }

    }
   }
// End 100 section


    //200 Section
   for(int n_msg200=0;n_msg200<N_MESSAGES_S200;n_msg200++){             //For each message in the 200 series
    for (int m2=0;m2<MAX_MATCHES;m2++){                                 // This second loop runs exactly once but is there to maintain readabilty and sanity
        if(regexec(&(compiled_messages_series200[n_msg200]),inputString,capture_groups_s200[n_msg200],groupArray,0)==0)
        {
            msg_id=200+n_msg200;
            printf("Matched %d\n",msg_id);
            break; // Break on the first match AKA look no further.
        }

    }
   }
   //End 200 Section



    //300 Section
    for(int n_msg300=0;n_msg300<N_MESSAGES_S300;n_msg300++){         //For each message in the 300 series
        for (int m3=0;m3<MAX_MATCHES;m3++){                             // This second loop runs exactly once but is there to maintain readabilty and sanity
        if(regexec(&(compiled_messages_series300[n_msg300]),inputString,capture_groups_s300[n_msg300],groupArray,0)==0)
        {
            msg_id=300+n_msg300;
            printf("Matched %d\n",msg_id);
            break; // Break on the first match AKA look no further.
        }
    }
   }
    // End 300 Section


return msg_id;  //This returned value can be used to call the specific message type handler or in a switch-case.



}//End of parse messages function



/*
 * The print_matches function exists only for desktop debugging purposes and is useless in an embedded environment.
 * DO NOT call it in an embedded environment.
 *
 */


void print_matches(char* sourceString){

    unsigned int msgID = parse_message(sourceString);

    if(msgID!=0){
    printf("The detected message ID is %u\n\n",msgID);

    for(int max_mtchs = 0 ; max_mtchs<MAX_MATCHES;max_mtchs++){

        for(int ga_idx=0;ga_idx<MAX_GROUPS;ga_idx++){
            if ((int)groupArray[ga_idx].rm_so < 0){
                break; //groupArray came back empty / AKA nothing was matched.
            }

           char sourcestringCopy[strlen(sourceString)+1];
           strcpy(sourcestringCopy,sourceString);
           sourcestringCopy[groupArray[ga_idx].rm_eo] = 0;

           printf("Group %d:[%2u-%2u]: %s\n",ga_idx,groupArray[ga_idx].rm_so,groupArray[ga_idx].rm_eo,sourcestringCopy+groupArray[ga_idx].rm_so);


          }

    }
}
    else{
        printf("No Matches Detected!\n");
    }

}


int initialize_message_validator(){

   unsigned int status=1;

   status=compile_regex_series100() +  compile_regex_series200() + compile_regex_series300();

   return status;

}



//Getter Functions to access the payloads in typecasted format.

float get_payload_float(char* group){

    return strtof(group,NULL);

}


//Cast to signed int
int get_payload_int(char* group){

    return atoi(group);

}

//Cast to double.
double get_payload_double(char* group){

    return strtod(group,NULL);

}



void terminate_message_validator(){

    //The allocation for the compiled regex's are freed
    for(int i=0;i<N_MESSAGES_S100;i++){
        regfree(&compiled_messages_series100[i]);
    }

    for(int i=0;i<N_MESSAGES_S200;i++){
        regfree(&compiled_messages_series200[i]);

    }

    for(int i=0;i<N_MESSAGES_S300;i++){
        regfree(&compiled_messages_series300[i]);

    }

    printf("Terminated all.\n\n");
}
