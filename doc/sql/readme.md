### 初始化数据
```
这个init目录下，有3份初始化数据
都是mysql关系型数据库，需要创建这个3个库

relase发布版本里面的SQL和这里的一样的。
这个初始化库非常重要。



```

### 注意事项
```
其中realmd库的realmlist表需要一条关键的初始化数据,
其中的xxx.xxx.xxx.xxx就是部署服务的ip地址，这个地方没填，或者填错了，会导致登录不了。
SQL如下：
INSERT INTO `realmlist` VALUES ('1', 'MaNGOS', 'xxx.xxx.xxx.xxx', '8085', '1', '0', '1', '0', '0', '5875 6005 6141 ');
```
