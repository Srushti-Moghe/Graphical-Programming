cls

cl.exe /c /EHsc /I "C:\glew\include"  01_perfragment.cpp

rc.exe OGL.rc

link.exe 01_perfragment.obj OGL.res User32.lib GDI32.lib /LIBPATH:C:\glew\lib\Release\x64 /SUBSYSTEM:WINDOWS

01_perfragment.exe

