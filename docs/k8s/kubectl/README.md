# `kubectl`

<center>
    <img src="https://geekflare.com/wp-content/uploads/2021/03/kubectl.jpg" alt="kubernetes mark">
    <p>kubectl</p>
</center>

## Shortcuts

- [cheetsheet](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)

---

## Install

- [install on macOS](https://kubernetes.io/docs/tasks/tools/install-kubectl-macos/)

## Usage

### Basics

normal commands like below:

```shell
kubectl [command] [TYPE] [NAME] [flags]
```

`kubectl`의 문법은 유연하다. 예를 들어서 아래 명령의 결과는 모두 같다.

```shell
kubectl get pod pod1
kubectl get pods pod1
kubectl get po pod1
```

그리고 뒤에 `--watch`를 붙이면 실시간으로 결과를 보여준다.

```shell
kubectl get po pod1 --watch
```

하지만 그냥 `watch` 명령어를 사용하는게 더 이쁘게 나오기 때문에, 나는 `watch`를 사용하는 편이다.

```shell
watch kubectl get po pod1
```

### Get resource from namespace

all resource from namespace

```sh
kubectl get all -n <namespace>
```