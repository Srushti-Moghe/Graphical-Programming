cls

cl.exe /c /EHsc *.cpp

rc.exe *.rc

link.exe  *.obj *.res user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS 

*.exe

*.exe