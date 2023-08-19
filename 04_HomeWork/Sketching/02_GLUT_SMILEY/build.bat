cls

cl.exe /c /EHsc /I c:/freeglut\include *.cpp

link.exe *.obj /LIBPATH:c:\freeglut\lib\X64 /SUBSYSTEM:CONSOLE /OUT:%~1.exe

%~1.exe