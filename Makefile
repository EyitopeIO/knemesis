# Today:	6-Nov-2022
# Who:		Eyitope Adelowo



# .PHONY:	uspace

include includes.mk


$(info User object:- $(UOBJS))
$(info Extra object:- $(EOBJS))


.PHONY: all clean


%.c.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ 

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@


# TODO: Build kcomp also
all: knemesis


clean:
	rm -f $(EOBJS) $(UOBJS)


# The user space executable
knemesis: $(UOBJS) $(EOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(UOBJS) $(EOBJS)


	




