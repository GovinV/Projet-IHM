CORE_DIR = ..

BIN_DIR = .#/bin

OBJECT_DIR = .#/objects

SOURCE_DIR = .#/sources

COMPILE = g++ -std=c++11

O_FILES = carte.o joueur.o joueuria.o manche.o partie.o pioche.o types.o

TESTS = test-types test-carte test-pioche test-manche test-joueur test-joueuria test-partie 


main.o: $(SOURCE_DIR)/main.cpp
	$(COMPILE) $< -c -o $(OBJECT_DIR)/$@


%.o: $(CORE_DIR)/%.cpp
	$(COMPILE) $< -c -o $(OBJECT_DIR)/$@


test-%: $(SOURCE_DIR)/test-%.cpp
	$(COMPILE) $< $(OBJECT_DIR)/*.o -o $(BIN_DIR)/$@.out


compil_tests: main.o $(O_FILES) $(TESTS)


tests: compil_tests
	for i in $(TESTS) ; do $(BIN_DIR)/$$i.out ; done


clean:
	rm -f $(OBJECT_DIR)/*.o
	rm `ls ./test-* | grep -v "./*.cpp"`

