TARGET = CurveAnalyzer.so
OFILES = sipCurveAnalyzercmodule.o sipCurveAnalyzerCurveAnalyzer.o
HFILES = sipAPICurveAnalyzer.h 

CC = gcc
CXX = g++
LINK = g++
CPPFLAGS = -DNDEBUG -DQT_NO_DEBUG -DQT_CORE_LIB -DQT_GUI_LIB -I. -Ipureqt -I/usr/include/python2.7 -I/usr/share/qt/mkspecs/default -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I/usr/X11R6/include
CFLAGS = -pipe -fPIC -O2 -g -march=i686 -Wall -W -D_REENTRANT
CXXFLAGS = -pipe -fPIC -O2 -g -march=i686 -Wall -W -D_REENTRANT
LFLAGS = -Wl,-O1,--sort-common,--as-needed,-z,relro,--hash-style=gnu -shared  -Wl,-O1 -Wl,--version-script=CurveAnalyzer.exp
LIBS = -Lpureqt -L. -L/usr/lib -L/usr/X11R6/lib -lCurveAnalyzer -lQtCore -lQtGui -lXext -lX11 -lm -lpthread
MOC = /usr/bin/moc
.SUFFIXES: .c .o .cpp .cc .cxx .C


.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

all: $(TARGET)

$(OFILES): $(HFILES)

$(TARGET): $(OFILES)
	@echo '{ global: initCurveAnalyzer; local: *; };' > CurveAnalyzer.exp
	$(LINK) $(LFLAGS) -o $(TARGET) $(OFILES) $(LIBS)

install: $(TARGET)
	@test -d $(DESTDIR)/usr/lib/python2.7/site-packages || mkdir -p $(DESTDIR)/usr/lib/python2.7/site-packages
	cp -f $(TARGET) $(DESTDIR)/usr/lib/python2.7/site-packages/$(TARGET)
	strip $(DESTDIR)/usr/lib/python2.7/site-packages/$(TARGET)
	@test -d $(DESTDIR)/usr/share/sip/curveanalyzer || mkdir -p $(DESTDIR)/usr/share/sip/curveanalyzer
	cp -f curveanalyzer.sip $(DESTDIR)/usr/share/sip/curveanalyzer/curveanalyzer.sip

clean:
	-rm -f $(TARGET)
	-rm -f sipCurveAnalyzercmodule.o
	-rm -f sipCurveAnalyzerCurveAnalyzer.o
	-rm -f CurveAnalyzer.exp
