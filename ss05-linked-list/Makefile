CC             = gcc
CFLAGS         = -g
TARGET        := bin/linkedList

# directories to create (and remove upon cleanup)
CREATEDIRS    := bin doc

# full path to the target
FULLTARGET    := $(CURDIR)/$(TARGET)

MODULES       := src/list.c src/person.c src/validator.c
SOURCES       := src/main.c $(MODULES)

TSTLIBDIR     := $(CURDIR)/../testlib/bin

INTEGSOURCES  := tests/test.c
UNITSOURCES   := tests/list.c

OBJECTS       := $(SOURCES:%.c=%.o)
TSTOBJECTS    := $(UNITSOURCES:%.c=%.o) $(INTEGSOURCES:%.c=%.o) # list of gcc -c  ... produced *.o files
TSTDEPS       := $(UNITSOURCES:%.c=%.d) $(INTEGSOURCES:%.c=%.d) # list of gcc -MD ... produced *.d files
# binaries must be in same folder as sources in order to use input files
UNITTARGET    := $(CURDIR)/tests/rununittest
INTEGTARGET   := $(CURDIR)/tests/runintegrationtest

# targets which get always visited (without checking any up-to-date state)
.PHONY: default clean test doc mkdir run integration-test unit-test

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
	$(RM) $(TARGET) $(OBJECTS) $(DEPS) $(UNITTARGET) $(INTEGTARGET) $(TSTOBJECTS) $(TSTDEPS) $(wildcard */*~ *~ tests/*.txt)
	$(RM) -r $(CREATEDIRS)
	@echo "#### $@ done ####"

test: unit-test integration-test

unit-test: $(UNITTARGET)
	(cd tests; $(UNITTARGET))
	@echo "#### $< executed ####"

$(UNITTARGET): $(FULLTARGET) $(TSTOBJECTS)
	$(CC) -o $(UNITTARGET) $(UNITSOURCES) $(MODULES) -lcunit -L$(TSTLIBDIR) -lprogctest
	@echo "#### $@ built ####"

integration-test: $(INTEGTARGET)
	(cd tests; $(INTEGTARGET))
	@echo "#### $< executed ####"

$(INTEGTARGET): $(FULLTARGET) $(TSTOBJECTS)
	$(CC) -o $(INTEGTARGET) $(INTEGSOURCES) $(MODULES) -lcunit -L$(TSTLIBDIR) -lprogctest
	@echo "#### $@ built ####"

mkdir:
	-mkdir -p $(CREATEDIRS)
