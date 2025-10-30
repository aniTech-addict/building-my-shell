# @ MyShell — A Simple UNIX-like Shell in C++

A lightweight shell written from scratch in **C++17**, built to understand how process control, forking, and command execution work in Linux systems.

This project is part of a learning journey — understanding the internals of shells like Bash or Zsh, one feature at a time.

---

## @ Features (Current Progress)


### @ Built-in commands:
@ Command prompt that accepts user input  

  - `cd`   —   Change directory  
  - `pwd`  —  Print current working directory  
  - `help` — Show basic usage info  
  - `exit` — Quit the shell  
  - `clear` — Clear the screen
  - `echo` -- Print a string
  - `ls` -- List files in current directory
  - `cat` -- Print the contents of a file

  ----etc-----

 Executes in a clean loop until manually exited  

# @ Upcoming (Planned):

- Input/output redirection (`>`, `<`)  
- Piping (`|`)  
- Background processes (`&`)  
- Command history and signals (`Ctrl+C`)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

## 🧩 Build Instructions

### 1️. Prerequisites

Make sure you have:
- `g++` (C++17 or higher)
- `make`
- Linux or WSL environment

Check versions:
```bash
g++  --version
make --version

#RUN EXECUTABLE:
```bash
    ./shell
```

You’ll see:

```basg
    my_shell>
```

From here you can use commands like:

```bash
    my_shell> pwd
    my_shell> cd ..
    my_shell> help
    my_shell> exit
```

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

### @Cleaning build files

To remove compiled object files and executable:

```bash
    make clean
```