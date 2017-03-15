# makefile for spcsac
CC = g++
#CC = /opt/intel/cc/9.0/bin/icc
CFLAGS = -g -fpermissive -L/usr/lib 
OBJS = spcsac.o

all:
	make spcsac

spcsac: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o spcsac;
.c.o: 
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) spcsac

