all:
	make Graph.zip

clean:
	rm -f Graph.log
	rm -f Graph.zip
	rm -f TestGraph
	rm -f ./*~

doc: Graph.h
	doxygen Doxyfile

turnin-list:
	turnin --list dlessin cs378pj5

turnin-submit: Graph.zip
	turnin --submit dlessin cs378pj5 Graph.zip

turnin-verify:
	turnin --verify dlessin cs378pj5

Graph.log:
	git log > Graph.log

Graph.zip: Graph.h Graph.log TestGraph.c++ TestGraph.out
	zip -r Graph.zip html/ Graph.h Graph.log TestGraph.c++ TestGraph.out

TestGraph: Graph.h TestGraph.c++
	g++ -pedantic -std=c++0x -Wall -I/public/linux/include/boost-1_44 TestGraph.c++ -o TestGraph -lgtest -lpthread -lgtest_main

TestGraph.out: TestGraph
	valgrind TestGraph > TestGraph.out

test: TestGraph
	TestGraph

testv: TestGraph
	valgrind TestGraph