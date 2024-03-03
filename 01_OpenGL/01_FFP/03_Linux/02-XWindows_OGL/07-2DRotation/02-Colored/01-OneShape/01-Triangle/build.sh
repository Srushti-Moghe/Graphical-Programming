gcc -c -o Win_OGL.o -I /usr/include Win_OGL.c   
gcc -o Win_OGL -L /usr/lib/x86_64-linux-gnu  Win_OGL.o -lX11 -lGL -lGLU 
