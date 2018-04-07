[![Build Status](https://travis-ci.org/chikuwait/TCP_PortScanner.svg?branch=master)](https://travis-ci.org/chikuwait/TCP_PortScanner)
[![LICENCE](https://img.shields.io/dub/l/vibe-d.svg)](https://github.com/chikuwait/TCP_PortScanner/blob/master/LICENSE)
# TCP_PortScanner
TCP_portscanner can check on 0 - 65535 ports open on any host.

# How to use
First, You clone this project.
```
$ git clone https://github.com/chikuwait/TCP_PortScanner.git && cd TCP_PortScanner
```
And use the make command in this project.
```
$ make 
```
To use it, specify an arbitrary host or IP address as an argument.
```
$ ./scanner localhost
```
or 
```
$ ./scanner 127.0.0.1
```
# Example
```
$ ./scanner 127.0.0.1
Starting the portscan 
80 : Open
631 : Open
40330 : Open
44380 : Open
48852 : Open
```
# LICENSE
See [LICENSE](/LICENSE).
