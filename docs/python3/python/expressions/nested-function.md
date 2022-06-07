# Nested function

## multiple parameter brackets

```python
foo(a)(b)
```

[python-functions-with-multiple-parameter-brackets](https://stackoverflow.com/questions/42874825/python-functions-with-multiple-parameter-brackets)

TL;DR; It's not multiple param bracket. It called **nested function**.

## Answer

Functions with multiple parameter brackets don't exist, as you saw when you tried to define one. There are, however, functions which return (other) functions:

```python
def func(a):
    def func2(b):
        return a + b
    return func2
```

Now when you call `func()` it returns the inner `func2` function:

```python
>>> func2 = func(1)  # You don't have to call it func2 here
>>> func2(2)
3
```

But if you don't need the inner function later on, then there's no need to save it into a variable and you can just call them one after the other:

```python
>>> func(1)(2)   # func(1) returns func2 which is then called with (2)
3
```

This is a very common idiom when defining decorators that take arguments.

---

Notice that calling `func()` always creates a *new* inner function, even though they're all named `func2` inside of the definition of our `func`:

```python
>>> f1 = func(1)
>>> f2 = func(1)
>>> f1(1), f2(1)
(2, 2)
>>> f1 is f2
False
```

---

> And, finally, what's the difference between f(a, b)and f(a)(b)?

It should be clear now that you know what `f(a)(b)` does, but to summarize:

- `f(a, b)` calls `f` with two parameters `a` and `b`
- `f(a)(b)` calls `f` with one parameter `a`, which then returns another function, which is then called with one parameter `b`
