CORE_DIR = ../core

BIN_DIR = ./bin

OBJECT_DIR = ./objects

SOURCE_DIR = ./sources

COMPILE = g++ -std=c++11

TESTS = test-carte #test-joueur test-joueuria test-manche test-partie test-pioche test-types


main.o: $(SOURCE_DIR)/main.cpp
	$(COMPILE) $^ -c -o $(OBJECT_DIR)/$@

tests: $(TESTS) run_test

test-%: $(SOURCE_DIR)/test-%.cpp main.o %.o
	$(COMPILE) $^ -o $(SOURCE_DIR)/$@

%.o: $(CORE_DIR)/%.cpp
	$(COMPILE) $< -c -o $(OBJECT_DIR)/$@

run_test:
	for i in $(TESTS) ; do $(SOURCE_DIR)/$$i ; done

clean:
	rm -f *.o
	rm -f $(TESTS)

