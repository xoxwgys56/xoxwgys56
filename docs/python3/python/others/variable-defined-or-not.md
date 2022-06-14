# How to check variable defined or not

catch exception with `NameError`.

```python
try:
    test
except NameError as err:
    print(f"got error {err}") # got error name 'test' is not defined
```

read more about [Testing if a Variable Is Defined](https://www.oreilly.com/library/view/python-cookbook/0596001673/ch17s02.html)
