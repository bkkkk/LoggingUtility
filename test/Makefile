CC = g++
INCLUDE = ../LoggingUtility
STATDIR = ../StandAlone
STATLIB = LoggingUtility
EXECTUABLE = ut_LoggingUtility
SRC = ut_LoggingUtility.cxx
BINDIR = ../test-bin

all: $(EXECTUABLE)
	
$(EXECTUABLE):
	mkdir -p $(BINDIR)
	$(CC) $(SRC) -o $(BINDIR)/$(EXECTUABLE) -L$(STATDIR) -l$(STATLIB) -I$(INCLUDE)

clean:
	rm -rf $(BINDIR)
