// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main()
{
	int fd;

	// FIFO file path
	char * myfifo = "/tmp/server_pipe";

	// Creating the named file(FIFO)
	// mkfifo(<pathname>, <permission>)
	mkfifo(myfifo, 0666);

	char arr1[80], arr2[80];
	//while (1){
	    // Prompt user for input
        printf("Enter range (format: RANGE XX YY): ");
	
		// Open FIFO for write only
		fd = open(myfifo, O_WRONLY);

		// Take an input arr2ing from user.
		// 80 is maximum length
		fgets(arr2, 80, stdin);

		// Convert command (first word) to uppercase for consistency
        char command[6];
        int lower, upper;
        if (sscanf(arr2, "%5s %d %d", command, &lower, &upper) == 3) {
            toUpperCase(command);
            snprintf(arr2, sizeof(arr2), "%s %d %d", command, lower, upper);
        }

		// Write the input arr2ing on FIFO
		// and close it
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		// Open FIFO for Read only
		fd = open(myfifo, O_RDONLY);

		// Read from FIFO
		read(fd, arr1, sizeof(arr1));

		// Print the read message
		printf("Client: %s\n", arr1);
		close(fd);
	//}
	return 0;
}

