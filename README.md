everwar开源魔兽世界
==============================
> 魔兽世界是世界上最成功的游戏，这是一套完整的服务端源码版本。
2023年6月，官网已经正式发布。欢迎点赞收藏。

![登录入口](https://github.com/geektcp/everwar/blob/master/screen/8.jpg)

# website
<a href="http://everwar.cn" target="_blank">Everwar 开源魔兽世界官网</a>
<br/>

# overview

```
顶级为60的魔兽世界版本是WOW最经典的版本,让我们重温经典吧。
觉得有用就赞一个，欢迎fork
https://github.com/geektcp/everwar.git

任何技术问题直接在issue提问。直接把问题和期望写清楚)，每周定期回复

技术qq群： 153459822
```

```
感谢各位的star，支持和关注，接下来这个项目也会进行持续的更新，大家可以留意动态。
2023年会发布一个新版本，基于CentOS7.x的版本，并部署到公网，到时候方便大家直接使用。
--------------

2023年9月20，基于CentOS7.x的新版本1.1已经内测通过，2023年9月16日上线。
```

# version
<a href="https://everwar.cn/deploy/everwar_1_1" target="_blank">Everwar-1.1版本发布</a>

- 公测帐号:
```
test1
test2
test3
...

test20
```

- 公测密码
```
123
```

# feature
```
在github找到其他魔兽世界服务端项目基本上完全没法使用。
往往clone下来是编译不了的，总会有各种问题。而这个git项目工程没这问题。

本项目支持机器人，自己可以创建玩家组队进行游戏。
```

# history
```
从2016年底开始计划，2017年初正式启动。
这个项目持续了漫长的时间，期间几乎没有收到任何开源界的正面反馈和支持。
沉寂了很久坚持到现在，是因为兴趣和源自魔兽世界游戏设计本身的魅力。

魔兽世界作为一款宏大而精良的角色扮演游戏，经历全球互联网用户的对网络世界的憧憬、探索、成熟等多个阶段。

真正的角色扮演游戏游戏的本质是什么？
是很多人通过现代化的网络技术方式，以非正式的，娱乐式的形式进行角色扮演，一起经历一些虚拟的互动，
过程中，每个人都能获得良好而精彩的娱乐体验。

希望你不要太当真，这只是一场游戏。

本项目聚焦经典旧世版本，未来还将持续下去。

```

# branch
```
目前有3个分支：
master: 
主分支，默认是最新可用版本。
编译构建可用。
目前是基于CentOS6.5的可用版本，后续会更新到基于CentOS7.9的版本。


branch.CentOS7.9：
接下来开发一个基于CentOS7.9的版本就在这个分支上进行。
事实上，基于本项目现有的文档资料，仅仅只是操作系统的变化，用户依然可以自行编译部署成功。

branch.CentOS6.5：
存档分支，
这个分支的代码是基于CentOS6.5的完整的可用的分支版本，
编译构建可用。
永久固定是基于CentOS6.5的版本。
```

# client
```
魔兽世界经典旧世客户端下载地址:
https://pan.baidu.com/s/1BgIYpZEmfTiAmeD_lMB1Sg
```

# os
```
CentOS 6.5 下载地址：
https://vault.centos.org/6.5/isos/x86_64/

CentOS 7.9 下载地址：
https://ftp.riken.jp/Linux/centos/7.9.2009/isos/x86_64/

完整的二进制安装包下载地址(仅支持CentOS 6.5)：
https://github.com/geektcp/everwar/releases/tag/1.0

完整的二进制安装包下载地址(支持CentOS 7.9)：
待发布
```

# describe
```
魔兽世界的服务端虽然没有客户端那么笨重，但是服务端的逻辑是比较复杂的。纯C/C++代码大约50万行。
阅读并维护，二次开发这样一款经典游戏的服务端源码，也是一件非常有趣的事情。

这是一个基于portalclassic，优化部分代码后的二次开发版本。
客户端使用1.12.x版本(60魔兽经典客户端)
```

- 界面截图
![登录入口](https://github.com/geektcp/everwar/blob/master/screen/login.png)

