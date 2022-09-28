# Kubernetes

<center>
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/39/Kubernetes_logo_without_workmark.svg/617px-Kubernetes_logo_without_workmark.svg.png" alt="kubernetes mark" width="25%">
    <p>K8S</p>
</center>

## 무엇인가?

`k8s`는 `docker-compose`와 유사한 도구라고 생각할 수 있다.
`docker-compose`를 사용할 때, 우리는 volume, network, container를 정의하고 이를 실행시킨다. `k8s`도 마찬가지다.

하지만 `k8s`는 `docker-compose`에 비해 좀 더 많은 기능을 제공한다. 그 중 가장 대표적인 것이 `autoscaling`이다.  
`autoscaling`은 운영 중인 서비스의 컨테이너 수를 늘렸다가, 줄이는 것을 의미한다. 예를 들어 로그인 서버가 너무 많은 부하를 받는다면 이를 모니터링해서 컨테이너 수를 늘려줄 수 있다.

그 외에 volume (persist volume), network (containerIP, load balancer etc) 등을 관리하는 도구이다.

> 만약 현재 서비스가 `docker-compose`같은 도구가 필요없는 수준이라면, `k8s`를 도입하는게 맞는지 고민이 필요하다. 만약 하나의 서버(컨테이너)를 운영하는 서비스라면, **AWS**의 `EB`(_Elastic Beanstalk_)을 고려해보자.

---

## Tools

`k8s`를 사용하면 주로 사용하는 도구들이다.

- about `kubectl` is [here](kubectl/README.md)
- about `helm` is [here](helm/README.md)
- about terraform

---

## Cloud

`k8s`를 로컬에서 사용할 수도 있지만, 대부분의 경우 클라우드에서 사용한다.

- about `EKS` is [here](eks/README.md)