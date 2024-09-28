#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MESSAGE_LENGTH 128
#define COMMAND_SIZE 256

int main(void) {
    char usr_input_msg[MESSAGE_LENGTH] = "";
    char commit_msg[COMMAND_SIZE] = "";
    
    // Stage changes
    system("git add .");

    // Check if there are any changes to commit
    int changes = system("git diff-index --quiet HEAD --");

    if (changes == 0) {
        printf("There are no changes to commit.\n");
        return 0;
    }

    // Prompt user for commit message
    printf("Type your commit message: ");
    fgets(usr_input_msg, MESSAGE_LENGTH, stdin);
    
    // Remove newline character if it exists
    size_t len = strlen(usr_input_msg);
    if (len > 0 && usr_input_msg[len - 1] == '\n') {
        usr_input_msg[len - 1] = '\0';
    }
    
    // Make commit command
    snprintf(commit_msg, COMMAND_SIZE, "git commit -m \"%s\"", usr_input_msg);
    system(commit_msg); // This executes "git commit -m "commit_msg""
    
    // Try executing git push
    int push_result = system("git push");
    
    // If git push fails, then try to execute it with "--set-upstream"
    if (push_result != 0) {
        printf("Initial git push failed. Trying 'git push --set-upstream origin main'\n");
        system("git push --set-upstream origin main");
    } else {
        printf("\nCommit pushed successfully!\n");
    }

    return 0;
}
