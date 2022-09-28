# Service

> see [k8s service](https://kubernetes.io/docs/concepts/services-networking/service/)

## Types

> see [k8s service types](https://kubernetes.io/docs/concepts/services-networking/service/#publishing-services-service-types)

| Type                                                                                          | description                    | usage                                                                        |
| --------------------------------------------------------------------------------------------- | ------------------------------ | ---------------------------------------------------------------------------- |
| ClusterIP                                                                                     | default service type           | only reachable from within the cluster                                       |
| [NodePort](https://kubernetes.io/docs/concepts/services-networking/service/#type-nodeport)    |                                |                                                                              |
| [LoadBalancer](https://kubernetes.io/docs/concepts/services-networking/service/#loadbalancer) | access from outside of cluster | externally using a cloud provider's load balancer                            |
| [ExternalName](https://kubernetes.io/docs/concepts/services-networking/service/#externalname) |                                | reach to [different namespace service](#access-difference-namespace-service) |


## Cases

### Access difference namespace service

use `ExternalName` service type.

> from [stackoverflow answer](https://stackoverflow.com/a/55650127/11082758)

```yml
kind: Service
apiVersion: v1
metadata:
  name: service-y
  namespace: namespace-a
spec:
  type: ExternalName
  externalName: service-y.namespace-b.svc.cluster.local
  ports:
  - port: 80
```

so `externalName` structured like below:

```yml
spec:
  type: ExternalName
  externalName: <servicename>.<namespace>.svc.cluster.local
```