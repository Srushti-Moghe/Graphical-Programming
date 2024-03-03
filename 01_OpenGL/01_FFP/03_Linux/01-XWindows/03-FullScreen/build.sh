gcc -c -o 03-FullScreen.o -I /usr/include 03-FullScreen.c   
gcc -o 03-FullScreen -L /usr/lib/x86_64-linux-gnu  03-FullScreen.o -lX11
