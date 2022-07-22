# Apache

this article describle about `httpd`

## Prerequisites

if you have no `httpd`. install first.

```sh
# install httpd
sudo yum install -y httpd
# get status
sudo systemctl status httpd
# run httpd
sudo systemctl start httpd
```

## Proxy

this article use 8000 port as example.  

### `httpd.conf`

add proxy for listen custom port.  

```sh
sudo vim /etc/httpd/conf/httpd.conf
```

my case, I added as virtualHost

```conf
<VirtualHost *:8000>
    ServerName localhost:8000
    ProxyPreserveHost On
    ProxyPass /node http://localhost:8000
    ProxyPassReverse /node http://localhost:8000
</VirtualHost>
```

### check listen list

```sh
sudo netstat -ntlp | grep 8000
```

### about 80 port

> Non-privileged user (not root) can't open a listening socket on ports below 1024. [see detail](https://stackoverflow.com/a/60373143/11082758)


### Read more about apache-proxy

- stackoverflow 
  - [apache-and-node-js-on-the-same-server](https://stackoverflow.com/a/18604082/11082758)
  - [apache-reverse-proxy-not-working](https://stackoverflow.com/a/51213029/11082758)
  - [why-is-apache-giving-dns-lookup-failures](https://unix.stackexchange.com/questions/240590/why-is-apache-giving-dns-lookup-failures)
  - [nodejs-listen-eacces-permission-denied-0-0-0-080](https://stackoverflow.com/questions/60372618/nodejs-listen-eacces-permission-denied-0-0-0-080)
- AWS
  - [CreateWebServer](https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/CHAP_Tutorials.WebServerDB.CreateWebServer.html)
- httpd
  - [Basic example](https://httpd.apache.org/docs/2.4/mod/mod_proxy.html#examples)
  - [ec2-instance-hosting-unresponsive-website](https://aws.amazon.com/premiumsupport/knowledge-center/ec2-instance-hosting-unresponsive-website/)