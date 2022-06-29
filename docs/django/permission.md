# Permission

## DRF

### `has_permission`

this method work for authentication.  
use for:

- Is the request method allowed?
- Is the user authenticated?
- Is the user an admin or super user?

### `has_object_permission`

this method work for validate resource's owner.  
use for:

- Who created the object?
- In which group does the object belong to?

`has_object_premission` do not called, below situation:

- Request about List view
  - because list view do not handle about *single* object.
- When `has_permission` return *False*

### Multiple permissions

like below, you can defined multiple permission for view:

```python
permission_classes = [IsAuthenticated, IsStaff, SomeCustomPermissionClass]
```

in this case, permission is granted only if all of the classes **passed** (as `True`).  

or you can use logical operator (`&`, `|`, `~`). see example below:

```python
permission_classes = (~cond1 & cond2)
# or
permission_classes = [PermGroupA | PermGroupB]
```

example of permission that exclude *Finances* member only. (do not allowed to *unauthenticated* user).  

```python
permission_classes = [~IsFinancesMember & IsAuthenticated]
```

### More read about *DRF* permission

- testdriven
  - [drf-permissions](https://testdriven.io/blog/drf-permissions/)
  - custom-permission-classes-drf [combining-and-excluding-permission-classes](https://testdriven.io/blog/custom-permission-classes-drf/#combining-and-excluding-permission-classes)
- drf
  - PR for [negative operator](https://github.com/encode/django-rest-framework/pull/6361)

## Django guardian

about object permission, django-guardian makes easier to handle. see [example_project](https://django-guardian.readthedocs.io/en/stable/userguide/example_project.html).  

### More read about *django-guardian*

- testdriven
  - [drf-permission](https://testdriven.io/blog/built-in-permission-classes-drf/#djangoobjectpermissions)