# makefile for tish

FC	= gfortran
FFLAGS	= -O4
OBJS	= calmat.f trialf.f others.f dclisb.f dclisb3.f tish.f
OBJS1    = calmat.f trialf.f others.f dclisb.f dclisb3.f tish_single.f

program0=tish
program1=tishSingle

all : $(program0) $(program1)

$(program0): $(OBJS)
	$(FC) $(FFLAGS) $(OBJS) -o $@

$(program1): $(OBJS1)
	$(FC) $(FFLAGS) $(OBJS1) -o $@
clean:
	rm -f $(program0) $(program1) 
