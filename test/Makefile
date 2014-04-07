CC = g++
CFLAGS = -I/usr/local/include/LoggingUtility
LDFLAGS = -lLoggingUtility
EXECTUABLE = ut_LoggingUtility
SOURCE = ut_LoggingUtility.cxx
BINDIR = ../test-bin

all: $(EXECTUABLE)
	
$(EXECTUABLE):
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(EXECTUABLE) $(SOURCE)

clean:
	rm -rf $(BINDIR)
