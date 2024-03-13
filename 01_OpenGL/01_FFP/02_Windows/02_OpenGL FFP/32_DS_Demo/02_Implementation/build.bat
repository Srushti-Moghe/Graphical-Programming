cls
cl.exe /c /EHsc 32_DSDemo.cpp
rc.exe OGL.rc
link.exe 32_DSDemo.obj OGL.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
32_DSDemo.exe