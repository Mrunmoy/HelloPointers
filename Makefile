# The variable CC will be the compiler to use.
CC=gcc


#The Target Binary Program
TARGET      := HelloPointers

# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := .
BUILDDIR    := obj
TARGETDIR   := bin
DEPEXT      := d
SRCEXT      := c
OBJEXT      := o

# CFLAGS will be the options to pass to the compiler.
CFLAGS      := -c -Wall -O3 -g -Wno-pointer-to-int-cast

# LDFLAGS will be the options to pass to the linker.
LDFLAGS=

INC         := -I$(INCDIR)
INCDEP      := -I$(INCDIR)


SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))


# Default Make all
all: directories $(TARGET)

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)	
	@mkdir -p $(BUILDDIR)
	
$(EXECUTABLE): $(OBJECTS)
	mkdir -p $(BUILDDIR)
	mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
        
#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(RM) -rf $(TARGETDIR)
	
#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)
	
#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
.PHONY: all remake clean
