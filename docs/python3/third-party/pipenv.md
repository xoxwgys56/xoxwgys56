# pipenv

virtualenvs [docs.python-guide.org](https://docs.python-guide.org/dev/virtualenvs/)

## what is pipenv?

source: [ordinary-python-development-environment](https://jonnung.dev/python/2019/11/23/ordinary-python-development-environment/)

> `pip` 를 대신하는 패키지관리자

```shell
$ pipenv --python 3.7.5
$ pipenv shell
# same as source ./venv/bin/activate

$ pipenv install selenium
# assign version is optional
$ pipenv install black --dev --pre
$ pipenv install pylint --dev
```

가상환경의 경로가 다르다.

```shell
/Users/<usrname>/.local/share/virtualenvs/browser-GLqq8keY/bin/python3
```

경로를 보면 해시를 이용한다는 것을 알 수 있다.

과정들을 통해 `Pipfile` 이 생성되었다. 내용은 아래와 같다.

```shell
[[source]]
url = "https://pypi.org/simple"
verify_ssl = true
name = "pypi"

[packages]
selenium = "*"
requests = "*"
fake-useragent = "*"
loguru = "*"

[dev-packages]
black = "*"
pylint = "*"

[requires]
python_version = "3.7"

[pipenv]
allow_prereleases = true
```

## get `requirements.txt`

```shell
# https://github.com/pypa/pipenv/issues/3493

pipenv run pip freeze > requirements.txt
```

### Allow creating requirements.txt files without dev-packages

```shell
# https://github.com/pypa/pipenv/issues/942

pipenv lock
# or
pipenv lock > requirements.txt
```

## version conflict

source: [how-to-fix-locking-failed-in-pipenv](https://stackoverflow.com/questions/64124931/how-to-fix-locking-failed-in-pipenv)

Try to remove `Pipefile.lock` before installing a package

---

## Read more

- 👍 [pipenv advanced](https://github.com/pypa/pipenv/blob/main/docs/advanced.rst)
