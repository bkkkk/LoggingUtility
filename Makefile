CC = g++
ARCHIVE = ar
OBJDIR = obj
OBJ = $(OBJDIR)/LoggingUtility.o
INCLUDE = LoggingUtility
STATDIR = StandAlone
STATLIB = $(STATDIR)/libLoggingUtility.a
SRC = ./src/LoggingUtility.cxx

all: $(OBJ) $(STATLIB)
	
$(OBJ):
	mkdir -p $(OBJDIR)
	$(CC) -c $(SRC) -o $(OBJ) -I$(INCLUDE)

$(STATLIB):
	mkdir -p $(STATDIR)
	$(ARCHIVE) rvs $(STATLIB) $(OBJ)

clean:
	rm -rf obj/ StandAlone/
