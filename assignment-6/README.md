Exercises 14-19

Build (POSIX required):

These programs require a POSIX environment (Linux, WSL, or macOS). On Windows, use WSL (Windows Subsystem for Linux) for full compatibility.

To build all programs:
1. Open a WSL or Linux terminal.
2. Navigate to the assignment-6 directory:
	cd /mnt/c/Users/abhis/Desktop/shell-assignments/assignment-6
3. Run:
	make

Programs:
- ex14_a_stdio: count blanks using stdio. Usage: ./ex14_a_stdio file
- ex14_b_syscall: count blanks using read syscall. Usage: ./ex14_b_syscall file
- ex15_interactive: read from stdin interactively to count lines/words/chars
- ex15_args: read filename given as argument
- ex15_redir: reads from stdin (for input redirection)
- ex16_cat: simple cat implementation (files or stdin)
- ex16_ls: simple ls (directory listing)
- ex16_mv: move/rename file (uses rename)
- ex17_stat: show file info (type, links, access time, perms)
- ex18_pipe: simple pipe example: ex18_pipe cmd1 cmd2
- ex19_fork: fork demonstration

Examples:
- ./ex14_a_stdio input.txt
- ./ex15_redir < input.txt
- ./ex16_ls .
- ./ex18_pipe ls sort
