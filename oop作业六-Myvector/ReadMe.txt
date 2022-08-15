本次实验，直接打开工程文件运行即可
在工程文件的main函数中，我提供了一种测试方式，其运行结果如下：
Test Message:
Create a empty vector, execute  "Vector<int> a;"
Judge if a is empty,execute "a.empty()" :Empty
Get invalid index by calling "a.at(10)" :message Line:16 File:D:\0学业\大二下\oop\作业六\Template\Template.cpp
Insert 1,2,3,4,5,6 one by one :(call a.push_back(int)) :
Test constructor function "Vector<int> b(a);"
a.Size = 6
a.Cap = 8
b.Size = 6
b.Cap = 8
a's elements:
1 2 3 4 5 6
Test and execute function  "a.clear();"
Size = 0
Cap = 0
a's elements:
Judge if a is empty,execute "a.empty()" :Empty
Test and execute function  " Vector <int>c(10);"
Size = 0
Cap = 10
说明：
1、定义"Vector<int> a"，检测缺省构造函数
2、判断此时的a是否为空，为空输出了empty
3、调用a.at(10)，检测异常处理程序，输出Get invalid index by calling "a.at(10)" :message Line:16 File:D:\0学业\大二下\oop\作业六\Template\Template.cpp
4、依次插入1~6，用a初始化b（即运行Vector<int> b(a)），查看a和b之间的信息是否正确，输出：
    a.Size = 6
    a.Cap = 8
    b.Size = 6
    b.Cap = 8
5、遍历a中的元素，输出1 2 3 4 5 6（遍历是用a[i]的方式遍历输出）
6、清空元素，执行a.clear()，查看a的信息：
Size = 0
Cap = 0
遍历a的元素，输出是空
7、判断此时a是否为空，输出empty
8、检测带参数size的构造函数，执行 Vector <int>c(10);查看c的属性：
Size = 0
Cap = 10