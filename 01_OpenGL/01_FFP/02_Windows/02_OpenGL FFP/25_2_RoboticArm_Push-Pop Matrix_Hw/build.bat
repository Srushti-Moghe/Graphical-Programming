cls

del *.obj
del *.exe

cl.exe /c /EHsc /I ..\Include\ *.cpp

rc.exe /i ..\Include\ ..\Resource\*.rc

link *.obj ..\Resource\window.res user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS /OUT:..\bin\%1.exe

del *.obj


..\bin\%1.exe