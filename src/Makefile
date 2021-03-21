CC = gcc
CFLAGS = -c -Wall
INCLUDEDIR = includes/
SORTDIR = sorters/
OBJ = sort

all: $(OBJ)

$(OBJ): main.o list.o vector.o bubble.o counting.o heap.o insertion.o merge.o quick.o radix.o selection.o
	$(CC) main.o list.o vector.o bubble.o counting.o heap.o insertion.o merge.o quick.o selection.o -o $(OBJ)
	@echo "[BUILD SUCCESSFUL]"

main.o: main.c
	@echo "[BUILDING]"
	$(CC) $(CFLAGS) main.c
list.o: $(INCLUDEDIR)list.c
	$(CC) $(CFLAGS) $(INCLUDEDIR)list.c
vector.o: $(INCLUDEDIR)vector.c
	$(CC) $(CFLAGS) $(INCLUDEDIR)vector.c
bubble.o: $(SORTDIR)bubble.c
	$(CC) $(CFLAGS) $(SORTDIR)bubble.c
counting.o: $(SORTDIR)counting.c
	$(CC) $(CFLAGS) $(SORTDIR)counting.c
heap.o: $(SORTDIR)heap.c
	$(CC) $(CFLAGS) $(SORTDIR)heap.c
insertion.o: $(SORTDIR)insertion.c
	$(CC) $(CFLAGS) $(SORTDIR)insertion.c
merge.o: $(SORTDIR)merge.c
	$(CC) $(CFLAGS) $(SORTDIR)merge.c
quick.o: $(SORTDIR)quick.c
	$(CC) $(CFLAGS) $(SORTDIR)quick.c
radix.o: $(SORTDIR)radix.c
	$(CC) $(CFLAGS) $(SORTDIR)radix.c
selection.o: $(SORTDIR)selection.c
	$(CC) $(CFLAGS) $(SORTDIR)selection.c

exec:
	@echo "[EXECUTING]"
	@echo "------------------------------------------------------------------------------------------"
	@echo ""
	./sort
	@echo ""
	@echo "------------------------------------------------------------------------------------------"
	@echo "[EXECUTION COMPLETE]"

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf *.o