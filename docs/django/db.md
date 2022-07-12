# DB

## verfiying connection

```python
from django.db import connections
from django.db.utils import OperationalError


db_conn = connections['default']
try:
    c = db_conn.cursor()
except OperationalError:
    connected = False
else:
    connected = True
```

### Read more about verifying conn

- stackoverflow [how-can-i-check-database-connection-to-mysql-in-django](https://stackoverflow.com/a/32109155/11082758)