# Admin

## create superuser without prompt

```shell
echo "from django.contrib.auth import get_user_model; User = get_user_model(); User.objects.create_superuser('admin', 'admin@myproject.com', 'password')" | python manage.py shell
```

read more about [how-to-automate-createsuperuser-on-django](https://stackoverflow.com/questions/6244382/how-to-automate-createsuperuser-on-django)
