#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int count = 0;  // Counter to track how many times SIGINT is received

// Custom signal handler for SIGINT
void handle_sigint(int sig) {
    count++;  // Increment the counter when SIGINT is received

    printf("SIGINT signal received, capture number: %d\n", count);

    if (count == 2) {
        // Restore the default behavior for SIGINT after receiving 2 signals
        signal(SIGINT, SIG_DFL);
        printf("Default behavior for SIGINT has been restored.\n");
    }
}

int main() {
    // Set the custom handler for SIGINT
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to send the SIGINT signal...\n");

    // Keep the program running to capture signals
    while (1) {
        sleep(1);
    }

    return 0;
}
