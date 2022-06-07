# underscore

[what-is-the-meaning-of-single-and-double-underscore-before-an-object-name](https://stackoverflow.com/questions/1301346/what-is-the-meaning-of-single-and-double-underscore-before-an-object-name)

## Single Underscore

Names, in a class, with a leading underscore are simply to indicate to other programmers that the attribute or method is intended to be private. However, nothing special is done with the name itself.

To quote [PEP-8](http://www.python.org/dev/peps/pep-0008/):

> \_single_leading_underscore: weak "internal use" indicator. E.g. from M import \* does not import objects whose name starts with an underscore.

## Double Underscore (Name Mangling)

From [the Python docs](https://docs.python.org/3/tutorial/classes.html#private-variables):

> Any identifier of the form **spam (at least two leading underscores, at most one trailing underscore) is textually replaced with _classname**spam, where classname is the current class name with leading underscore(s) stripped. This mangling is done without regard to the syntactic position of the identifier, so it can be used to define class-private instance and class variables, methods, variables stored in globals, and even variables stored in instances. private to this class on instances of other classes.

And a warning from the same page:

> Name mangling is intended to give classes an easy way to define “private” instance variables and methods, without having to worry about instance variables defined by derived classes, or mucking with instance variables by code outside the class. Note that the mangling rules are designed mostly to avoid accidents; it still is possible for a determined soul to access or modify a variable that is considered private.

## Example

```python
>>> class MyClass():
...     def __init__(self):
...             self.__superprivate = "Hello"
...             self._semiprivate = ", world!"
...
>>> mc = MyClass()
>>> print mc.__superprivate
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: myClass instance has no attribute '__superprivate'
>>> print mc._semiprivate
, world!
>>> print mc.__dict__
{'_MyClass__superprivate': 'Hello', '_semiprivate': ', world!'}
```

---

## Answer 2

`__foo__`: this is just a convention, a way for the Python system to use names that won't conflict with user names.

`_foo`: this is just a convention, a way for the programmer to indicate that the variable is private (whatever that means in Python).

`__foo`: this has real meaning: the interpreter replaces this name with `_classname__foo` as a way to ensure that the name will not overlap with a similar name in another class.

No other form of underscores have meaning in the Python world.

There's no difference between class, variable, global, etc in these conventions.
