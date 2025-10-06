#include <stdio.h>  
#include <stdlib.h>  
#include <sys/ipc.h>  
#include <sys/msg.h>  
#include<string.h> 
#include<unistd.h> 

struct msg_buffer {  
    long msg_type;  
    char msg_text[100];  
} message;  
int main()  
 {  
    key_t key;  
    int msgid;  
    // Generate unique key  
    key = ftok("progfile", 65);  
    // Create message queue  
    msgid = msgget(key, 0666 | IPC_CREAT);  
    message.msg_type = 1;  
    if (fork() == 0) {  
        // Child process writes  
        strcpy(message.msg_text, "Message from Child");  
        msgsnd(msgid, &message, sizeof(message), 0);  
    }   
else {  
        // Parent process reads  
        msgrcv(msgid, &message, sizeof(message), 1, 0);  
        printf("Parent read: %s\n", message.msg_text);  
        // Destroy message queue  
        msgctl(msgid, IPC_RMID, NULL);  
    }  
    return 0;  
}