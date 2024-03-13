cls
cl.exe /c /EHsc DSDemoScene.cpp
rc.exe OGL.rc
link.exe DSDemoScene.obj OGL.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
DSDemoScene.exe