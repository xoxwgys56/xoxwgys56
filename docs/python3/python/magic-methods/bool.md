# bool

you can override `__bool__` method.

```python
class MyClass:
    flag: bool

    def __init__(self, flag):
        self.flag = flag

    # in python3 define `bool` method
    def __bool__(self):
        return self.flag

    # in python2 define `nonzero` method
    def __nonzero__(self):
        return self.flag

    # or define all of them!

if __name__ == "__main__":
    print(MyClass(True)) # True
```

## Read more

- [in-python-what-operator-to-override-for-if-object](https://stackoverflow.com/questions/5288990/in-python-what-operator-to-override-for-if-object/5289320)
