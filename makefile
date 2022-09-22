cube: main.o cube.o
	g++ -o cube main.cpp cube.cpp

main.o: main.cpp cube.h
	g++ -c main.cpp

cube.o: cube.cpp cube.h
	g++ -c cube.cpp

clean:
	rm *.o cube recon.txt