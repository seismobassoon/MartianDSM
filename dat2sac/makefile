# makefile for dat2sac

CC = gcc
#CC = /opt/intel/cc/9.0/bin/icc
CFLAGS = -L/usr/lib -g
OBJS = dat2sac.o

all:
	make dat2sac

dat2sac: $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o dat2sac
.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) dat2sac
