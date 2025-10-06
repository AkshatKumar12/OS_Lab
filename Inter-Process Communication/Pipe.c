#include<stdio.h> 
#include<unistd.h> 

int main() 
{ 
    int p[2]; // Array to hold the two ends of the pipe: p[0] for reading, p[1] for writing
    int returnstatus; 
    char writing[2][25]= {"HELLO","world"}; // Messages to write into the pipe
    char readmsg[25]; // Buffer to store the message read from the pipe

    returnstatus=pipe(p); // Create a pipe; returns 0 on success, -1 on failure
    if(returnstatus==-1) { 
        printf("pipe not created"); 
    } 

    printf("\nWriting started %s",writing[0]); 
    write(p[1],writing[0],sizeof(writing[0])); // Write the first message to the write end of the pipe

    read(p[0],readmsg,sizeof(readmsg)); // Read from the read end of the pipe into readmsg buffer

    printf("\nReading from pipe-msg1 %s\n",readmsg); 
    return 0; 
} 

/*
*-----------------------------------------------------------------------------------------------------------------------------------------------*
*-----------------------------------------------------------------------------------------------------------------------------------------------*

Inter-process communication (IPC) in Operating Systems refers to mechanisms that allow processes to communicate and synchronize their actions. IPC is essential for processes to share data and resources, coordinate execution, and avoid conflicts.

One common IPC mechanism is the use of files and pipes:

1. **Files**: Processes can communicate by reading from and writing to files. This is a simple form of IPC, but it is not suitable for real-time communication since files are persistent and require explicit management.

2. **Pipes**: Pipes provide a unidirectional communication channel between processes. Data written to the write end of the pipe can be read from the read end. Pipes are commonly used for communication between parent and child processes.

    - In C, the `pipe()` system call creates a pipe, returning two file descriptors: one for reading and one for writing.
    - Example:
      ```c
      int fd[2];
      pipe(fd); // fd[0]: read end, fd[1]: write end
      ```

3. **Named Pipes (FIFOs)**: Unlike regular pipes, named pipes (created using `mkfifo()`) exist as special files in the filesystem and can be used for communication between unrelated processes.

    - Permissions for FIFOs are set using octal notation (e.g., `0666` for read/write permissions for everyone).
    - Example:
      ```c
      mkfifo("myfifo", 0666);
      ```

Other IPC mechanisms include message queues, shared memory, and semaphores, each with their own use cases and advantages.

Octal permissions like 0666 specify access rights for files and FIFOs. The digits represent permissions for the owner, group, and others.
Each digit is a sum of: 4 (read), 2 (write), and 1 (execute).
For example, 0666 means read and write permissions for everyone (owner, group, others), but no execute permission.
*-----------------------------------------------------------------------------------------------------------------------------------------------*
*-----------------------------------------------------------------------------------------------------------------------------------------------*

*/