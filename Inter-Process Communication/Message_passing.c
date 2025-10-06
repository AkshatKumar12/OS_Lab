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
    msgid = msgget(key, 0666 | IPC_CREAT);      // 0 means "current machine || current user"
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
/*
*-----------------------------------------------------------------------------------------------------------------------------------------------*
*-----------------------------------------------------------------------------------------------------------------------------------------------*
1. ftok()   --> creates a unique key based on a filename and a project identifier, used for IPC mechanisms.
2. msgget() --> either returns the message queue identifier for a newly created message queue or returns the identifier for a queue,
                which exists with the same key value.
3. msgsnd() --> Data is placed onto a message queue by calling msgsnd(), which sends a message to the queue.
4. msgrcv() --> Used to receive (read) a message from a message queue, removing it from the queue.
5. msgctl() --> Performs various control operations on the message queue, such as deleting the queue or getting its status.


Octal permissions like 0666 specify access rights for files and FIFOs. The digits represent permissions for the owner, group, and others.
Each digit is a sum of: 4 (read), 2 (write), and 1 (execute).
For example, 0666 means read and write permissions for everyone (owner, group, others), but no execute permission.
*-----------------------------------------------------------------------------------------------------------------------------------------------*
*-----------------------------------------------------------------------------------------------------------------------------------------------*




*/