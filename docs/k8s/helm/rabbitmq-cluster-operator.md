# RabbitMQ cluster operator

- see [github page](https://github.com/bitnami/charts/tree/master/bitnami/rabbitmq-cluster-operator/)
- see [official guide](https://www.rabbitmq.com/kubernetes/operator/quickstart-operator.html) about rabbitmq kubernetes operator
  - see [production-ready example](https://github.com/rabbitmq/cluster-operator/tree/main/docs/examples/production-ready)


## Install 

install through `helm-cli`

```shell
# add repo
helm repo add bitnami https://charts.bitnami.com/bitnami
# install rabbitmq-cluster-operator
helm install my-rabbitmq-release bitnami/rabbitmq-cluster-operator \
    --namespace rabbitmq-system \ # recommend namespace
    ...
```

and there is something missing (I don't know why) so after that install [rabbitmq-cluster](./rabbitmq-cluster.yml).

```shell
kubectl create -f ./rabbitmq-cluster.yml -n rabbitmq-system
```


## Usage

### 📦 main parameters

> see [all parameters](https://github.com/bitnami/charts/tree/master/bitnami/redis/#parameters)

| type               | parameter                              | default       | options                                                         | note                                                                                                                                                                                                        |
| ------------------ | -------------------------------------- | ------------- | --------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Global             | `global.storageClass`                  | ""            |                                                                 | did not used                                                                                                                                                                                                |
| cluster            | `clusterOperator.metrics.service.type` | `"ClusterIP"` | `"ClusterIP"`, `"NodePort"`, `"LoadBalancer"`, `"ExternalName"` | see detail about[k8s service types](https://kubernetes.io/docs/concepts/services-networking/service/#publishing-services-service-types). if you need external access outside of cluster, use "LoadBalancer" |
| cluster            | `clusterOperator.nodeSelector`         | `{}`          | `{ nodeName: "rabbitmq"}`                                       | if you use terraform see [terraform usage](#assign-object-parameters)                                                                                                                                       |
| messaging topology | `msgTopologyOperator.replicaCount`     | 1             |                                                                 |                                                                                                                                                                                                             |
| messaging topology | `msgTopologyOperator.nodeSelector`     | `{}`          |                                                                 | same as `clusterOperator.nodeSelector`                                                                                                                                                                      |

## Terraform usage

### assign object parameters


if you need assign object to parameter. you can not directly assign object to parameter.  
should iterate object and assign to parameter. like below:

```hcl
resource "helm_release" "my-rabbitmq-release" {
    ...

    set {
        name  = "clusterOperator.nodeSelector.nodeName"
        value = "rabbitmq"
    }
}
```

## Connection

### connect through LoadBalancer

```shell
kubectl get svc
```

### dashboard

```shell
username="$(kubectl get secret -n rabbitmq-system rabbitmq-cluster-default-user -o jsonpath='{.data.username}' | base64 --decode)"
echo "username: $username"
password="$(kubectl get secret -n rabbitmq-system rabbitmq-cluster-default-user -o jsonpath='{.data.password}' | base64 --decode)"
echo "password: $password"

# port-forward to access on local
kubectl port-forward -n rabbitmq-system "service/rabbitmq-cluster" 15672
```