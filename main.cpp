#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX = 92;
const int LETTERS_NUMBERS = 62;

int generate_password(int password_length);
int without_special_char(int password_length);

int main(int argc, char *argv[]) {
    int option;

    while((option = getopt(argc, argv, "ls:")) != -1) { 
      switch(option){
         case 'l':
            srand(time(NULL));
            generate_password(std::atoi(optarg));
            break;
        case 's':
            srand(time(NULL));
            without_special_char(std::atoi(optarg));
            break;
        case '?': //used for some unknown options
            printf("unknown option: %c\n", optopt);
            break;
      }
   }
   for(; optind < argc; optind++){ //when some extra arguments are passed
      printf("Given extra arguments: %s\n", argv[optind]);
   }

   return 0;
}

int generate_password(int password_length) {
    char characters[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9',
                        '`', '~', '!', '@', '#', '$', '%', '^', '&',
                        '*', '(', ')', '-', '_', '[', ']', ';', '/', '\\', 
                        '{', '}', '|', ':', '<', '>', '?', ',', '.', '+', '='};

    std::string password = "";
    for(int i = 0; i < password_length; i++) {
        password += characters[rand() % MAX];
    }    

    std::cout << "Your password is: " << password << std::endl;

    return 0;
}

int without_special_char(int password_length) {
    char characters[LETTERS_NUMBERS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                        's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9'};

    std::string password = "";
    for(int i = 0; i < password_length; i++) {
        password += characters[rand() % LETTERS_NUMBERS];
    }

    std::cout << "Your password is: " << password << std::endl;

    return 0;
}