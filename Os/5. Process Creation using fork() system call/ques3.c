#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5;

    // create process p2
    pid2 = fork();
    if (pid2 == 0) { // child process p2
        printf("Process p2 with PID %d created by p1 with PID %d\n", getpid(), getppid());

        // create process p3
        pid3 = fork();
        if (pid3 == 0) { // child process p3
            printf("Process p3 with PID %d created by p2 with PID %d\n", getpid(), getppid());
            exit(0); // terminate process p3
        }
        else { // parent process p2
            wait(NULL); // wait for process p3 to terminate
            exit(0); // terminate process p2
        }
    }

    // create process p1
    pid1 = getpid();
    printf("Process p1 with PID %d\n", pid1);

    // create process p4
    pid4 = fork();
    if (pid4 == 0) { // child process p4
        printf("Process p4 with PID %d created by p1 with PID %d\n", getpid(), pid1);

        // create process p5
        pid5 = fork();
        if (pid5 == 0) { // child process p5
            printf("Process p5 with PID %d created by p4 with PID %d\n", getpid(), getppid());
            exit(0); // terminate process p5
        }
        else { // parent process p4
            wait(NULL); // wait for process p5 to terminate
            exit(0); // terminate process p4
        }
    }

    // parent process p1
    wait(NULL); // wait for process p2 to terminate
    wait(NULL); // wait for process p4 to terminate
    exit(0); // terminate process p1
}

