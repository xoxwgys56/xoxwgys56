# Model

## get specific field

use `.values()` method after _queryset_

```python
>>> queryset = User.objects.filter(
    first_name__startswith='R'
).values('first_name', 'last_name')
>>> queryset
<QuerySet [{'first_name': 'Ricky', 'last_name': 'Dayal'}, {'first_name': 'Ritesh', 'last_name': 'Deshmukh'}]
```

Read more about [select_some_fields](https://books.agiliq.com/projects/django-orm-cookbook/en/latest/select_some_fields.html)
