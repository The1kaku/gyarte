g++ -c *.cpp
g++ *.o -o main -lpdcurses
rm -f *.o
start main
exit