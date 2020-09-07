#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    string key = argv[1];
    if(strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string text = get_string("Please enter a text? ");
    for(int i =0, v = strlen(text); i <= v; i++) {
        char lower = tolower(text[i]);
        if (lower >= 'a' && lower <= 'z') {
            int index = lower - 97;
            char replace_text = key[index];
            if (islower(text[i])) {
                printf("%c", tolower(replace_text));
            }else {
                printf("%c", toupper(replace_text));
            }
        } else if (lower == 0) {
            printf("\n");
        } else {
            printf("%c", lower);
        }
    }
}