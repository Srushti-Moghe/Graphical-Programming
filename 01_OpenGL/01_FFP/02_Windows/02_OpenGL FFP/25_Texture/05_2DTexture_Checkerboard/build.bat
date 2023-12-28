cls

del *.obj
del *.exe
del *.txt

cl.exe /c /EHsc /I ..\..\Include\ *.cpp 

rc.exe /i ..\..\Include\ ..\..\Resource\Window.rc 

rc.exe /i ..\..\Include\ text.rc

link *.obj ..\..\Resource\Window.res text.res user32.lib gdi32.lib kernel32.lib /OUT:..\..\bin\%1.exe  /SUBSYSTEM:WINDOWS

del *.obj

..\..\bin\%1.exe
