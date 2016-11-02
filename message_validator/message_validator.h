/* ---------------------------------------------------------------------------
** message_validator.h
**
** DESCRIPTION: This file contains the message validator functions that enable intended parsing behavior to take place.
**
** Author: Abishek Hariharan
** -------------------------------------------------------------------------*/




#ifndef MESSAGE_VALIDATOR_H
#define MESSAGE_VALIDATOR_H

#include <regex.h>
#include <string.h>


// We need to tell it the number of totaly messages we wish to validate - this is to make life easier.
// change this #define if you add or subtract message types

#define MAX_ERRORS_MSG 1000    //For error messages

#define N_MESSAGES_S100 5     //100-104

#define N_MESSAGES_S200 19     // 200-218

#define N_MESSAGES_S300 31     // 300-330

#define MAX_MATCHES 1 //A string can contain only one match for a given expression. We do not consider malformed and concatenated messages.



#define MAX_GROUPS 9   // From 0 to 8. Since first two groups are the implicit match and the whole match this leaves us with 7 remaining groups.

// Group 2 is always the header. Subsequent griups hold the various payloads.

regmatch_t groupArray[MAX_GROUPS];

static volatile char group0[];
static volatile char group1[];
static volatile char group2[];
static volatile char group3[];
static volatile char group4[];
static volatile char group5[];
static volatile char group6[];
static volatile char group7[];
static volatile char group8[];


/*****************************************************************************************/

float get_payload_float( char* group);
int get_payload_int( char* group);
double get_payload_double( char* group);

regex_t compiled_messages_series100[N_MESSAGES_S100];
regex_t compiled_messages_series200[N_MESSAGES_S200];
regex_t compiled_messages_series300[N_MESSAGES_S300];

int compile_regex_series100();
int compile_regex_series200();
int compile_regex_series300();
int initialize_message_validator();
void terminate_message_validator();
int parse_message(char *inputString);
void print_matches(char *inputString);


// For series 100 there is no Payload present, the implicit group '0' is the whole match - which in our case happens to be the same as the group 1 match.
// Thats why we have max_groups_series100 as 2. No worries.

/****************************************************************************/

#endif // MESSAGE_VALIDATOR_H
