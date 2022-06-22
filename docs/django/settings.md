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