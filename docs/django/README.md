# Django

DRF and django is seperated

## Run with port

```shell
python3 manage.py runserver :portNumber
```

### Read more about run-with-port

- stackoverflow [django-change-default-runserver-port](https://stackoverflow.com/a/23639676/11082758)

## OpenAPI

If you wanna use *OpenAPI* in django. you should use third-party library.  

## Async

simplely add `async` keyword to your view. like below:

```python
from django.http import HttpResponse


async def index(request):
    return HttpResponse("Hello, async Django!")
```

### Run with `gunicorn`

```shell
gunicorn myproject.asgi:application -k uvicorn.workers.UvicornWorker
```

### django channel

https://github.com/django/channels

### Error list

#### `TypeError: __call__() missing 1 required positional argument: 'send'`

answer from django.channel discussion [1736](https://github.com/django/channels/discussions/1736).  
add `.as_asig()` to view.

```python
# path(conf["intranet"]["address"].split("/")[3]+"/", Trade)
path(conf["intranet"]["address"].split("/")[3]+"/", Trade.as_asgi())
```

**Related url**

- stackoverflow [typeerror-call-missing-1-required-positional-argument-send-django](https://stackoverflow.com/questions/68194577/typeerror-call-missing-1-required-positional-argument-send-django)

### Read more about *async*

- testdriven [django-async-views](https://testdriven.io/blog/django-async-views/)
- wersdoerfer [django-31-async](https://wersdoerfer.de/blogs/ephes_blog/django-31-async/)
- stackoverflow
  - [django-async-to-sync-vs-asyncio-run](https://stackoverflow.com/questions/59503825/django-async-to-sync-vs-asyncio-run)
- django doc [uvicorn](https://docs.djangoproject.com/en/4.0/howto/deployment/asgi/uvicorn/)


## progress bar

https://buildwithdjango.com/blog/post/celery-progress-bars/