# Redis 

> see [github page](https://github.com/bitnami/charts/tree/master/bitnami/redis/)

## Usage 

install through `helm-cli`

```shell
# add repo
helm repo add bitnami https://charts.bitnami.com/bitnami
# install chart
helm install my-redis-release bitnami/redis \
    --set cluster.enabled=true
    ...
```

### 📦 main parameters

> see [all parameters](https://github.com/bitnami/charts/tree/master/bitnami/redis/#parameters)

| type     | parameter               | default     | options                                                 | note                                                                                                                                                                                                        |
| -------- | ----------------------- | ----------- | ------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Global   | `global.redis.password` | ""          |                                                         |                                                                                                                                                                                                             |
| Global   | `global.storageClass`   | ""          |                                                         | recommend `ebs-sc` or `efs-sc` on AWS                                                                                                                                                                       |
| master   | `master.service.type`   | "ClusterIP" | "ClusterIP", "NodePort", "LoadBalancer", "ExternalName" | see detail about[k8s service types](https://kubernetes.io/docs/concepts/services-networking/service/#publishing-services-service-types). if you need external access outside of cluster, use "LoadBalancer" |
| master   | `master.nodeSelector`   | `{}`        | `{ nodeName: "redis"}`                                  | if you use terraform see [terraform usage](#assign-object-parameters)                                                                                                                                       |
| replicas | `replica.nodeSelector`  | `{}`        | `{ nodeName: "redis"}`                                  | same as `master.nodeSelector`                                                                                                                                                                               |
| replicas | `replica.replicaCount`  | 3           |                                                         | for testing I set up value as _1_                                                                                                                                                                           |

## Terraform usage

### assign object parameters


if you need assign object to parameter. you can not directly assign object to parameter.  
should iterate object and assign to parameter. like below:

```hcl
resource "helm_release" "my-redis-release" {
    set {
        name  = "master.nodeSelector.nodeName"
        value = "redis"
    }
}
```

## Connection

### connect through LoadBalancer

```shell
kubectl get svc
```