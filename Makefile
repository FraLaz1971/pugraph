CC = gcc
RM = rm -f
PUHOME = /home/francesco/Software/plotutils-2.6
CPPFLAGS = -I$(PUHOME)/include
CFLAGS = -I$(PUHOME)/lib
LDFLAGS = -L$(PUHOME)/lib
PU_LIBS = -lplot -lpng -lz -lm
X11_LIBS = -lXaw -lXmu -lXt -lSM -lICE -lXext -lX11
LIBS = $(PU_LIBS) $(X11_LIBS)
OEXE = .o
EEXE =
TARGET1 = fpugraph
TARGET2 = firstmap
TARGET3 = c_graph
TARGETS = $(TARGET1) $(TARGET2) $(TARGET3)
OBJS = $(TARGET1)$(OEXE) $(TARGET2)$(OEXE) $(TARGET3)$(OEXE)

.PHONY: all clean

all: $(TARGETS)

$(TARGET1)$(OEXE): $(TARGET1).c
	$(CC) $(CPPFLAGS) -c $(TARGET1).c

$(TARGET1)$(EEXE): $(TARGET1)$(OEXE)
	$(CC) $(TARGET1)$(OEXE) -o $(TARGET1) $(LDFLAGS) $(PU_LIBS)

$(TARGET2)$(OEXE): $(TARGET2).c
	$(CC) $(CPPFLAGS) -c $(TARGET2).c

$(TARGET2)$(EEXE): $(TARGET2)$(OEXE)
	$(CC) $(TARGET2)$(OEXE) -o $(TARGET2) $(LDFLAGS) $(LIBS)

$(TARGET3)$(OEXE): $(TARGET3).c
	$(CC) $(CPPFLAGS) -c $(TARGET3).c

$(TARGET3)$(EEXE): $(TARGET3)$(OEXE)
	$(CC) $(TARGET3)$(OEXE) -o $(TARGET3) $(LDFLAGS) $(LIBS)
	
clean:
	$(RM) $(TARGETS) $(OBJS)
