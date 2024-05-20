# Makefile para compilar o arquivo main.c e gerar o executável linearscan

# Nome do compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -std=c99

# Arquivos fonte
SRCS = main.c

# Arquivos objetos gerados pela compilação
OBJS = $(SRCS:.c=.o)

# Nome do executável
EXEC = linearscan

# Regra de compilação para gerar os arquivos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Regra para limpar os arquivos objetos e o executável
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para reconstruir o projeto do zero
rebuild: clean $(EXEC)

# Indica que os alvos clean e rebuild não são arquivos
.PHONY: clean rebuild
