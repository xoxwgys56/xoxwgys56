# EKS

still not sure which one is better to use and share.

- [EKS](#eks)
  - [eksctl](#eksctl)
    - [Usage](#usage)
  - [terraform](#terraform)
  - [Basics](#basics)
    - [k8s object](#k8s-object)
    - [k8s pod](#k8s-pod)
  - [Node](#node)
    - [custom trigger](#custom-trigger)
  - [References about k8s](#references-about-k8s)

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