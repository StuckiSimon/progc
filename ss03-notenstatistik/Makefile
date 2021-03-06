CC      = gcc
CFLAGS  = -g
TARGET := bin/markStats

# directories to create (and remove upon cleanup)
CREATEDIRS    := bin doc

# full path to the target
FULLTARGET    := $(CURDIR)/$(TARGET)

SOURCES       := src/main.c src/markStats.c

CUNITLIBDIR   := $(CURDIR)/../../CUnit/lib
TSTLIBDIR     := $(CURDIR)/../testlib/bin

TSTSOURCES    := tests/test.c

OBJECTS       := $(SOURCES:%.c=%.o)
TSTOBJECTS    := $(TSTSOURCES:%.c=%.o) # list of gcc -c  ... produced *.o files
TSTDEPS       := $(TSTSOURCES:%.c=%.d) # list of gcc -MD ... produced *.d files
TSTTARGET     := $(CURDIR)/tests/runtest

# targets which get always visited (without checking any up-to-date state)
.PHONY: default clean test doc mkdir run

default: $(FULLTARGET)
	$(MAKE) run
	@echo "#### $< built ####"

run:
	$(TARGET)

$(FULLTARGET): mkdir $(OBJECTS) Makefile
	$(LINK.c) -o $@ $(OBJECTS)

doc:
	doxygen ../Doxyfile > /dev/null
	@echo "#### $@ done ####"

clean:
	$(RM) $(TARGET) $(OBJECTS) $(DEPS) $(TSTTARGET) $(TSTOBJECTS) $(TSTDEPS) $(wildcard */*~ *~ tests/*.txt)
	$(RM) -r $(CREATEDIRS)
	@echo "#### $@ done ####"

test: $(TSTTARGET)
	(cd tests; $(TSTTARGET))
	@echo "#### $< executed ####"

$(TSTTARGET): $(FULLTARGET) $(TSTOBJECTS)
	gcc -o $(TSTTARGET) tests/test.c src/markStats.c -L$(CUNITLIBDIR) -lcunit -L$(TSTLIBDIR) -lprogctest
	@echo "#### $@ built ####"

mkdir:
	-mkdir -p $(CREATEDIRS)
