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

### More read about *DRF* permission

- testdriven
  - [drf-permissions](https://testdriven.io/blog/drf-permissions/)
