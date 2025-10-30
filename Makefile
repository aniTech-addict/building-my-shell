
CXX = g++
CXXFLAGS = -Wall -std=c++17

# final executable filename
TARGET = shell

# files to compile
SRCS = main.cpp parser.cpp

 # object files
OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)

# link all the object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
