#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MESSAGE_LENGHT 128
#define COMMAND_SIZE 256

int main(void) {
    char usr_input_msg[MESSAGE_LENGHT] = "";
    char commit_msg[COMMAND_SIZE] = "";
    
    // Prompt user for commit message
    printf("Type your commit message: ");
    fgets(usr_input_msg, MESSAGE_LENGHT, stdin);
    
    // Remove enter
    if (MESSAGE_LENGHT > 0 && usr_input_msg[MESSAGE_LENGHT - 1] == '\n') {
        usr_input_msg[MESSAGE_LENGHT - 1] = '\0';
    }
    
    // Make commit command
    strcat(commit_msg, "git commit -m \"");
    strcat(commit_msg, usr_input_msg);
    strcat(commit_msg, "\"");
    
    system("git add .");
    system(commit_msg); // This executes "git commit -m "commit_msg""

    // Try executing git push
    int push_result = system("git push");
    
    // Check if git push failed
    if (push_result != 0) {
        printf("Initial git push failed. Trying 'git push --set-upstream origin main'\n");
        system("git push --set-upstream origin main");
    }
    else{
        printf("\n\nCommit pushed succesfully!\n");
    }

    return 0;
}
