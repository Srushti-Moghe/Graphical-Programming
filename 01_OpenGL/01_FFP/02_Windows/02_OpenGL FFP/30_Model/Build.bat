cls
cl.exe /c /EHsc 30_Model.cpp
rc.exe text.rc
link.exe 30_Model.obj text.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
30_Model.exe