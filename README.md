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
在git找到其他魔兽世界服务端项目基本上完全没法使用。
往往clone下来是编译不了的，总会有各种问题。而这个版本没这问题。
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
Linux_wow1.12私服搭建

一、背景
60魔兽是最经典的版本，遗憾的是60年代时还在大学读书，穷得很，买不起点卡，后来工作了，大概70年代开始玩的。

多年以前，玩游戏时，一直非常期望能够自己控制角色的属性级别，得到各种装备。

多年以后，在这款纯粹的开源服务器问世后，终于如愿以偿。

让我们重温经典吧。


二、部署服务器端
项目源码： https://github.com/geektcp/elf-wow

觉得有用就赞一个


一、背景
60魔兽是最经典的版本，遗憾的是60年代时还在大学读书，穷得很，买不起点卡，后来工作了，大概70年代开始玩的。

多年以前，玩游戏时，一直非常期望能够自己控制角色的属性级别，得到各种装备。

多年以后，在这款纯粹的开源服务器问世后，终于如愿以偿。

让我们重温经典吧。

 

 

二、部署服务器端
```
Linux_wow1.12私服搭建

一、背景
60魔兽是最经典的版本，遗憾的是60年代时还在大学读书，穷得很，买不起点卡，后来工作了，大概70年代开始玩的。

多年以前，玩游戏时，一直非常期望能够自己控制角色的属性级别，得到各种装备。

多年以后，在这款纯粹的开源服务器问世后，终于如愿以偿。

让我们重温经典吧。


二、部署服务器端
1、版本要求
编译服务端有版本要求：
os					centOS 6.5
wow					mangos-classic
gcc					4.9.3
cmake				3.5
boost				1.60
dbc and map		1.12.3
wow client			1.12.3

2、升级cmake
wget --no-check-certificate \
https://cmake.org/files/v3.5/cmake-3.5.2.tar.gz 

tar -zxvf cmake-3.5.2.tar.gz
cd cmake-3.5.2
./configure --prefix=/usr/local/cmake-3.5.2
make -j16
make install

3、升级GCC
yum -y install glibc-devel.i686
tar -jxvf gcc-4.8.2.tar.bz2
cd gcc-4.8.2
./contrib/download_prerequisites
mkdir build
cd build
../configure --prefix=/usr/local/gcc-4.8.2
make -j16
make install

4、安装boost
在centos6.5上用yum安装的boost版本太低，必须重新编译安装。
最好直接安装在默认路径。
wget http://netcologne.dl.sourceforge.net/project/boost/boost/1.60.0/boost_1_60_0.tar.bz2
tar -jxvf boost_1_60_0.tar.bz2
cd boost_1_60_0
./bootstrap.sh
./b2
./b2 install

5、编译安装
先下载源码：
cd /usr/local/src/wow/
git clone https://github.com/geektcp/elf-wow.git

然后开始编译并安装(必须要指定环境变量LD_LIBRARY_PATH为新版本g++的库)：
export LD_LIBRARY_PATH=/usr/local/gcc-4.9.3/lib64/
export BASE_DIR=/usr/local/wow_mangos_bot_2017.10.2
mkdir -p /usr/local/src/wow/elf-wow/build/  &&
rm -rf /usr/local/src/wow/elf-wow/build/*  &&
cd /usr/local/src/wow/elf-wow/build &&
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


6、地图文件生成
map文件包括maps,mmaps,vmaps,dbc四个部分。，每个文件夹下面有大量地图文件。

这些地图文件是从哪里来的呢？
是从客户端的安装文件里面的抽取出来的。

抽取方式，先从服务器端的源码里面找到如下目录：
ls /usr/local/src/wow/elf-wow/contrib/extractor_binary
ad.exe
ExtractResources.sh
MoveMapGen.exe
MoveMapGen.sh
offmesh.txt
README.txt
vmap_assembler.exe
vmapExtractor.exe
注意上面这几个exe文件，只有我用的这个版本才有，最新的cmangos-classic没有对应的可执行文件，而这几个可执行文件是用来生成map文件的，而服务器端启动时必须依赖map文件。
网上找到的下载1.12版本的map文件很难找到，没有下载地址，有也是无效的链接，或者下载下来不能用的。

将上米娜的exe文件都拷贝windows环境的wow客户端下，跟wow.exe同一级目录
然后依次直接按如下步骤运行：
1、生成dbc和maps文件
ad.exe

2、创建vmaps空文件夹并生成文件
md vmaps
vmap_assembler.exe Buildings vmaps

3、创建mmpas文件夹并生成文件，这一步可能要很久，一两个小时。
md mmaps
MoveMapGen.exe


最后，如过不想一步一步完成，可以使用批处理(写入到generateMap.bat文件中)：
ad.exe
md vmaps
vmap_assembler.exe Buildings vmaps
md mmaps
MoveMapGen.exe


7、数据库初始化
wow mangos classic经典版本的数据库数据来源于：
/usr/local/src/wow/mangos-classic/sql

另一部分存在于源码目录下：
git clone git://github.com/cmangos/classic-db.git

创建数据库账号：
grant all on *.* to mangos@'%' IDENTIFIED by 'mangos';

创建wow数据库：
CREATE DATABASE `mangos` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;

CREATE DATABASE `characters` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;

CREATE DATABASE `realmd` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;


然后进入源码目录下的sql目录：
导入对应的sql到对应的数据库：
ls /usr/local/src/wow/mangos-classic/sql/base
characters.sql  mangos.sql  realmd.sql



8、配置文件
mangosd.conf的关键配置项如下：
# 监听端口
WorldServerPort = 8085

# 监听网卡IP
BindIP = "0.0.0.0"

# 是否启用控制台
Console.Enable = 0

# 日志级别
LogLevel = 1

另外还有数据库连接方式的参数：
LoginDatabaseInfo     = "10.10.10.10;3310;mangos;mangos;realmd"
WorldDatabaseInfo     = "10.10.10.10;3310;mangos;mangos;mangos"
CharacterDatabaseInfo = "10.10.10.10;3310;mangos;mangos;characters"



标准可用的配置文件如下：
cat /usr/local/wow_mangos/etc/mangosd.conf |grep -v ^# |grep -v ^$  
[MangosdConf]
ConfVersion=2015090801
RealmID = 1
DataDir = "/usr/local/wow_mangos/data/"
LogsDir = "/usr/local/wow_mangos/logs/"
LoginDatabaseInfo     = "10.10.10.10;3310;mangos;mangos;realmd"
WorldDatabaseInfo     = "10.10.10.10;3310;mangos;mangos;mangos"
CharacterDatabaseInfo = "10.10.10.10;3310;mangos;mangos;characters"
LoginDatabaseConnections = 1
WorldDatabaseConnections = 1
CharacterDatabaseConnections = 1
MaxPingTime = 30
WorldServerPort = 8085
BindIP = "0.0.0.0"
SD2ErrorLogFile = "SD2Errors.log"
UseProcessors = 0
ProcessPriority = 1
Compression = 1
PlayerLimit = 100
SaveRespawnTimeImmediately = 1
MaxOverspeedPings = 2
GridUnload = 1
LoadAllGridsOnMaps = ""
GridCleanUpDelay = 300000
MapUpdateInterval = 100
ChangeWeatherInterval = 600000
PlayerSave.Interval = 900000
PlayerSave.Stats.MinLevel = 0
PlayerSave.Stats.SaveOnlyOnLogout = 1
vmap.enableLOS = 1
vmap.enableHeight = 1
vmap.ignoreSpellIds = "7720"
vmap.enableIndoorCheck = 1
DetectPosCollision = 1
TargetPosRecalculateRange = 1.5
mmap.enabled = 1
mmap.ignoreMapIds = ""
UpdateUptimeInterval = 10
MaxCoreStuckTime = 0
AddonChannel = 1
CleanCharacterDB = 1
LogSQL = 1
PidFile = ""
LogLevel = 1
LogTime = 0
LogFile = "Server.log"
LogTimestamp = 0
LogFileLevel = 0
LogFilter_TransportMoves = 1
LogFilter_CreatureMoves = 1
LogFilter_VisibilityChanges = 1
LogFilter_Weather = 1
LogFilter_DbStrictedCheck = 1
LogFilter_Pathfinding = 1
LogFilter_MapsLoading = 1
LogFilter_EventAiDev = 1
LogFilter_PeriodicAffects = 0
LogFilter_PlayerMoves = 1
LogFilter_SQLText = 1
LogFilter_AIAndMovegens = 0
LogFilter_PlayerStats = 0
LogFilter_Damage = 0
LogFilter_Combat = 0
LogFilter_SpellCast = 0
WorldLogFile = ""
WorldLogTimestamp = 0
DBErrorLogFile = "DBErrors.log"
EventAIErrorLogFile = "EventAIErrors.log"
CharLogFile = "Char.log"
CharLogTimestamp = 0
CharLogDump = 0
GmLogFile = ""
GmLogTimestamp = 0
GmLogPerAccount = 0
RaLogFile = ""
LogColors = ""
GameType = 1
RealmZone = 1
DBC.Locale = 255
DeclinedNames = 0
StrictPlayerNames = 0
StrictCharterNames = 0
StrictPetNames = 0
MinPlayerName = 2
MinCharterName = 2
MinPetName = 2
CharactersCreatingDisabled = 0
CharactersPerAccount = 50
CharactersPerRealm = 10
SkipCinematics = 0
MaxPlayerLevel = 60
StartPlayerLevel = 1
StartPlayerMoney = 0
MaxHonorPoints = 75000
StartHonorPoints = 0
MinHonorKills = 15
MaintenanceDay = 3
InstantLogout = 1
AllFlightPaths = 0
AlwaysMaxSkillForLevel = 0
ActivateWeather = 1
CastUnstuck = 1
MaxSpellCastsInChain = 20
RabbitDay = 0
Instance.IgnoreLevel = 0
Instance.IgnoreRaid = 0
Instance.ResetTimeHour = 4
Instance.UnloadDelay = 1800000
Quests.LowLevelHideDiff = 4
Quests.HighLevelHideDiff = 7
Quests.IgnoreRaid = 0
Guild.EventLogRecordsCount = 100
TimerBar.Fatigue.GMLevel = 4
TimerBar.Fatigue.Max = 60
TimerBar.Breath.GMLevel = 4
TimerBar.Breath.Max = 60
TimerBar.Fire.GMLevel = 4
TimerBar.Fire.Max = 1
MaxPrimaryTradeSkill = 2
TradeSkill.GMIgnore.MaxPrimarySkillsCount = 4
TradeSkill.GMIgnore.Level = 4
TradeSkill.GMIgnore.Skill = 4
MinPetitionSigns = 9
MaxGroupXPDistance = 74
MailDeliveryDelay = 3600
MassMailer.SendPerTick = 10
PetUnsummonAtMount = 0
Event.Announce = 0
BeepAtStart = 1
ShowProgressBars = 0
WaitAtStartupError = 0
Motd = "Welcome to the Continued Massive Network Game Object Server."
PlayerCommands = 1
AllowTwoSide.Accounts = 0
AllowTwoSide.Interaction.Chat = 0
AllowTwoSide.Interaction.Channel = 0
AllowTwoSide.Interaction.Group = 0
AllowTwoSide.Interaction.Guild = 0
AllowTwoSide.Interaction.Trade = 0
AllowTwoSide.Interaction.Auction = 0
AllowTwoSide.Interaction.Mail = 0
AllowTwoSide.WhoList = 0
AllowTwoSide.AddFriend = 0
TalentsInspecting = 1
ThreatRadius = 100
Rate.Creature.Aggro = 1
CreatureRespawnAggroDelay = 5000
CreatureFamilyFleeAssistanceRadius = 30
CreatureFamilyAssistanceRadius = 10
CreatureFamilyAssistanceDelay = 1500
CreatureFamilyFleeDelay = 7000
WorldBossLevelDiff = 3
Corpse.EmptyLootShow = 1
Corpse.Decay.NORMAL = 300
Corpse.Decay.RARE = 900
Corpse.Decay.ELITE = 600
Corpse.Decay.RAREELITE = 1200
Corpse.Decay.WORLDBOSS = 3600
Rate.Corpse.Decay.Looted = 0.0
Rate.Creature.Normal.Damage = 1
Rate.Creature.Elite.Elite.Damage = 1
Rate.Creature.Elite.RAREELITE.Damage = 1
Rate.Creature.Elite.WORLDBOSS.Damage = 1
Rate.Creature.Elite.RARE.Damage = 1
Rate.Creature.Normal.SpellDamage = 1
Rate.Creature.Elite.Elite.SpellDamage = 1
Rate.Creature.Elite.RAREELITE.SpellDamage = 1
Rate.Creature.Elite.WORLDBOSS.SpellDamage = 1
Rate.Creature.Elite.RARE.SpellDamage = 1
Rate.Creature.Normal.HP = 1
Rate.Creature.Elite.Elite.HP = 1
Rate.Creature.Elite.RAREELITE.HP = 1
Rate.Creature.Elite.WORLDBOSS.HP = 1
Rate.Creature.Elite.RARE.HP = 1
ListenRange.Say = 40
ListenRange.TextEmote = 40
ListenRange.Yell = 300
GuidReserveSize.Creature = 100
GuidReserveSize.GameObject = 100
ChatFakeMessagePreventing = 0
ChatStrictLinkChecking.Severity = 0
ChatStrictLinkChecking.Kick = 0
ChatFlood.MessageCount = 10
ChatFlood.MessageDelay = 1
ChatFlood.MuteTime = 10
Channel.SilentlyGMJoin = 0
GM.LoginState            = 2
GM.Visible               = 2
GM.AcceptTickets         = 2
GM.Chat                  = 2
GM.WhisperingTo          = 2
GM.InGMList.Level        = 3
GM.InWhoList.Level       = 3
GM.LogTrade              = 1
GM.StartLevel            = 1
GM.LowerSecurity         = 0
GM.InvisibleAura         = 31748
Visibility.GroupMode = 0
Visibility.Distance.Continents    = 90
Visibility.Distance.Instances     = 120
Visibility.Distance.BG            = 180
Visibility.Distance.InFlight      = 100
Visibility.Distance.Grey.Unit   = 1
Visibility.Distance.Grey.Object = 10
Visibility.RelocationLowerLimit    = 10
Visibility.AIRelocationNotifyDelay = 1000
Rate.Health = 1
Rate.Mana = 1
Rate.Rage.Income = 1
Rate.Rage.Loss = 1
Rate.Focus = 1
Rate.Loyalty = 1
Rate.Energy = 1
Rate.Skill.Discovery = 1
Rate.Drop.Item.Poor = 1
Rate.Drop.Item.Normal = 1
Rate.Drop.Item.Uncommon = 1
Rate.Drop.Item.Rare = 1
Rate.Drop.Item.Epic = 1
Rate.Drop.Item.Legendary = 1
Rate.Drop.Item.Artifact = 1
Rate.Drop.Item.Referenced = 1
Rate.Drop.Money = 1
Rate.XP.Kill    = 1
Rate.XP.Quest   = 1
Rate.XP.Explore = 1
Rate.Rest.InGame = 1
Rate.Rest.Offline.InTavernOrCity = 1
Rate.Rest.Offline.InWilderness = 1
Rate.Damage.Fall = 1
Rate.Auction.Time = 1
Rate.Auction.Deposit = 1
Rate.Auction.Cut = 1
Auction.Deposit.Min = 0
Rate.Honor = 1
Rate.Mining.Amount = 1
Rate.Mining.Next   = 1
Rate.Talent = 1
Rate.Reputation.Gain = 1
Rate.Reputation.LowLevel.Kill    = 0.2
Rate.Reputation.LowLevel.Quest   = 1
Rate.InstanceResetTime = 1
SkillGain.Crafting = 1
SkillGain.Defense = 1
SkillGain.Gathering = 1
SkillGain.Weapon = 1
SkillChance.Orange = 100
SkillChance.Yellow = 75
SkillChance.Green  = 25
SkillChance.Grey   = 0
SkillChance.MiningSteps   = 0
SkillChance.SkinningSteps = 0
SkillFail.Loot.Fishing = 0
SkillFail.Gain.Fishing = 0
SkillFail.Possible.FishingPool = 1
DurabilityLossChance.Damage = 0.5
DurabilityLossChance.Absorb = 0.5
DurabilityLossChance.Parry  = 0.05
DurabilityLossChance.Block  = 0.05
Death.SicknessLevel = 11
Death.CorpseReclaimDelay.PvP = 1
Death.CorpseReclaimDelay.PvE = 1
Death.Bones.World = 1
Death.Bones.Battleground = 1
Death.Ghost.RunSpeed.World = 1.0
Death.Ghost.RunSpeed.Battleground = 1.0
Battleground.CastDeserter = 1
Battleground.QueueAnnouncer.Join = 0
Battleground.QueueAnnouncer.Start = 0
Battleground.ScoreStatistics = 0
Battleground.InvitationType = 0
BattleGround.PrematureFinishTimer = 300000
BattleGround.PremadeGroupWaitForMatch = 0
OutdoorPvp.SIEnabled = 1
OutdoorPvp.EPEnabled = 1
Network.Threads = 1
Network.OutKBuff = -1
Network.OutUBuff = 65536
Network.TcpNodelay = 1
Network.KickOnBadPacket = 0
Console.Enable = 0
Ra.Enable = 0
Ra.IP = 0.0.0.0
Ra.Port = 3443
Ra.MinLevel = 3
Ra.Secure = 1
Ra.Stricted = 1
SOAP.Enabled = 0
SOAP.IP = 10.10.10.10
SOAP.Port = 7878
CharDelete.Method = 0
CharDelete.MinLevel = 0
CharDelete.KeepDays = 30


cat /usr/local/wow_mangos/etc/realmd.conf |grep -v ^# |grep -v ^$  
[RealmdConf]
ConfVersion=2010062001
LoginDatabaseInfo = "10.10.10.10;3310;mangos;mangos;realmd"
LogsDir = ""
MaxPingTime = 30
RealmServerPort = 3724
BindIP = "0.0.0.0"
PidFile = ""
LogLevel = 0
LogTime = 0
LogFile = "Realmd.log"
LogTimestamp = 0
LogFileLevel = 0
LogColors = ""
UseProcessors = 0
ProcessPriority = 1
WaitAtStartupError = 0
RealmsStateUpdateDelay = 20
WrongPass.MaxCount = 0
WrongPass.BanTime = 600
WrongPass.BanType = 0



9、启动服务器
cat /usr/local/wow_mangos/bin/startup.sh
启动脚本内容如下：
#!/bin/sh
# usage : sh shutdown.sh
# author : nagle
# date   : Sat Jan 21 16:10:11 CST 2017
# website:  https://github.com/geektcp

base_dir=`dirname $0`/..
cd $base_dir/bin/
export LD_LIBRARY_PATH=/usr/local/gcc-4.9.3/lib64/:$base_dir/lib
nohup $base_dir/bin/realmd 2>&1 >> $base_dir/logs/nohup_realmd.out &
$base_dir/bin/mangosd

cat /usr/local/wow_mangos/bin/shutdown.sh
关闭脚本内容：
#!/bin/sh
# usage : sh shutdown.sh
# author : nagle
# date   : Sat Jan 21 16:10:11 CST 2017
# website: https://github.com/geektcp

ps -ef |grep wow_mangos |grep wow|grep -v grep |grep -v local|awk '{print $2}' |xargs -t -i kill -9 {}



alais环境变量：
vim ~/.bash_profile
alias startmangos='screen -S thy -X screen su - wow -c /usr/local/wow_mangos/bin/startup.sh'

alias stopmanos='screen -S thy -X screen su - wow -c /usr/local/wow_mangos/bin/shutdown.sh'




10、创建账号
如果启动mangosd服务端时，配置文件指定了启用控制台，那么可以在控制台输入命令：
account create nagle 123

即可创建一个帐号为nagle，密码为123的帐号了。


另外通过数据库也可以创建账号,对应的sql语句是：
SET
@username = "test1",
@password = "123",
@email = "test@163.com",
@expansion = 0,  -- 0表示经典旧时， 1表示70年代，一次类推
@gmlevel = 0,   -- 0 = player, 1=GM, 2=Moderator, 3=Admin, 4=Console
@realmid = 1;

INSERT INTO account 
(username, sha_pass_hash, gmlevel, email, expansion, active_realm_id)
VALUES (
UPPER(@username), 
(SHA1(CONCAT(UPPER(@username), 
':', UPPER (@password))) ), 
@gmlevel, 
@email, 
@expansion,
@realmid
);

INSERT INTO `realmd`.`realmcharacters` (`realmid`, `acctid`) VALUES ('1', '5');

11、客户端连接
找到wow.exe同一级目录下的配置文件，没有用记事本新建一个，重命名为realmlist.wtf
写入内容(其中如果不是默认端口3724，可以在后面添加端口，比如:13724)：
SET realmlist 43.247.69.127:13724


三、扩展功能
后续打算抽时间弄个机器人版本，以经典旧时的客户端和服务器作为研究对象，来深入二次开发。

待续。


常用配置项
开启所有飞行点
AllFlightPaths=1



机器人用法
对应的机器人命令：
vim /usr/local/src/wow/portalclassic/doc/playerbot/commands.txt

查看机器人状态：
/t 夜之眼 stats

/t 夜之眼 info

召唤机器人：
.bot add 夜之眼
.bot add 索拉查的笛声


保持位置不动：
/t 夜之眼 stay
/t 索拉查的笛声 stay
/t 夜之眼 cast 1243

.bot remove 索拉查的笛声

.bot add 小牛
.bot add 塞拉摩
.bot add 爱在西元前
/t 爱在西元前 orders combat heal
/t 塞拉摩 orders combat protect 
/t 小牛 orders combat resistfire
/t 小牛 orders combat assist


.bot remove 夜之眼
.bot remove 索拉查的笛声

/t 夜之眼 orders combat heal
/t 夜之眼 help
/t 夜之眼 follow near
/t 夜之眼 follow far
/t 索拉查的笛声 follow near
/t 索拉查的笛声 follow near
/t 索拉查的笛声 follow info


/t 爱在西元前 orders combat attack
.bot remove  爱在西元前
.bot remove 塞拉摩

常用GM命令
21级血杀斧：
.additem 13016

盾牌24级：
.additem 12997
.additem 13032

学会所有法术：
.learn all



传送
传送门
添加传送门(如果对应的id不存在，或者填错了，就会增加一个空的物体)：
.gobject add [entry]

删除传送门：
.gobject delete [guid]

entry是物体模板id，可以按同一个模块添加多个同样的物体，
所以删除时必须删除物体id

添加物体后，控制台界面(聊天窗口)会返回GUID信息，这个GUID就是物体的id，根据这个id删除物体即可。

传送门entry对应 表是gameobject_template
传送门guid对应的表是gameobject

查看guid和entry对应关系：
SELECT t.entry,t.name,o.id, o.guid,
o.position_x,o.position_y,o.position_z,o.map
FROM gameobject o,gameobject_template t 
WHERE o.id=[entry] 

比如：
SELECT t.entry,t.name,o.id, o.guid,
o.position_x,o.position_y,o.position_z,o.map
FROM gameobject o,gameobject_template t 
WHERE o.id =176499


序号	添加物体	命令	备注
0	删除传送门	.gobject delete 90007	　
1	奥格瑞玛传送门	.gobject add 176499	　
2	暴风传送门	.gobject add 176296	　
3	铁炉堡传送门	.gobject add 176497	　
4	达纳苏斯传送门	.gobject add 176498	　
5	奥格玛传送门	.gobject add 176499 	　
6	雷霆崖传送门	.gobject add 176500	　
7	幽暗城传送门	.gobject add 176501	　
8	末日传送门	.gobject add 177193	　
9	半人马传送门01	.gobject add 178386	　
10	集合石传送门	.gobject add 179944	　
11	卡拉赞传送门	.gobject add 181146	　
12	暗夜村落传送门	.gobject add 182061	　
13	部落营地传送门	.gobject add 182060	　
14	黑石塔之传送门	.gobject add 184247	　
15	召唤传送门(黄球)	.gobject add 181810	　
16	玛拉顿的传送门	.gobject add 178400	　
		.gobject activate 90072	


坐标
序号	目的地	命令	备注
1	奥格瑞玛鸟点	.go 1652 -4331 62 1	主城
2	奥格 武器大师	.go 1637 2091 -4822 1	主城
3	幽暗城门口 	.go 1909 235 53 0	主城
4	幽暗城鸟点	.go 1567 268 -43 0	主城
5	雷霆崖	.go -1391 140 23 1	主城
6	暴风城门口	.go -9065 434 94 0	主城
7	暴风城银行	.go -8832 627 94 0	主城
8	铁炉堡门口	.go -5032 -819 495 0	主城
9	铁炉堡银行	.go -4927 -947 502 0	主城
10	铁炉堡最高峰(屋顶)	.go -4866 -1445 580 0	主城
11	达纳苏斯	.go 9961 2055 1329 1	主城
12	GM岛	.go 16222.1 16252.1 12.5872 1	主城
13	藏宝海湾	.go -14302 518 9 0	副城
14	棘齿城	.go -977 -3788 6 1	副城
15	牛头出生地	.go -2254 -758 8.2 1	　
16	塔伦米尔：	.go -36 -927 55 0	　
17	陶拉祖营地：	.go -2375 -1880 96 1	　
18	灰谷:	.go 2324 -1668 125 1	　
19	千针石林山顶	.go -4885 -1596 101 1	　
			




四、常见问题
编译安装通常是正常的，问题往往处在map文件的获取，及map文件和当前编译版本不匹配，或者是数据库表，由于不完整，或者不同版本杂乱在一起导致没法正常启动。

1、代码调试方法
打印日志，以打印std:string类型的字符串name为例：
sLog.outError("111111： %s", name. c_str());


2、map和sql的版本问题
map文件必须跟服务器端的版本匹配，目前我的客户端是1.12.3版本
服务器端的版本是老的mangos-classic，这个源码也不记得从哪里搞的，反正现在的官方的github下的mangos-classic是没有可执行文件生成map，而且用本文档提供的方式生成的map也跟github上的官方源码版本是不匹配的，这个地方要注意。

只能用我的git下的服务端源码下的用于抽取的可执行文件，来抽取我的客户端版本1.12.3下的map文件，服务器才能正常启动，另外数据库初始化数据也必须用我的git下的初始化sql。

报错如下
Using DataDir ../data/
WORLD: VMap support included. LineOfSight:1, getHeight:1, indoorCheck:1
WORLD: VMap data directory is: ../data/vmaps
WORLD: MMap pathfinding enabled

VMap file '../data/vmaps/000.vmtree' is missing or point to wrong version vmap file, redo vmaps with latest vmap_assembler.exe program
Correct *.map files not found in path '../data/maps' or *.vmtree/*.vmtile files in '../data/vmaps'. Please place *.map and vmap files in appropriate directories or correct the DataDir value in the mangosd.conf file.


可能原因
这个问题可能跟map文件的版本也有关，但是从网上下别人的机器人端的map文件也提示报这个错，我怀疑是数据库里面某个字段对应的版本号有关系，导致提示这个错误。
待研究。


解决办法
重要找出问题原因了，原来是mangos启动时会检查地图的版本，如果不匹配直接退出，就没有启动成功了。
在代码src/game/GridMap.cpp里面有个判断语句，用到检查方法是：
vim /usr/local/src/wow/portalclassic/src/game/GridMap.cpp
bool GridMap::ExistVMap(uint32 mapid, int gx, int gy)
{
    if (VMAP::IVMapManager* vmgr = VMAP::VMapFactory::createOrGetVMapManager())
    {
        if (vmgr->isMapLoadingEnabled())
        { bool exists = vmgr->existsMap((sWorld.GetDataPath() + "vmaps").c_str(),  mapid, gx, gy);
             if (!exists)
            {
                std::string name = vmgr->getDirFileName(mapid, gx, gy);
                sLog.outError("VMap file '%s' is missing or point to wrong version vmap file, redo vmaps with latest vmap_assembler.exe program", (sWorld.GetDataPath() + "vmaps/" + name).c_str());
                return false;
            }
...


临时解决方案:
vim /usr/local/src/wow/portalclassic/src/game/vmap/MapTree.cpp
// const char VMAP_MAGIC[] = "VMAP_6.0";
// 修改bug,因为地图版本不同导致启动不了的问题
const char VMAP_MAGIC[] = "VMAP_5.0";
const char RAW_VMAP_MAGIC[] = "VMAP005";
 
vim /usr/local/src/wow/portalclassic/src/game/vmap/VMapDefinitions.h
// const char VMAP_MAGIC[] = "VMAP_6.0";       // used in final vmap files
// 修改bug,因为地图版本不同导致启动不了的问题
const char VMAP_MAGIC[] = "VMAP_5.0";
const char RAW_VMAP_MAGIC[] = "VMAP005";      // used in extracted vmap files with raw data



3、猎人宠物过段时间直接消失
锁表后查日志，发现，确实是服务器程序自动删除了数据库的一条记录导致：
vim /usr/local/src/wow/portalclassic/src/game/Pet.cpp
注释掉下面两行，测试：
465         //SqlStatement stmt = CharacterDatabase.CreateStatement(delPet, "DELETE FROM character_pet WHERE owner = ? AND id = ?");
 466         //stmt.PExecute(ownerLow, m_charmInfo->GetPetNumber());

上面的方法会引起bug。

解决办法：
这其实不是bug，而是60年代的猎人的精细设计一个体现，宠物一定时间不喂养，就会逃跑，因为饿死了，或者忠诚度太低导致。

修改配置文件：
vim mangosd.conf
# 启用宠物忠诚度,小于等于1，包括0，都会导致空闲宠物10分钟多一点的时间不喂食就逃跑了，改10以上即可。
Rate.Loyalty = 100

4、添加机器人报错
添加或者移除机器人时报错：
.bot add 索拉查的笛声
.bot remove 索拉查的笛声

界面提示：
指令语法格式错误

后台报错：
tailf /usr/local/wow_mangos_bot/logs/Server.log
2017-01-28 17:58:00 ERROR:MMAP:loadMap: 0003337.mmtile was built with generator v4, expected v5

原因还是地图版本问题导致：
因为当前源码的版本默认编译安装使用的题图版本是5，而我用extractor.exe之类的抽取程序抽取的map是4的版本，服务器启动会检查map，vmap，mmap版。

vim /usr/local/src/wow/portalclassic/src/game/MoveMapSharedDefines.h
找到如下一行：
#define MMAP_VERSION 5

修改为：
#define MMAP_VERSION 4

语法格式错误的解决方式：
修改mangos的mangos_string表的entry为10的记录，即把内容：
指令语法格式错误
设置为空，然后重启服务器即可，这个表示在服务器启动时就读取到内存的。


5、传送门已锁
添加传送门后，提示传送门锁定


待解决

vim /usr/local/src/wow/ClassicWOW/src/scriptdev2/scripts/eastern_kingdoms/gnomeregan/instance_gnomeregan.cpp



五、参考链接
我的服务端源码地址(含可用的mysql初始化数据)：
https://github.com/geektcp/mangos-classic

客户端下载地址：
http://pan.baidu.com/s/1hslkRVQ 


官方服务端下载地址(不能用)：
https://github.com/cmangos/mangos-classic


sql下载地址（可用）：
https://github.com/keyshuwen/Classicdb/

部署参考链接：
https://github.com/cmangos/issues/wiki

官方部署文档（有参考价值）：
https://github.com/cmangos/issues/wiki/Installation-Instructions


其他参考链接：
http://www.mangoscn.com/forum.php?mod=viewthread&tid=180042


60年代其他参考版本:
https://github.com/TrinityZero/TrinityZero


其他相关下载服务端：
git clone git://github.com/cmangos/mangos-classic.git 	mangos_server
git clone git://github.com/scriptdev2/scriptdev2-classic.git 	mangos_scriptdev2
git clone git://github.com/ACID-Scripts/Classic.git 	mangos_acid
git clone git://github.com/classicdb/database.git 		mangos_classicdb
git clone git://github.com/cmangos/classic-db.git

```
