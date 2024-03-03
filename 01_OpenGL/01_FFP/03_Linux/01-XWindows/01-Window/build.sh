gcc -c -o 01-XWindows.o -I /usr/include 01-XWindows.c   
gcc -o 01-XWindows -L /usr/lib/x86_64-linux-gnu  01-XWindows.o -lX11
