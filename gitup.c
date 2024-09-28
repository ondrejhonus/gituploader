#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void){
    char usr_commit_msg[128] = "";
    char commit_msg[156] = "";
    system("git add .");
    printf("Type your commit message: ");
    scanf("%s", usr_commit_msg);
    strcat(commit_msg, "git commit -m \"");
    strcat(commit_msg, usr_commit_msg);
    strcat(commit_msg, "\"");
    system(commit_msg);
    system("git push");
    return 0;
}
