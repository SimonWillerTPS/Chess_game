CFLAGS			=	-std=c++11 -g -Wall
TARGET			=	echecs
DOC				=	doc_file
DOCDIR			=	doc
SRCDIR			= 	src
OBJDIR			= 	obj
INCLUDE_PATH	=	./include

SOURCES			:=	$(wildcard $(SRCDIR)/*.cc)
INCLUDES		:=	$(wildcard $(INCLUDE_PATH)/*.h)
OBJECTS			:=	$(SOURCES:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)

$(TARGET) :	$(OBJECTS)
	g++		-o $@ $^ $(CFLAGS)

$(OBJECTS):				$(OBJDIR)/%.o:	$(SRCDIR)/%.cc
	mkdir	-p $(OBJDIR)
	g++		-o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)

$(DOC) :
	@doxygen $(DOCDIR)/$(DOC)

all : $(DOC) $(TARGET)
	@echo " ----- \e[32mLinking complete\e[39m ----- "

clean :
	rm -rf doc/html/
	rm -f $(OBJDIR)/*.o
	rm -f $(OBJDIR)/*.gcda
	rm -f $(OBJDIR)/*.gcno
	rm -f $(TARGET)
	@echo " ----- \e[32mCleaning complete\e[39m ----- "

open_doc :
	@sensible-browser $(DOCDIR)/html/index.html
