lSOURCES=$(wildcard *.cxx)
sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=maze.exe
LIB=maze.a

all: $(TARGET) $(LIB)
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@
clean:
	rm *.o *.exe 
explain:
	@echo "Lib Sources: $(lSOURCES)"
	@echo "User Sources: $(sSOURCES)"
	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
