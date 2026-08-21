#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char* pop();
extern void push(char);

int main(int argc, char* argv[])
{
    int current_char;
    int last_char = ' '; 
    char tag_buffer[100]; // buffer for storing tag identities
    int tag_len = 0; // current length of tag buffer
    while ((current_char = getchar()) != EOF) {
        if (last_char == '<' && current_char != '/') { // start tag detected
            // read tag identity
            tag_len = 0;
            while (isalpha(current_char)) {
                tag_buffer[tag_len] = current_char;
                tag_len++;
                current_char = getchar();
            }
            tag_buffer[tag_len] = '\0';
            if (current_char != '>') {
                fprintf(stderr, "Error: invalid start tag\n");
                exit(1);
            }
            push(tag_buffer[0]);
        }
        else if (last_char == '<' && current_char == '/') { // end tag detected
         // read tag identity
            tag_len = 0;
            current_char = getchar();
            while (isalpha(current_char)) {
                tag_buffer[tag_len] = current_char;
                tag_len++;
                current_char = getchar();
            }
            tag_buffer[tag_len] = '\0';
            if (current_char != '>') {
                fprintf(stderr, "Error: invalid end tag\n");
                exit(1);
            }
            // pop the stack and compare with the end tag identity
            char start_tag = pop();
            if (start_tag == -1) {
                fprintf(stderr, "Error: empty stack\n");
                exit(1);
            }
            if (start_tag != tag_buffer[0]) {
                fprintf(stderr, "Error: mismatched tags\n");
                exit(1);
            }
        }
        last_char = current_char;
    }
    if (!isEmpty()) {
        fprintf(stderr, "Error: unclosed tag(s)\n");
        exit(1);
    }
    printf("XML expression is valid\n");
    exit(0);
}
