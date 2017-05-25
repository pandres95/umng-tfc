TARGET   = tfc

CPP      = g++
CFLAGS   = -std=c++11 -Wall -I $(INCDIR)

LINKER   = g++
LFLAGS   =

SRCDIR   = src
INCDIR   = include
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f
mkdir    = mkdir -p


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(mkdir) $(BINDIR)
	@$(LINKER) $(LFLAGS) -o $@ $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(CPP) $(CFLAGS) -I $(INCDIR) -c $< -o $@

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"
