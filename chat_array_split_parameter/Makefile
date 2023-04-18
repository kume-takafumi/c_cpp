sc = /source-charset:utf-8

debug_exe: dt_ _dt
dt : debug_exe

#------------------.
dt_: ./stringsplit.cpp ./stringsplit.h
	cl $(sc) /Fe:"./stringsplit.exe" /Fo:"./stringsplit.obj" /EHsc ./stringsplit.cpp
_dt: ./stringsplit.exe
	./stringsplit.exe
#------------------.

#------------------.
dto: ./stringsplit.cpp ./stringsplit.h
	cl $(sc) /Fo:"./stringsplit.obj" /EHsc /c ./stringsplit.cpp
#------------------.
