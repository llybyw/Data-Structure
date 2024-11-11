# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -g -Wall -std=c++2a -O2

# 定义链接选项
LDFLAGS =

# 定义目标文件
TARGET = BST

# 定义源文件
SOURCES = test.cpp

# 定义对象文件
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

report: report.pdf
report.pdf: report.tex
	xelatex report.tex
	xelatex report.tex

# 链接目标
$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

# 编译源文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理编译产生的文件
clean:
	rm -f $(TARGET) $(OBJECTS) report.pdf report.aux report.log report.out

# 伪目标，避免与同名文件冲突
.PHONY: all clean
