# Model

## populate data for testing

see gist [populate.sh](https://gist.github.com/xoxwgys56/fd9fc9f5ac6d2e216956ec1a768433c8)

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

## remove object from many-to-many field

use `.remove` method.

```python
my_mood.interests.remove(my_interest)
```

Read more about [django-removing-object-from-manytomany-relationship](https://stackoverflow.com/questions/6333068/django-removing-object-from-manytomany-relationship)


## Reverse referencing

or you can call it. as "reverse-lookup".  

use `<attribute>_set` property.

```python
class Event(models.Model):
    name = models.CharField(max_length=255)
    venue = models.ForeignKey(Venue)

class Venue(models.Model):
    name = models.CharField(max_length=255)


events = venue.event_set
```

### Read more about reverse-ref

- [django-reverse-lookup-of-foreign-keys](https://stackoverflow.com/questions/15306897/django-reverse-lookup-of-foreign-keys)