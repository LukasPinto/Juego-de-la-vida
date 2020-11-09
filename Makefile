#Compila el programa principal

gameOfLife: src/main.o src/funciones.o 
	g++ -o gameOfLife src/main.o src/funciones.o 

main.o: src/main.cpp 
	g++ -c -Iinclude src/main.cpp -o src/main.cpp

funciones.o: funciones.cpp
	g++ -c src/funciones.cpp
#limpia el programa
clean:
	rm -f gameOfLife src/*.o 