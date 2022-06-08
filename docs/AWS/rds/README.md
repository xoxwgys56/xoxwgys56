# RDS

## access from ec2

### prerequisites

- located same vpc.

### use `nslookup`

you can get rds's ip address:

```shell
nslookup myexampledb.xxxx.us-east-1.rds.amazonaws.com
Server: xx.xx.xx.xx
Address: xx.xx.xx.xx#53

Non-authoritative answer:
Name: myexampledb.xxxx.us-east-1.rds.amazonaws.com
Address: 172.31.xx.x
```

### Read more about connectivity

- [rds-connectivity-instance-subnet-vpc](https://aws.amazon.com/premiumsupport/knowledge-center/rds-connectivity-instance-subnet-vpc/)
- [USER_VPC.Scenarios](https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/USER_VPC.Scenarios.html)
