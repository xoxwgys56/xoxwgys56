# Dev

## populate data on docker

use `loaddata` command. see below example `docker-compose.yml`.  

```yml
command: >
      bash -c "echo 'Populate data'
      && python3 manage.py loaddata dump.json
      && python3 manage.py runserver 0.0.0.0:8000"
```

`dump.json` example

```json
[
    { "model": "auth.user",
        "pk": 1,
        "fields": {
            "username": "admin",
            "password": "pbkdf2_sha256$10000$vkRy7QauoLLj$ry+3xm3YX+YrSXbri8s3EcXDIrx5ceM+xQjtpLdw2oE=",
            "is_superuser": true,
            "is_staff": true,
            "is_active": true
        }
    }
]
```

### Read more about populate-data-on-docker

- stackoverflow [how-to-add-superuser-in-django-from-fixture](https://stackoverflow.com/a/34322435/11082758)
- tistory [dumpdata와 loaddata를 활용해서 데이터 옮기기](https://realcoding.tistory.com/2)
- django
  - [dumpdata](https://docs.djangoproject.com/en/4.0/ref/django-admin/#dumpdata)
  - [fixture data](https://docs.djangoproject.com/en/4.0/howto/initial-data/)


## Create superuser

### In console

```shell
python manage.py createsuperuser \
        --noinput \
        --username $DJANGO_SUPERUSER_USERNAME \
        --email $DJANGO_SUPERUSER_USERNAME
```

inside of `.env` or environment variables.

```conf
DJANGO_SUPERUSER_PASSWORD=**********
DJANGO_SUPERUSER_EMAIL=example@example.com
DJANGO_SUPERUSER_USERNAME=admin
```

### Read more about create-superuser

- stackoverflow [create-django-super-user-in-a-docker-container-without-inputting-password](https://stackoverflow.com/a/64050025/11082758)