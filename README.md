OVERVIEW

This project demonstrates inter-process communication (IPC) using **NAMED PIPES** (FIFO) on Unix-based systems. 
It includes two components:
Server: Listens for requests from the client via a named pipe, computes prime numbers within a given range, 
and sends the result back.
Client: Sends a request to the server (e.g., RANGE 10 50) and displays the server’s response.

Project Structure
server.cpp: Server code that listens for client requests and processes them.
prog1.c: Client code that sends requests to the server and prints the server’s response.

How It Works
Server : Creates a named pipe (FIFO) at /tmp/server_pipe. Waits for client requests of the form RANGE XX YY.
If the request is valid: Computes all prime numbers in the given range [XX, YY]. Sends the list of primes back to the client.
If the request is malformed, it responds with: "Malformed request."

Client (Prog1.c) : Prompts the user to enter a request (e.g., RANGE 10 50). Sends the request to the server via the named pipe.
Waits for the server’s response and prints it to the terminal.

HOW TO RUN: 

1. Compile the Server and Client
Open a terminal and run: g++ server.cpp -o server
                        g++ client.cpp -o client

2. Run the Server
In a terminal, execute: "./server"
You should see: Server listening on /tmp/server_pipe...

3. Run the Client
In another terminal, execute: "./client"
When prompted, enter a request:
Enter a request (e.g., RANGE 10 50): RANGE 10 50 (FYI, it is not case sensitive)

4. Sample Output
Client Terminal:
Enter a request (e.g., RANGE 10 50): RANGE 10 50
Server response: 11 13 17 19 23 29 31 37 41 43 47 

If the request is malformed:
Enter a request (e.g., RANGE 10 50): INVALID INPUT
Server response: Malformed request.

ERROR HANDLING:

Malformed Requests: The server responds with "Malformed request." if the input is not in the correct format.

Pipe Errors: If the named pipe cannot be created or accessed, appropriate error messages are displayed.

Blocking Behavior: The server waits for a request and responds one at a time (simple single-threaded implementation).

CLEANUP: 

After testing, remove the named pipe to avoid clutter: rm /tmp/server_pipe