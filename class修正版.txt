class Cpu --CPU信息
EN		CN		var
Processor	CPU编号  	Processor
BogoMIPS	CPU速度估测	BogoMIPS
Features			Features
CPU implementer		implementer
CPU architecture		architecture
CPU variant			variant
CPU part			part
CPU revision		revision
Hardware			Hardware

class Env --环境变量
EN		CN		var
key		变量		key		
value		值		value

class File --文件
EN		CN		var
filesystem	文件系统	filesys
size		总容量		size
used		已用		used
avail		可用		avail
use%		已用百分比	usedperc
mounted		挂载点		mounted

class Memory --内存
EN		CN		var
ID		内存号		id
total		内存总大小	total
used		已经使用大小	used
free		空闲内存大小	free
shared		共享内存大小	shared
cache		缓存		cache

class Process --进程
EN		CN		var
user		用户		user
pid		进程号		pid
command		进程名		command
%cpu		CPU占用百分比	cpuperc
%mem		内存占用百分比	memperc
start		启动时间	start
time		占用CPU时间	time

class System --系统信息
EN		CN		var
distributor	经销商		distributor
description	系统描述	description
release		系统版本	release
codename	发行版代号	codename

class Software --已安装软件
EN		CN		var
name		软件名称	name

