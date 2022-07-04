# Typing

let's start typing.

```python
# python3.8 or higher
from __future__ import annotations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    # add import what you want typing
    pass
```

## Callable

for typing function in parameter.  
`Callable[[param1, param2 ...], ReturnType]`

```python
from __future__ import annotations
from typing import Callable, Any, Iterable


class MyClass:
    foo: str

    def __init__(self, foo: str):
        self.foo = foo

def func(foo: str) -> MyClass
    return MyClass(foo)


def imap(f: Callable[[str], MyClass], l: Iterable[Any]) -> List[Any]:
    """An immediate version of map, don't pass it any infinite iterables!"""
    return list(map(f, l))
```

### Read more about callable

- [how-do-python-functions-handle-the-types-of-parameters-that-you-pass-in](https://stackoverflow.com/questions/2489669/how-do-python-functions-handle-the-types-of-parameters-that-you-pass-in)