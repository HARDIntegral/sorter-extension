CC = gcc
MOVE = mv
CFLAGS = -c -Wall
INCLUDEDIR = includes/
SORTDIR = sorters/
OBJDIR = ../obj/
BUILDDIR = ../build/
OBJ = sort

all: $(OBJ)

$(OBJ): main.o list.o vector.o bubble.o counting.o heap.o insertion.o merge.o quick.o radix.o selection.o
	$(CC) main.o list.o vector.o bubble.o counting.o heap.o insertion.o merge.o quick.o selection.o -o $(OBJ)
	$(MOVE) main.o $(OBJDIR)
	$(MOVE) list.o $(OBJDIR)
	$(MOVE) vector.o $(OBJDIR)
	$(MOVE) bubble.o $(OBJDIR)
	$(MOVE) counting.o $(OBJDIR)
	$(MOVE) heap.o $(OBJDIR)
	$(MOVE) insertion.o $(OBJDIR)
	$(MOVE) merge.o $(OBJDIR)
	$(MOVE) quick.o $(OBJDIR)
	$(MOVE) radix.o $(OBJDIR)
	$(MOVE) selection.o $(OBJDIR)
	$(MOVE) $(OBJ).exe $(BUILDDIR)
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
	$(BUILDDIR)./sort
	@echo ""
	@echo "------------------------------------------------------------------------------------------"
	@echo "[EXECUTION COMPLETE]"

clean:
	@echo "[Cleaning]"
	rm -rf *.exe
	rm -rf $(OBJ)*.o

py:
	py gui.py