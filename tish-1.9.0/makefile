# makefile for tish

FC	= gfortran
FFLAGS	= -O4
OBJS	= calmat.f trialf.f others.f dclisb.f dclisb3.f tish.f
tish: $(OBJS)
	$(FC) $(FFLAGS) $(OBJS) -o tish
clean:
	rm -f tish
