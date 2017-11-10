# makefile .fr tipsv

FC	= gfortran
FFLAGS	= -O4
OBJS	= calmat.f trialf.f others.f rk3.f glu2.f dcsymbdl0.f dcsymbdl.f tipsv.f
OBJS2    = calmat.f trialf.f others.f rk3.f glu2.f dcsymbdl0.f dcsymbdl.f tipsv_single.f

program0=tipsv
program1=tipsvSingle

all : $(program0) $(program1)

$(program0): $(OBJS)
	$(FC) $(FFLAGS) $(OBJS)  -o $@ 

$(program1): $(OBJS2)
	        $(FC) $(FFLAGS) $(OBJS2)  -o $@ 
		


clean:
	rm -f tipsv tipsvSingle
