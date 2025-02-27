# client_server_app

# Client-Server Application

This project is a simple client-server application that allows a client to communicate with a server. The server provides a menu of options for the client to choose from and processes the client's requests accordingly.

## Features

- Send a message to the server
- Sum two integer numbers
- Apply a mathematical operation (+, -, *, /) to two integer numbers
- Exit the application

## Prerequisites

- C++ compiler (e.g., g++)
- Make (optional, for using the provided Makefile)

## Steps to reproduce

1) Compile the server and client source files
2) To run project open two terminals and run ./server and ./client execution files.
3) File src_lin/server.cpp contain 3 function that reproduce different tasks.
4) To change task uncomment desired line and recompile file.

## Features

### server_insert_name()

Client send any string to server, server add its string and send back to client

### sum_two_numbers()

Client send to server string lile 23+14, server process data and send back the result

### do_math_operation()

Client send to server sring like with math operations +,-,*,/ 34-7 or 45/3, server process it and send back the result.
