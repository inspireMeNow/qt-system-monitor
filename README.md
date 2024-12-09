# 系统监控工具
### Cpu -- CPU信息
| EN                 | CN         | var         |
|--------------------|------------|-------------|
| Processor          | CPU编号    | Processor   |
| BogoMIPS           | CPU速度估测 | BogoMIPS    |
| Features           | 特征       | Features    |
| CPU implementer    | 销售ID     | implementer |
| CPU architecture   | 架构版本   | architecture|
| CPU variant        | 大版本号   | variant     |
| CPU part           | 产品代码   | part        |
| CPU revision       | 小版本号   | revision    |
| Hardware           | 主板型号   | Hardware    |

### Env -- 程序
| EN   | CN    | var  |
|------|-------|------|
| key  | 变量   | key  |
| value| 值     | value|

### File -- 文件
| EN         | CN         | var       |
|------------|------------|-----------|
| filesystem | 文件系统   | filesys   |
| size       | 总容量     | size      |
| used       | 已用       | used      |
| avail      | 可用       | avail     |
| use%       | 已用百分比 | usedperc  |
| mounted    | 挂载点     | mounted   |

### Memory -- 内存
| EN     | CN         | var   |
|--------|------------|-------|
| ID     | 内存号     | id    |
| total  | 内存总大小 | total |
| used   | 已经使用大小| used  |
| free   | 空闲内存大小| free  |
| shared | 共享内存大小| shared|
| cache  | 缓存       | cache |

### Process -- 进程
| EN     | CN                | var         |
|--------|-------------------|-------------|
| user   | 用户              | user        |
| pid    | 进程号            | pid         |
| command| 进程名            | command     |
| %cpu   | CPU占用百分比(%)  | processperc |
| %mem   | 内存占用量(MB)    | memperc     |
| start  | 启动时间          | start       |
| time   | 运行时长(s)       | time        |

### System -- 系统信息
| EN           | CN         | var         |
|--------------|------------|-------------|
| distributor  | 经销商     | distributor |
| description  | 系统描述   | description |
| release      | 系统版本   | release     |
| codename     | 发行版代号 | codename    |

### Software -- 已安装软件
| EN   | CN       | var  |
|------|----------|------|
| name | 软件名称 | name |

### Button -- 按钮状态
| EN         | CN       | var       |
|------------|----------|-----------|
| button_id  | 按钮编号 | button_id |
| status     | 按钮状态 | status    |

### Network Interface -- 网络接口
| EN               | CN              | var            |
|------------------|-----------------|----------------|
| ifname           | 接口名称        | ifname         |
| iftype           | 接口类型        | iftype         |
| mac              | MAC地址         | mac            |
| ip               | IP地址          | ip             |
| mask             | 子网掩码        | mask           |
| broadcast        | 广播地址        | broadcast      |
| gateway          | 网关            | gateway        |
| upload_speed     | 上传速度(bit)   | upload_speed   |
| download_speed   | 下载速度(bit)   | download_speed |
| upload_bytes     | 上传流量(bit)   | upload_bytes   |
| download_bytes   | 下载流量(bit)   | download_bytes |
