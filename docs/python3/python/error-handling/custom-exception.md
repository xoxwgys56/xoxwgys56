# custom exception

# proper way to declare custom exception

> [https://stackoverflow.com/questions/1319615/proper-way-to-declare-custom-exceptions-in-modern-python](https://stackoverflow.com/questions/1319615/proper-way-to-declare-custom-exceptions-in-modern-python)

# Answer

# **"Proper way to declare custom exceptions in modern Python?"**

This is fine, unless your exception is really a type of a more specific exception:

```python
class MyException(Exception):
    pass
```

Or better (maybe perfect), instead of `pass` give a docstring:

```python
class MyException(Exception):
    """Raise for my specific kind of exception"""
```

## Subclassing Exception Subclasses

From the [docs](https://docs.python.org/2/library/exceptions.html#exceptions.BaseException)

> ExceptionAll built-in, non-system-exiting exceptions are derived from this class. All user-defined exceptions should also be derived from this class.

That means that **if** your exception is a type of a more specific exception, subclass that exception instead of the generic `Exception` (and the result will be that you still derive from `Exception` as the docs recommend). Also, you can at least provide a docstring (and not be forced to use the `pass` keyword):

```python
class MyAppValueError(ValueError):
    '''Raise when my specific value is wrong'''

```

Set attributes you create yourself with a custom `__init__`. Avoid passing a dict as a positional argument, future users of your code will thank you. If you use the deprecated message attribute, assigning it yourself will avoid a `DeprecationWarning`:

```python
class MyAppValueError(ValueError):
    '''Raise when a specific subset of values in context of app is wrong'''
    def __init__(self, message, foo, *args):
        self.message = message # without this you may get DeprecationWarning
        # Special attribute you desire with your Error,
        # perhaps the value that caused the error?:
        self.foo = foo
        # allow users initialize misc. arguments as any other builtin Error
        super(MyAppValueError, self).__init__(message, foo, *args)
```

There's really no need to write your own `__str__` or `__repr__`. The builtin ones are very nice, and your **cooperative inheritance** ensures that you use it.

## Critique of the top answer

> Maybe I missed the question, but why not:

```python
class MyException(Exception):
    pass

```

Again, the problem with the above is that in order to catch it, you'll either have to name it specifically (importing it if created elsewhere) or catch Exception, (but you're probably not prepared to handle all types of Exceptions, and you should only catch exceptions you are prepared to handle). Similar criticism to the below, but additionally that's not the way to initialize via `super`, and you'll get a `DeprecationWarning` if you access the message attribute:

> Edit: to override something (or pass extra args), do this:

```python
class ValidationError(Exception):
    def __init__(self, message, errors):

        # Call the base class constructor with the parameters it needs
        super(ValidationError, self).__init__(message)

        # Now for your custom code...
        self.errors = errors
```

> That way you could pass dict of error messages to the second param, and get to it later with e.errors

It also requires exactly two arguments to be passed in (aside from the `self`.) No more, no less. That's an interesting constraint that future users may not appreciate.

**To be direct - it violates [Liskov substitutability](https://en.wikipedia.org/wiki/Liskov_substitution_principle).**

I'll demonstrate both errors:

```python
>>> ValidationError('foo', 'bar', 'baz').message

Traceback (most recent call last):
  File "<pyshell#10>", line 1, in <module>
    ValidationError('foo', 'bar', 'baz').message
TypeError: __init__() takes exactly 3 arguments (4 given)

>>> ValidationError('foo', 'bar').message
__main__:1: DeprecationWarning: BaseException.message has been deprecated as of Python 2.6
'foo'
```

Compared to:

```python
>>> MyAppValueError('foo', 'FOO', 'bar').message
'foo'
```
