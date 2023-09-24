TARGETOS = BOTH
!include <win32.mak>

lflags  = /NODEFAULTLIB /INCREMENTAL:NO /RELEASE /NOLOGO
dlllflags = $(lflags) -entry:_DllMainCRTStartup$(DLLENTRY) -dll

all: textadeptcm.dll

textadeptcm.dll: textadeptcm.obj textadeptcm.res
	$(implib) -machine:$(CPU) -def:textadeptcm.def $** -out:textadeptcm.lib
	$(link) $(dlllflags) -base:0x1C000000 -out:$*.dll $** $(olelibsdll) shell32.lib msvcrt.lib textadeptcm.lib comctl32.lib textadeptcm.exp
	mt -manifest $*.manifest -outputresource:$*.dll;2

.cpp.obj:
	$(cc) $(cflags) $(cvarsdll) $*.cpp

textadeptcm.res: textadeptcm.rc
	$(rc) $(rcflags) $(rcvars) textadeptcm.rc

clean:
	-1 del textadeptcm.dll textadeptcm.lib textadeptcm.dll.manifest textadeptcm.obj textadeptcm.exp textadeptcm.res