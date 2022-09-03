

system : *.h *.c
	esterel abro.strl -main ABRO -B abro -D . 

	cc -c abro.c entry_point.c -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated
	cc -o basic_main *.o

cbmc : *.h *.c
	esterel abro.strl -main ABRO -B abro -D . 
	cc -c abro.c entry_point.c  -Wno-c++11-compat-deprecated-writable-strings -Wno-deprecated 
	cbmc -DCBMC abro.c entry_point.c --trace

clean:
	rm *.o abro.c abro.exe simul_sys