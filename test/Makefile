# 定义编译器
CXX = g++

# 定义编译选项
CXXFLAGS = -Wall -std=c++2a -O2

src = $(wildcard ./*.cpp) # 匹配当前工作目录下的所有.c 文件。将文件名组成列表，赋值给变量 src 

obj = $(patsubst %.cpp, %.o, $(src)) 

ALL : test.out

$(obj) : %.o : %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)


test.out : $(obj)
	
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean :
	-rm -rf $(obj) a.out

.PHONY : clean ALL
