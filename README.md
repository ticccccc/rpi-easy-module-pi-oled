# rpi-easy-module-pi-oled

树莓派4b easy module pi模块液晶屏(12864)显示

## 什么是树莓派

[树莓派](https://www.raspberrypi.org): 是一款arm的单板机(SBC, Single Board Computer)

## 使用的树莓派版本

raspberrey pi 4B(4G)

## 树莓派的GPIO信息

```bash
$gpio readall
 +-----+-----+---------+------+---+---Pi 4B--+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   2 |   8 |   SDA.1 | ALT0 | 1 |  3 || 4  |   |      | 5v      |     |     |
 |   3 |   9 |   SCL.1 |  OUT | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT5 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT5 | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |  OUT | 0 | 11 || 12 | 1 | IN   | GPIO. 1 | 1   | 18  |
 |  27 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI | ALT0 | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO | ALT0 | 0 | 21 || 22 | 0 | OUT  | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK | ALT0 | 0 | 23 || 24 | 1 | OUT  | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | OUT  | CE1     | 11  | 7   |
 |   0 |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   5 |  21 | GPIO.21 |  OUT | 0 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 1 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 1 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |   IN | 1 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 4B--+---+------+---------+-----+-----+
 ```

## easy module pi 是什么

由[ywrobot studio](http://wiki.ywrobot.net/index.php?title=%E9%A6%96%E9%A1%B5)制作的一块多合一的印刷电路板. 可惜在他们的网站上并没有找到这块板子的介绍, 提供一个[淘宝链接](https://item.taobao.com/item.htm?spm=a230r.1.14.19.b04827fa6ObwFJ&id=635885331685&ns=1&abbucket=2#detail)

关于 easy module pi的电路信息存储在[emp](emp)目录内

## 项目功能介绍

使用 easy module pi 的oled屏幕展示ip, cup, 内存等信息

## 如何编译&执行

```bash
$# raspberrey pi的命令行环境
$# 当前目录下执行 没有cmake请自行安装
$# 依赖wiringPi 使用了国内的github镜像 hub.fastgit.org 如果无法下载请使用 github.com
$# 编译环境 gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)
$# 使用c++ std=17 
$cmake -S . -B build
$cmake --build build
$bin/oled
```

## 最终试验结果

[video](video/oled.mp4)
