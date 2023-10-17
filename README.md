# Simple Shell

This is a simple shell written in C. It provides a command-line interface to the user allowing them to execute programs and scripts.

## Description

The shell is designed to interpret and execute commands entered by the user. It provides an interface between the user and the kernel, executing programs called commands. For example, if a user enters `ls`, then the shell executes the `ls` command.

## Installation

The shell is designed to run on Ubuntu 20.04 LTS. To install, follow these steps:

1. Clone the repository using the command: `git clone "https://github.com/Nwachiemu/simple_shell.git"`
2. Navigate to the cloned repository.
3. Compile the code using: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Usage

You can run the shell in either interactive mode or non-interactive mode:

- Interactive mode: Run the shell with the command: `./hsh`
- Non-interactive mode: Pipe commands to the shell with the command: `echo "command" | ./hsh`

## Contributors

This shell was developed by Nwachiemu and Ngwuebo. You can reach them at emuchaynwachi@gmail.com and nnathaniel155@gmail.com respectively
