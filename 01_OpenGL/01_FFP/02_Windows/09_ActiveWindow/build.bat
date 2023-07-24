cls

del *.obj

cl.exe /c /EHsc *.cpp

link.exe  *.obj *.res user32.lib gdi32.lib kernel32.lib /OUT:..\bin\%~1.exe

del *.obj

..\bin\%~1.exe