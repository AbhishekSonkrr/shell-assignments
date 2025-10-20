CC = gcc
CFLAGS = -Wall -Wextra -std=c11

PROGS = ex14_a_stdio ex14_b_syscall ex15_interactive ex15_args ex15_redir \
	ex16_cat ex16_ls ex16_mv ex17_stat ex18_pipe ex19_fork

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
