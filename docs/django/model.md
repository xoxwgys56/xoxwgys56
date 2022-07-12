# Model

## to dictionary

### 1. `instance.__dict__`

missing `many_to_many`, `foreign_key`

```python
data: dict = instance.__dict__

# return example
{
    '_foreign_key_cache': <OtherModel: OtherModel object>,
    '_state': <django.db.models.base.ModelState at 0x7ff0993f6908>,
    'auto_now_add': datetime.datetime(2018, 12, 20, 21, 34, 29, 494827, tzinfo=<UTC>),
    'foreign_key_id': 2,
    'id': 1,
    'normal_value': 1,
    'readonly_value': 2
}
```

### 2. `model_to_dict`

include `many_to_many` but missing uneditable field.

```python
from django.forms.models import model_to_dict


data: dict = model_to_dict(instance)

# return example
{
    'foreign_key': 2,
    'id': 1,
    'many_to_many': [<OtherModel: OtherModel object>],
    'normal_value': 1
}
```

### Read more about django-dict

- stackoverflow [convert-django-model-object-to-dict-with-all-of-the-fields-intact](https://stackoverflow.com/a/29088221/11082758)

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

## Bridge table

> also called *intermediary table* or *intermediate model*

In django, you can add `through` field (as paramter) on `ManyToManyField`.  

```python
from django.db import models


class Person(models.Model):
    name = models.CharField(max_length=50)


class Group(models.Model):
    name = models.CharField(max_length=128)
    members = models.ManyToManyField(
        Person,
        through='Membership',
        through_fields=('group', 'person'),
    )


class Membership(models.Model):
    """bridge table"""
    group = models.ForeignKey(Group, on_delete=models.CASCADE)
    person = models.ForeignKey(Person, on_delete=models.CASCADE)
    inviter = models.ForeignKey(
        Person,
        on_delete=models.CASCADE,
        related_name="membership_invites",
    )
    invite_reason = models.CharField(max_length=64)
```

I think specifying `through_fields` is more better to read.  

>if there is `through_fields` and model has multiple *foreign_key* it could be raise error.

### Read more about `through` fields

- Django
  - field [django.db.models.ManyToManyField.through_fields](https://docs.djangoproject.com/en/4.0/ref/models/fields/#django.db.models.ManyToManyField.through_fields)
  - model [intermediary-manytomany](https://docs.djangoproject.com/en/4.0/topics/db/models/#intermediary-manytomany)
- [tips-using-djangos-manytomanyfield](https://www.revsys.com/tidbits/tips-using-djangos-manytomanyfield/)
- [django-extend-manytomanyfield](https://lee-seul.github.io/django/2019/02/21/django-extend-manytomanyfield.html)
- IBM [relationships-bridge-tables](https://www.ibm.com/docs/en/cognos-analytics/11.1.0?topic=relationships-bridge-tables)
  - A logical data model may contain one or more many-to-many relationships. Physical data modelling techniques transform a many-to-many many-relationships into one-to many-relationships by adding *additional tables*. These are referred to as bridge tables.

## Update

```python
"""
return updated model instance count
below case, must return 1
"""
response = MyModel.objects.filter(pk=obj.pk).update(val=F('val') + 1)
```

it is like below SQL query:

```sql
UPDATE `model` SET `field1` = 2 WHERE `model`.`id` = 223
```

but what if `obj.pk` does not exist? is there raised `DoesNotExist` error from `.update` method or not?

```python
response = MyModel.objects.filter(pk=not_exist_pk).update(field=new_value)
print(response) # 0
```

it does not raise `DoesNotExist` error. so if you want check, you should validate response from `.update`.

### Read more about django-update

- django doc [refreshing-objects-from-database](https://docs.djangoproject.com/en/4.0/ref/models/instances/#refreshing-objects-from-database)
- stackoverflow [django-calling-update-on-a-single-model-instance-retrieved-by-get](https://stackoverflow.com/a/30353795/11082758)