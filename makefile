main: main.o player.o propertycard.o normalproperty.o utilities.o rr.o board.o specialbox.o dice.o communitychest.o chance.o
	g++ main.o player.o propertycard.o normalproperty.o utilities.o rr.o board.o specialbox.o dice.o communitychest.o chance.o -o main -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: player.h propertycard.h normalproperty.h utilities.h rr.h board.h specialbox.h dice.h communitychest.h chance.h main.cpp
	g++ -c main.cpp -I./SFML/include

player.o: player.h player.cpp
	g++ -c player.cpp -I./SFML/include

propertycard.o: propertycard.h propertycard.cpp
	g++ -c propertycard.cpp -I./SFML/include

normalproperty.o: propertycard.h normalproperty.h normalproperty.cpp
	g++ -c normalproperty.cpp -I./SFML/include

utilities.o: propertycard.h utilities.h utilities.cpp
	g++ -c utilities.cpp -I./SFML/include

rr.o: propertycard.h rr.h rr.cpp
	g++ -c rr.cpp -I./SFML/include

board.o: propertycard.h normalproperty.h utilities.h rr.h specialbox.h board.h communitychest.h chance.h board.cpp
	g++ -c board.cpp -I./SFML/include

specialbox.o: specialbox.h specialbox.cpp
	g++ -c specialbox.cpp -I./SFML/include

dice.o: dice.h dice.cpp
	g++ -c dice.cpp -I./SFML/include

communitychest.o: communitychest.h communitychest.cpp
	g++ -c communitychest.cpp -I./SFML/include

chance.o: chance.h chance.cpp
	g++ -c chance.cpp -I./SFML/include

clean:
	rm *.o
	
cleanall:
	rm *.o main