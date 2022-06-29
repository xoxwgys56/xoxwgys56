# Admin

## create superuser without prompt

```shell
echo "from django.contrib.auth import get_user_model; User = get_user_model(); User.objects.create_superuser('admin', 'admin@myproject.com', 'password')" | python manage.py shell
```

read more about [how-to-automate-createsuperuser-on-django](https://stackoverflow.com/questions/6244382/how-to-automate-createsuperuser-on-django)

## ManyToMany Field

it does not work for me.

```python
class ProfileAdmin(UserAdmin)
    filter_horizontal = ('opetest',)
```

read more about [django-admin-manytomanyfield](https://stackoverflow.com/questions/8043881/django-admin-manytomanyfield)