本实验实现Fraction，每一个Fraction类型的数字含有分子、分母、flag三个标志
flag为INF和NAN时，分别代表无穷和非数字，为NUMBER时，是普通数字
（1）default ctor：设置缺省构造函数，使得Fraction默认值为0
（2）ctor takes two integers as parameters:构造函数传入两个int是标准构造方式，用法如下：Fraction name(2,3)(表示三分之二)
（3）copy ctor：可以调用copy方法，方式如下：A = B.copy();(其实不如直接用A = B 赋值，更方便，效果都是把B赋值给A)
（4）arithmetical operators: 支持四则运算，当然因为引入了NAN和INF，所以定义了新规则，0/0是NAN，其他除以0是无穷，有NAN参与的运算结果是NAN，
         否则有INF时结果是INF，其他情况输出正常的数字
（5）relational operators:逻辑操作，都是将数字转为double后判断，和两个double数之间的逻辑运算结果相同，包括NAN和INF之间的比较
（6）type cast to double：调用double(name)即可强转double类型
（7）to string：同上，string(name)即可转为string类型
（8）inserter and extractor for streams：输出流控制，负数统一输出为-(int1/int2)的形式，正数是int1/int2，NAN数输出NAN，INF输出INF，
         当然，当分母为1直接输出分子，如11会输出11而不是11/1，当然输入流只支持xx/xx类型的输入，不能直接输入小数
（8）conversion from a finite decimal string like: 1.414：支持定义string类型然后赋值给Fraction，当然格式需要按照xx.xx的形式，或没有小数直接按xx输入

测试方式：在1.txt中输入五个想要测试的数字，格式为 整型/整型，由空格分割，原1.txt中已存入代表数据（5/4 -3/2 0/0 3/0 0/2），可以代表普通数字，NAN数，INF数和0，
	后面的输出提示也是根据原输入来提示的，所以具体的实现需要看main函数中的具体实现，对string的转化，string对该类的直接赋值都是在main函数中定义实现的，可以在main中修改。
	输出结果输出在result.txt中
在这里贴一个原1.txt下的输出：
A:5/4
B:-(3/2)
C:NAN
D:INF
E:0
A+B=-(1/4)
A-B=11/4
A*B=-(15/8)
A/B=-(5/6)
A<B:0
A<=B:0
A==B:0
A!=B:1
A>=B:1
A>B:1
非常规数参与运算A*D:INF
非常规数参与运算A/C:NAN
非常规数输出A/E:INF
强转double(A)1.25
强转字符串string(A)：这是一个5/4字符串
用小数string初始化:25/2			//注：这里的string十进制小数在main函数里
用小数赋值例1:1/8
用小数赋值例2:11
用其他变量赋值：5/4			//注：这里是用A直接赋值
