CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = rpn_calc
SOURCES = main.cpp rpn_calc.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run