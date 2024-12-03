#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MESSAGE_LENGTH 128
#define COMMAND_SIZE 256

int main(void) {
    char *usr_input_msg;
    char commit_msg[COMMAND_SIZE] = "";

    // Check for an initialized git repo
    int is_git = system("git rev-parse --is-inside-work-tree > /dev/null 2>&1");

    if (is_git != 0) {
        fprintf(stderr, "Error: not a git repository.\nTry running \"git init\" to initialize it.\n");
        return 1;
    }

    // Stage changes
    system("git add .");

    // Check if there has been a commit already before
    int has_commit = system("git rev-parse HEAD > /dev/null 2>&1");

    // If this isn't a first commit, check for changes
    if (has_commit == 0) {
        int changes = system("git diff-index --quiet HEAD --");
        if (changes == 0) {
            printf("\033[1;33mThere are no changes to commit.\033[0m\n");
            return 0;
        }
        // Print the last commit message and date
        printf("\033[1;35mLast commit:\n\033[0m"); // Resetting the color afterwards
        system("git --no-pager log -1 --pretty=format:'\033[1;32m%s\033[0m | by \033[1;33m%an\033[0m on \033[1;35m%ad\033[0m' --date=short");
        printf("\n\n");
    } else {
        printf("\033[1;33mThis is your first commit in this repo.\033[0m\n");
    }

    // Ask user for commit message
    usr_input_msg = readline("\033[1;36mType your commit message: \n\033[0m");
    if (usr_input_msg == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Make and run commit command
    snprintf(commit_msg, COMMAND_SIZE, "git commit -m \"%s\"", usr_input_msg);
    system(commit_msg);  // This executes "git commit -m "commit_msg""

    // Free the input message
    free(usr_input_msg);

    // Try executing git push
    int push_result = system("git push");

    // If git push fails, then try to execute it with "--set-upstream"
    if (push_result != 0) {
        printf("\033[1;33mInitial git push failed. Trying 'git push --set-upstream origin master'\n\033[0m");
        
        // Try pushing with origin master
        push_result = system("git push --set-upstream origin master");
        if (push_result != 0) {
            printf("\033[1;33mInitial git push failed. Trying 'git push --set-upstream origin main'\n\033[0m");
            // Try pushing with origin main
            push_result = system("git push --set-upstream origin main");
            if (push_result != 0) {
                fprintf(stderr, "\033[1;31mCouldn't push the commit to github. You're on your own now :/\n\033[0m");
                return 1;
            } else {
                // If pushing with origin main works
                printf("\033[1;32m\nCommit pushed successfully! (using 'git push --set-upstream origin main')\n\033[0m");
            }

        } else {
            // If pushing with origin master works
            printf("\033[1;32m\nCommit pushed successfully! (using 'git push --set-upstream origin master')\n\033[0m");
        }
    } else {
        // If pure git push works
        printf("\033[1;32m\nCommit pushed successfully!\n\033[0m");
    }
    return 0;
}
