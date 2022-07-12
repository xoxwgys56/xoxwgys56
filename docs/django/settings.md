# settings

about django `settings.py` setup config file

## split file by environment

> No official/general rule about this

### 1. Simple Package Organization for Environments

1. create `/settings` directory
2. and locate several settings file inside of `/settings` like below

```shell
[myapp]$ tree settings
settings
├── __init__.py
├── defaults.py
├── dev.py
└── production.py
```

for example, inside of `dev.py`:

```python
from default import *
...
```

and set current environment like below:

```shell
export DJANGO_SETTINGS_MODULE=myapp.settings.production
```

#### Read more about Simple Package Organization for Environments

- django doc [SimplePackageOrganizationforEnvironments](https://code.djangoproject.com/wiki/SplitSettings#SimplePackageOrganizationforEnvironments)
- about `DJANGO_SETTINGS_MODULE`
  - stackoverflow [django-how-to-manage-development-and-production-settings](https://stackoverflow.com/questions/10664244/django-how-to-manage-development-and-production-settings)

### 2. use `_env` suffix

create `settings_dev.py` for development environment.  
and call it when launch django-server like below:

```shell
python3 manage.py runserver --settings=settings_dev.py
```

read more about [what-is-the-variable-that-indicates-the-environment-in-django](https://stackoverflow.com/questions/1233463/what-is-the-variable-that-indicates-the-environment-in-django)

## Get variable

you can access through `settings`.

```python
from django.conf import settings

# "FOO" must defined inside of `settings.py`
foo = settings.FOO
```

but it could be raise an error. in this case, there is 2 solutions.  

1. use `getattr`

```python
foo = getattr(settings, 'FOO', 'default value of foo')
```

2. catch with `AttributeError`

```python
try:
  foo = settings.FOO
except AttributeError as err:
  print(err)
```

### Read more about get setting var

- [how-to-define-a-default-value-for-a-custom-django-setting](https://stackoverflow.com/questions/5601590/how-to-define-a-default-value-for-a-custom-django-setting)
- [how-do-i-reference-a-django-settings-variable-in-my-models-py](https://stackoverflow.com/questions/7867797/how-do-i-reference-a-django-settings-variable-in-my-models-py)

## In server (mod_wsgi)

replace set env-var like below:

```python
import os


# os.environ.setdefault("DJANGO_SETTINGS_MODULE", "mysite.settings")
os.environ['DJANGO_SETTINGS_MODULE'] = 'mysite.settings'
```

### Read more about mod_wsgi

- django doc [settings](https://docs.djangoproject.com/en/4.0/topics/settings/#on-the-server-mod-wsgi)
- stackoverflow [improperlyconfigured-you-must-either-define-the-environment-variable-django-set](https://stackoverflow.com/questions/26082128/improperlyconfigured-you-must-either-define-the-environment-variable-django-set)