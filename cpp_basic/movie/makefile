ahahahha :ahahahha.o menu.o administrator.o reception.o MovieLinkList.o str.o
ahahahha.o :ahahahha.c
	cc -c -o ahahahha.o ahahahha.c 
menu.o :menu.h  
# menu.h :employee.h
administrator.o: administrator.h 
# administrator.h :MovieLinkList.h employee.h
reception.o: str.o reception.h 

# reception.h:MovieLinkList.h
MovieLinkList.o :  MovieLinkList.h 

str.o: str.h
.PHONY:clean
clean:
	 -rm -f  *.o
