Shell scripts for Assignment 5 exercises 21-25

Files:
- `ex21.sh` — prints the three requested patterns. Usage: `./ex21.sh [i|ii|iii|all]`
- `ex22.sh` — compute sum, mean and variance of numeric arguments. Usage: `./ex22.sh 1 2 3.5`
- `ex23.sh` — compress a string by replacing runs with char+count. Usage: `./ex23.sh aaabbc`
- `ex24.sh` — generate all permutations of provided items. Usage: `./ex24.sh a b c`
- `ex25.sh` — longest common substring for two strings. Usage: `./ex25.sh string1 string2`

Notes:
- The scripts use standard POSIX bash features. On Windows, run them under WSL, Git Bash, or another bash-compatible shell.
- `ex22.sh` uses `bc` for floating-point math; ensure `bc` is installed if you need decimal calculations.
