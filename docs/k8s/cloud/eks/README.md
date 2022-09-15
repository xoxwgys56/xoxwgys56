# EKS

<center>
    <img src="https://d1.awsstatic.com/product-page-diagram_Amazon-EKS%402x.ddc48a43756bff3baead68406d3cac88b4151a7e.ddc48a43756bff3baead68406d3cac88b4151a7e.png" alt="AWS EKS">
    <p>EKS</p>
</center>

## What is it?

`k8s`를 세팅하려면 여러가지 도구들이 필요한데, `EKS`는 기본적인 도구들을 제공하고, 컨테이너를 실행시키는 노드를 _EC2_로 제공해줘서 `k8s`를 사용하기 쉽게 만들어준다. 

> 필요한 기본적인 도구들:
>
> - etcd는 별도 오픈소스 입니다. 알아서 구축하세요.
> - kubernetes master는 stateless 입니다. 따라서 Clustering 과 같은 HA  기능을 제공하지 않습니다.
> - node에 설치되는 SW 중 Kubernetes가 제공하는 것은 Kublet과 Kube-proxy  입니다. conainer runtime을 제공하진 않습니다. 물론 OS도 제공하지 않습니다.
> A.K.A Add-on들도.... 엄밀하게 말 하면, Service Discovery에 사용되는 DNS나 Networking, Storage등도 Kubernetes의 본연은 아닙니다. 마치 Device Driver와 같은 것 입니다.
>
> copied from devocean [초보자를 위한 EKS 맛 보기](https://devocean.sk.com/blog/techBoardDetail.do?ID=163578)
---

## eksctl

- [eksctl.io](https://eksctl.io/)

eksctl is a command line tool for managing Amazon EKS clusters.

### Usage

```shell
eksctl create cluster
```

위의 명령은 아래의 파라미터를 default로 포함한다:

- exciting auto-generated name (e.g. `fabulous-mushroom-1527688624`)
- 2 `m5.large` worker node
- use official [AWS EKS AMI](https://github.com/awslabs/amazon-eks-ami)
- region as `us-west-2`
- use dedicated VPC

## terraform

- [eks-module](https://registry.terraform.io/modules/terraform-aws-modules/eks/aws/latest)

---

## Basics

### k8s object

### k8s pod

---

## Node

### custom trigger

---

## References about k8s

- AWS
  - [workshop](https://awskrug.github.io/eks-workshop/introduction/)
- terraform
  - [learn terraform eks](https://learn.hashicorp.com/tutorials/terraform/eks)