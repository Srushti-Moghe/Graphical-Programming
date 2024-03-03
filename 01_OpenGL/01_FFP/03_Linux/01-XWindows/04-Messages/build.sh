gcc -c -o XWindows.o -I /usr/include XWindows.c   
gcc -o XWindows -L /usr/lib/x86_64-linux-gnu  XWindows.o -lX11
