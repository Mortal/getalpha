all: getalpha_fast getalpha_slow

COMPILEFLAGS := -O3
CPPFLAGS += -DBUFSIZE=$(BUFSIZE)
CFLAGS += $(COMPILEFLAGS) -std=c99
CXXFLAGS += $(COMPILEFLAGS)

getalpha_fast: getalpha_fast.o getalpha_fast_report.o getalpha_report.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

getalpha_slow: getalpha_slow.o getalpha_report.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) getalpha_fast getalpha_slow *.o
