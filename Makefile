CC = g++
NC = nasm

CFLAGS_O = -Wpedantic -Wextra -Wall -g3 -c -O2 -mavx2 -DNDEBUG
CFLAGS = -Wpedantic -Wextra -Wall -g3 -O2 -mavx2 -DNDEBUG

NASMFLAGS = -w+all -f elf64

LFLAGS = -no-pie

SRC_N = NoOptimizations/HashTableFunctions.cpp List/List.cpp
SRC_O = Optimizations/HashTableFunctions.cpp List/List.cpp

SRC_ASM_1 = Optimizations/CRC32.asm
SRC_ASM_2 = Optimizations/isalpha.asm

hashtable_o = hashtable_o
hashtable = hashtable

all: $(hashtable_o) $(SRC_O) $(SRC_ASM_1) $(SRC_ASM_2) $(hashtable) $(SRC_N)

$(hashtable_o): $(SRC_O) $(SRC_ASM_1) $(SRC_ASM_2)
	$(CC) $(CFLAGS_O) $(SRC_O)

	$(NC) $(NASMFLAGS) $(SRC_ASM_1)
	
	$(NC) $(NASMFLAGS) $(SRC_ASM_2)

	$(CC) $(LFLAGS) Optimizations/*.o *.o -o $(hashtable_o)

	rm Optimizations/*.o *.o

$(hashtable): $(SRC_N)
	$(CC) $(CFLAGS) $(SRC_N) -o $(hashtable)

clean:
	rm *.o
	
