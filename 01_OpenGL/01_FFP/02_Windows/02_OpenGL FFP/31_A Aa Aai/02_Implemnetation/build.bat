cls
cl.exe /c /EHsc 31_AAaAai.cpp
rc.exe OGL.rc
link.exe 31_AAaAai.obj OGL.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
31_AAaAai.exe