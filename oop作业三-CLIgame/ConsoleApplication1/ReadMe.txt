游戏说明:
本游戏有四种模式，分别是easy，normal，hard，selfdefine
这四种模式的区别在于地图大小和怪物的数量
easy： 3x3大小的九宫格，但有概率会随机关闭一些房间，有2只怪物
normal： 6x6大小的36宫格，但有概率会随机关闭一些房间，有10只怪物
easy： 10x10大小的100宫格，但有概率会随机关闭一些房间，有30只怪物
selfdeine：nxn大小的九宫格，其中n是自己输入的介于[3，50]的整数，并回根据n的值提示玩家输入合理区间范围内的怪物数，如当n为50时，提示玩家输入不大于277只怪物
本程序利用BFS算法保证生成的地图一定存在可行解（即不会在骑士救公主、公主通往出口的唯一路径上存在怪物，保证骑士、公主、出口在躲避怪物的条件下连通）
游戏步骤与规则说明：
1.进入游戏，玩家根据提示输入自己的姓名后，会选择游戏模式，输入1代表easy，依次类推至4（代表selfdefine）
2.游戏开始，玩家根据房间出口信息，输入 go xxx 命令，控制骑士移动
3.房间中随机散落着游戏道具——radar和map，radar可以显示最近的怪物和你的距离以及大致方位，map在找到公主前显示公主和你的距离以及大致方位，找到公主后提示出口方位与距离
4.在执行go xxx命令后，骑士抵达新房间，如果骑士可以继续游戏（即未碰到怪物），则会捡起房间中的道具，每次抵达新房间后都可以选择是否使用道具（用y/n代表是与否）
5.游戏分为两个大阶段，阶段一，找到公主，阶段二，带领公主找到出口，并在每一次移动后，显示当前位置周围的怪物数（周围指以骑士为中心的3x3九宫格）
一个可能的游戏进程：
Please Input your name
hahh						（玩家输入姓名）
Please Select game difference:
[1] easy
[2] normal
[3] hard
[4] self define map's size
1						（玩家选择难度）
Game start:
Map is generating, please wait a moment
You are a knight, your task is to rescue the princess in the castle
with many monsters, you will see two props: radar and map in
the room, radar can help you avoid monsters, map can help you
find the princess and exit, Come on, and good luck.
Welcome To Living room, There are 2 exits: east and south.	（游戏独白与介绍）
Evil does not prevail, always				（每回合的游戏画外音与剧情)
Enter your command: go east				  (玩家输入移动命令 go east)
Wow, Look! a map is here, maybe can help me find princess and exit	（捡拾道具提示）
hahh knight, you have 0 radars and 1 maps		（玩家道具情况）
Use tools? [y]/[n]
n						（玩家输入n表示不选择使用道具）
1 monsters are near you, be careful			（玩家四周怪物提示）
Welcome To Living room, There are 3 exits: west, east and south.（新房间介绍）
Forward forward!!					（每回合的游戏画外音与剧情)
Enter your command: go east			 	 （玩家输入移动命令 go east)
Look! monster is here			 	 （遇到怪物提示)
you failed!