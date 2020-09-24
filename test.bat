g++ *.cpp -c -lpdcurses -std=c++17
g++ *.o -o main -lpdcurses -std=c++17
rm -f *.o
