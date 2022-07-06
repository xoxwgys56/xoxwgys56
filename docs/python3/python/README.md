# python

about python's python

## Generic

There is no official grammar about this. but partially supported.

### 1. using `isinstance`

```python
class MyClass:
    pass

if isinstance(inst, MyClass):
    pass
```

### 2. using `TypeVar`

it do not work in *python3.9*, no error.

```python
from typing import TypeVar, Generic, List


T = TypeVar("T")

class Stack(Generic[T]):
    def __init__(self) -> None:
        """Create an empty list with items of type T"""
        self.items: List[T] = []

    def push(self, item: T) -> None:
        self.items.append(item)

    def pop(self) -> T:
        return self.items.pop()
    
    def __str__(self) -> str:
        return "".join(str(self.items))


if __name__ == "__main__":
    stack = Stack[int]()
    stack.push(2)
    stack.pop()
    stack.push("x") # raise type error

    print(stack)
```

### Read more about python-generic

- [generics-templates-in-python](https://stackoverflow.com/questions/6725868/generics-templates-in-python)