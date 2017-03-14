# makefile for dat2sac

OBJS = dat2sac.o
CC = gcc
#CC = /opt/intel/cc/9.0/bin/icc
CFLAGS = -L/usr/lib -g

all:
	make dat2sac

dat2sac: $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) $(SACDIR)/lib/sacio.a -o dat2sac
.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJS) dat2sac
