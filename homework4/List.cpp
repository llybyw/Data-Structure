#include <iostream>
#include "List.h"

int main()
{
  // 测试默认构造函数和 empty()
  List<int> list;
  std::cout << "列表是否为空？" << std::boolalpha << list.empty() << "\n";

  // 测试 push_front, push_back 和 size()
  list.push_back(10);
  list.push_front(5);
  list.push_back(15);
  std::cout << "push_front 和 push_back 后的大小: " << list.size() << "\n";

  // 测试 front() 和 back()
   std::cout << "前面的元素: " << list.front() << "\n";
  std::cout << "后面的元素: " << list.back() << "\n";

  // 测试 pop_front 和 pop_back
  list.pop_front();
  std::cout << "pop_front 后，前面的元素: " << list.front() << "\n";
  list.pop_back();
  std::cout << "pop_back 后，后面的元素: " << list.back() << "\n";

  // 测试 insert
  auto iter = list.begin();
  list.insert(iter, 20);
  std::cout << "插入 20 到前面后，前面的元素: " << list.front() << "\n";

  // 测试拷贝构造函数
  List<int> copiedList(list);
  std::cout << "复制后的列表前面的元素: " << copiedList.front() << "\n";

  // 测试移动构造函数
  List<int> movedList(std::move(copiedList));
  std::cout << "移动后的列表前面的元素: " << movedList.front() << "\n";
  std::cout << "移动后复制列表的大小: " << copiedList.size() << "\n";  // 应为 0

  // 测试赋值运算符
  List<int> anotherList = list;
  std::cout << "赋值后的列表前面的元素: " << anotherList.front() << "\n";

  // 测试初始化列表构造函数
  List<int> initList = {30, 40, 50};
  std::cout << "初始化列表，前面的元素: " << initList.front() << "\n";
  std::cout << "初始化列表，后面的元素: " << initList.back() << "\n";

  // 测试删除单个元素
  iter = initList.begin();
  ++iter;
  initList.erase(iter);
  std::cout << "删除第二个元素后，前面的元素: " << initList.front() << "\n";
  std::cout << "删除第二个元素后，后面的元素: " << initList.back() << "\n";

  // 测试 clear 和 empty()
  initList.clear();
  std::cout << "清空列表后是否为空？" << std::boolalpha << initList.empty() << "\n";

  // 测试迭代器遍历
  List<int> rangeList = {1, 2, 3, 4, 5};
  std::cout << "rangeList 中的元素: ";
  for (auto it = rangeList.begin(); it != rangeList.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // 测试逆向迭代
  std::cout << "逆向顺序中的元素: ";
  for (auto it = --rangeList.end(); it != --rangeList.begin(); --it)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  return 0;
}
   