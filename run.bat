g++ -c *.cpp
g++ *.o -o main -lpdcurses
del *.o
start main
exit