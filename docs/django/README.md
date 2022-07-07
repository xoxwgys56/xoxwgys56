# Django

DRF and django is seperated

## OpenAPI

If you wanna use *OpenAPI* in django. you should use third-party library.  

## Async

simplely add `async` keyword to your view. like below:

```python
from django.http import HttpResponse


async def index(request):
    return HttpResponse("Hello, async Django!")
```

### Read more about *async*

- testdriven [django-async-views](https://testdriven.io/blog/django-async-views/)
- wersdoerfer [django-31-async](https://wersdoerfer.de/blogs/ephes_blog/django-31-async/)


## progress bar

https://buildwithdjango.com/blog/post/celery-progress-bars/