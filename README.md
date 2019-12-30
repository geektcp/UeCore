# overview
```
顶级为60的魔兽世界版本是WOW最经典的版本。
让我们重温经典吧。
```

# demo
```
测试游戏环境服务端:
realmd   wow.whyalive.org:3724
mangosd  wow.whyalive.org:8085

客户端下载60 wow， 1.12.3版本即可，修改配置文件realmlist.wtf
SET realmlist wow.whyalive.org
指向上面的服务器地址即可。
测试帐号：test1/123
```

# client
```
魔兽世界经典旧世客户端下载地址
https://pan.baidu.com/s/1BgIYpZEmfTiAmeD_lMB1Sg
```

# describe
```
魔兽世界的服务端虽然没有客户端那么笨重，但是服务端的逻辑是比较复杂的。纯C/C++代码大约50万行。
阅读并维护，二次开发这样一款经典游戏的服务端源码，也是一件非常有趣的事情。

这是一个基于portalclassic，优化部分代码后的二次开发版本。
客户端使用1.12.x版本(60魔兽经典客户端)
```

# feature
```
你在git找到其他魔兽世界服务端项目基本上完全没法使用。
往往clone下来是编译不了的，总会有各种问题。而我这个版本没这问题。
```

# plan
```
考虑构建一个java版本的魔兽服务端
这将是一个极具诱惑力，并且规模巨大的开源项目。
 ```
 # env
env|version
:-:|:-:
os|CentOS 6.5
wow|mangos-classic
gcc|4.9.3
cmake|3.5
boost|1.60
dbc and map|1.12.3
wow client|1.12.3


# install
make -j16用于cpu16核服务器环境，全部编译完要半小时
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
tar -jxvf gcc-4.9.3.tar.bz2
cd gcc-4.9.3
./contrib/download_prerequisites
mkdir build
cd build
../configure --prefix=/usr/local/gcc-4.9.3
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
groupadd wow && useradd wow -g wow &&
chown -R wow.wow -R $BASE_DIR
```

# deploy
preparing
