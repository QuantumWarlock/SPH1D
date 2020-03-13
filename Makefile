# SHELL
SHELL       =   /bin/bash


# COMPILER
CCP         =   g++ -std=gnu++11


# PHONY
.PHONY: all clean


# DIRS
SRCDIR      =   src
INCDIR      =   inc
OBJDIR      =   obj


# OBJS
SRCOBJS     =   $(SRCDIR)/Timer.o $(SRCDIR)/sph1D.o $(SRCDIR)/init.o $(SRCDIR)/DataOut.o
SRCOBJS    +=	$(SRCDIR)/timeIntegrator.o $(SRCDIR)/dtStep.o $(SRCDIR)/symFind.o

 
# RULES
%.o: %.cpp
	$(CCP) -I$(INCDIR) -o $@ -c $^

    
all: $(SRCOBJS)
	$(CCP) -I$(INCDIR) $(SRCOBJS) -o sph1D.x
    

clean:
	rm -f $(SRCDIR)/*.o *.x
