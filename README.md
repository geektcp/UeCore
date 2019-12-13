# 概述
```
顶级为60的魔兽世界版本是WOW最经典的版本，当年，那个年头哪个男人没玩过网络游戏。

多年以前，玩游戏时，一直非常期望能够自己控制角色的属性级别，得到各种装备。
多年以后，在这款纯粹的开源服务器问世后，终于如愿以偿。
让我们重温经典吧。
```

# 说明
```
魔兽世界的服务端虽然没有客户端那么笨重，但是服务端的逻辑是比较复杂的。纯C/C++代码大约50万行。
阅读并维护，二次开发这样一款经典游戏的服务端源码，也是一件非常有趣的事情。

这是一个基于portalclassic，优化部分代码后的二次开发版本，提供大量后台的可用性更新，及bug修改，功能定制。
客户端使用1.10版本(60魔兽经典客户端)
```

# 特点
```
你在git找到其他魔兽世界服务端项目基本上完全没法使用。往往克隆下来是编译不了的，总会有各种问题。而我这个版本没这问题。
我这个项目有少量bug，但是基本可用。
```

# 未来规划
```
我希望有一天，开源界能发起一个Java版的魔兽世界服务端，并最终开发出来。如果没有人发起，那么我来吧。
这将是一个极具诱惑力，并且规模巨大的开源项目。
 ```
 # env
```
os					centOS 6.5
wow					mangos-classic
gcc					4.9.3
cmake				3.5
boost				1.60
dbc and map		1.12.3
wow client			1.12.3
```

# install
```
wget --no-check-certificate https://cmake.org/files/v3.5/cmake-3.5.2.tar.gz 
tar -zxvf cmake-3.5.2.tar.gz
cd cmake-3.5.2
./configure --prefix=/usr/local/cmake-3.5.2
make -j16
make install
```
```
yum -y install glibc-devel.i686
tar -jxvf gcc-4.8.2.tar.bz2
cd gcc-4.8.2
./contrib/download_prerequisites
mkdir build
cd build
../configure --prefix=/usr/local/gcc-4.8.2
make -j16
make install
```
```
wget http://netcologne.dl.sourceforge.net/project/boost/boost/1.60.0/boost_1_60_0.tar.bz2
tar -jxvf boost_1_60_0.tar.bz2
cd boost_1_60_0
./bootstrap.sh
./b2
./b2 install
```

```
cd /usr/local/src/wow/
git clone https://github.com/geektcp/elf-wow.git

export LD_LIBRARY_PATH=/usr/local/gcc-4.9.3/lib64/
export BASE_DIR=/usr/local/wow_mangos_bot_2017.10.2
mkdir -p /usr/local/src/wow/ClassicWOW/build/  &&
rm -rf /usr/local/src/wow/ClassicWOW/build/*  &&
cd /usr/local/src/wow/ClassicWOW/build &&
/usr/local/cmake-3.5.2/bin/cmake ../ \
-DCMAKE_INSTALL_PREFIX=$BASE_DIR  \
-DCONF_DIR=$BASE_DIR/etc \
-DPCH=1 \
-DDEBUG=0 \
-DCMAKE_C_COMPILER=/usr/local/gcc-4.9.3/bin/gcc \
-DCMAKE_CXX_COMPILER=/usr/local/gcc-4.9.3/bin/g++ &&
time make -j16 &&
make install &&
chown -R wow.wow -R $BASE_DIR
```
