# ssh dir

create ssh alias.

## usage

1. create `~/.ssh/config` like below:

```config
Host ec2
  Hostname ec2-35-169-93-188.compute-1.amazonaws.com
  user ubuntu
  IdentityFile ~/.ssh/my-aws-key.pem
  Port 22
```

2. command like below:

```shell
ssh ec2
```

---

## Read more

- cloud-gc.readthedocs.io [ssh-config](https://cloud-gc.readthedocs.io/en/latest/chapter06_appendix/ssh-config.html)
