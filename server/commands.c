#include "commands.h"

/*
 * int isValidCommand(char * toParse) -> Takes command as string and checks if it is valid
 *
 *
 * “/r” - list the rooms on the server
 * “/l” - lists people in the current room
 * “/x” - close the connection and log off the server
 * “/q” - end private chat
 * “/h” - help
 * “/p name"      - private chat
 * “/j roomname ” - joins the given room
 * “/f filename"  - send file
 */


/* return 1 if the command is VALID. Returns 0 if the command is NOT valid
 * Take command in form: /j testRoom
 */
int isValidCommand(char * toParse){
    if(toParse != NULL && strlen(toParse) >= 2){
        if(toParse[0] == "/") { //starts with command character. Definitely not a chat message

            char temporaryS[strlen(toParse)+1];
            strcpy(temporaryS, toParse);
            char toTest = temporaryS[1];

            switch(toTest) {
                case 'r' : //list the rooms on the server
                    if(strlen(toParse) == 2)
                        return 1;
                    else
                        return 0;
                case 'l' : //lists people in the current room
                    if(strlen(toParse) == 2)
                        return 1;
                    else
                        return 0;
                case 'x' : //close the connection and log off the server
                    if(strlen(toParse) == 2)
                        return 1;
                    else
                        return 0;
                case 'q' : //end private chat
                    if(strlen(toParse) == 2)
                        return 1;
                    else
                        return 0;
                case 'h' : //help
                    if(strlen(toParse) == 2)
                        return 1;
                    else
                        return 0;
                case 'p' : //private chat
                    removeSpaces(toParse);
                    if(strlen(toParse) > 2)
                        return 1;
                    else
                        return 0;
                case 'j' : //joins the given room
                    removeSpaces(toParse);
                    if(strlen(toParse) > 2)
                        return 1;
                    else
                        return 0;
                case 'f' : //send file
                    removeSpaces(toParse);
                    if(strlen(toParse) > 2)
                        return 1;
                    else
                        return 0;
                default : //doesn't match any command
                    return 0;
            }
        }
    }else
        return 0;
}
void executeCommand(char * toParse){
    if(isValidCommand(toParse)) {
        char toTest = temporaryS[1];

        switch (toTest) {
            case 'r' : //list the rooms on the server
                //command is valid, do something
            case 'l' : //lists people in the current room
                //command is valid, do something
            case 'q' : //end private chat
                //command is valid, do something
            case 'h' : //help
                //command is valid, do something
            case 'p' : //private chat
                //command is valid, do something
            case 'j' : //joins the given room
                //command is valid, do something
            case 'f' : //send file
                //command is valid, do something
            default : //doesn't match any command
                return 0;
        }
    }
}
/*
 * Take incoming String and convert it to lower case
 */
void makeLowerCase(char * toParse){
    if(strlen(toParse) != 0) {
        int i;
        for (i = 0; i < strlen(toParse); i++) {
            toParse[i] = tolower(toParse[i]);
        }
    }
}
void removeSpaces(char * toParse) {
    int count = 0;

    for (int i = 0; i < strlen(toParse); i++) {
        if (toParse[i] != ' ') {
            toParse[count++] = toParse[i];
        }
    }
    toParse[count] = '\0';
}
