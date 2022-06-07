# `__slot__`

[usage-of-slots](https://stackoverflow.com/questions/472000/usage-of-slots/28059785#28059785)

> **In Python, what is the purpose of `__slots__` and what are the cases one should avoid this?**

## TLDR

The special attribute [`__slots__`](https://docs.python.org/3/reference/datamodel.html#slots) allows you to explicitly state which instance attributes you expect your object instances to have, with the expected results:

1. **faster** attribute access.
2. **space savings** in memory.

The space savings is from

1. Storing value references in slots instead of `__dict__`.
2. Denying [`__dict__`](https://docs.python.org/3/library/stdtypes.html#object.__dict__) and [`__weakref__`](https://stackoverflow.com/questions/36787603/what-exactly-is-weakref-in-python) creation if parent classes deny them and you declare `__slots__`.

### Quick Caveats

Small caveat, you should only declare a particular slot one time in an inheritance tree. For example:

```python
class Base:
    __slots__ = 'foo', 'bar'

class Right(Base):
    __slots__ = 'baz',

class Wrong(Base):
    __slots__ = 'foo', 'bar', 'baz'        # redundant foo and bar

```

Python doesn't object when you get this wrong (it probably should), problems might not otherwise manifest, but your objects will take up more space than they otherwise should. Python 3.8:

```python
>>> from sys import getsizeof
>>> getsizeof(Right()), getsizeof(Wrong())
(56, 72)

```

This is because the Base's slot descriptor has a slot separate from the Wrong's. This shouldn't usually come up, but it could:

```python
>>> w = Wrong()
>>> w.foo = 'foo'
>>> Base.foo.__get__(w)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: foo
>>> Wrong.foo.__get__(w)
'foo'

```

The biggest caveat is for multiple inheritance - multiple "parent classes with nonempty slots" cannot be combined.

To accommodate this restriction, follow best practices: Factor out all but one or all parents' abstraction which their concrete class respectively and your new concrete class collectively will inherit from - giving the abstraction(s) empty slots (just like abstract base classes in the standard library).

See section on multiple inheritance below for an example.

### Requirements

- To have attributes named in `__slots__` to actually be stored in slots instead of a `__dict__`, a class must inherit from `object`.
- To prevent the creation of a `__dict__`, you must inherit from `object` and all classes in the inheritance must declare `__slots__` and none of them can have a `'__dict__'` entry.

There are a lot of details if you wish to keep reading.

## Why use `__slots__`: Faster attribute access.

The creator of Python, Guido van Rossum, [states](http://python-history.blogspot.com/2010/06/inside-story-on-new-style-classes.html) that he actually created `__slots__` for faster attribute access.

It is trivial to demonstrate measurably significant faster access:

```python
import timeit

class Foo(object): __slots__ = 'foo',

class Bar(object): pass

slotted = Foo()
not_slotted = Bar()

def get_set_delete_fn(obj):
    def get_set_delete():
        obj.foo = 'foo'
        obj.foo
        del obj.foo
    return get_set_delete

```

and

```python
>>> min(timeit.repeat(get_set_delete_fn(slotted)))
0.2846834529991611
>>> min(timeit.repeat(get_set_delete_fn(not_slotted)))
0.3664822799983085

```

The slotted access is almost 30% faster in Python 3.5 on Ubuntu.

```python
>>> 0.3664822799983085 / 0.2846834529991611
1.2873325658284342

```

In Python 2 on Windows I have measured it about 15% faster.

## Why use `__slots__`: Memory Savings

Another purpose of `__slots__` is to reduce the space in memory that each object instance takes up.

[My own contribution to the documentation clearly states the reasons behind this](https://docs.python.org/3/reference/datamodel.html#slots):

> The space saved over using **dict** can be significant.

[SQLAlchemy attributes](http://docs.sqlalchemy.org/en/rel_1_0/changelog/migration_10.html#significant-improvements-in-structural-memory-use) a lot of memory savings to `__slots__`.

To verify this, using the Anaconda distribution of Python 2.7 on Ubuntu Linux, with `guppy.hpy` (aka heapy) and `sys.getsizeof`, the size of a class instance without `__slots__` declared, and nothing else, is 64 bytes. That does *not* include the `__dict__`. Thank you Python for lazy evaluation again, the `__dict__` is apparently not called into existence until it is referenced, but classes without data are usually useless. When called into existence, the `__dict__` attribute is a minimum of 280 bytes additionally.

In contrast, a class instance with `__slots__` declared to be `()` (no data) is only 16 bytes, and 56 total bytes with one item in slots, 64 with two.

For 64 bit Python, I illustrate the memory consumption in bytes in Python 2.7 and 3.6, for `__slots__` and `__dict__` (no slots defined) for each point where the dict grows in 3.6 (except for 0, 1, and 2 attributes):

```plain
       Python 2.7             Python 3.6
attrs  __slots__  __dict__*   __slots__  __dict__* | *(no slots defined)
none   16         56 + 272†   16         56 + 112† | †if __dict__ referenced
one    48         56 + 272    48         56 + 112
two    56         56 + 272    56         56 + 112
six    88         56 + 1040   88         56 + 152
11     128        56 + 1040   128        56 + 240
22     216        56 + 3344   216        56 + 408
43     384        56 + 3344   384        56 + 752

```

So, in spite of smaller dicts in Python 3, we see how nicely `__slots__` scale for instances to save us memory, and that is a major reason you would want to use `__slots__`.

Just for completeness of my notes, note that there is a one-time cost per slot in the class's namespace of 64 bytes in Python 2, and 72 bytes in Python 3, because slots use data descriptors like properties, called "members".

```python
>>> Foo.foo
<member 'foo' of 'Foo' objects>
>>> type(Foo.foo)
<class 'member_descriptor'>
>>> getsizeof(Foo.foo)
72

```

## Demonstration of `__slots__`

To deny the creation of a `__dict__`, you must subclass `object`:

```python
class Base(object):
    __slots__ = ()

```

now:

```python
>>> b = Base()
>>> b.a = 'a'
Traceback (most recent call last):
  File "<pyshell#38>", line 1, in <module>
    b.a = 'a'
AttributeError: 'Base' object has no attribute 'a'

```

Or subclass another class that defines `__slots__`

```python
class Child(Base):
    __slots__ = ('a',)

```

and now:

```python
c = Child()
c.a = 'a'

```

but:

```python
>>> c.b = 'b'
Traceback (most recent call last):
  File "<pyshell#42>", line 1, in <module>
    c.b = 'b'
AttributeError: 'Child' object has no attribute 'b'

```

To allow `__dict__` creation while subclassing slotted objects, just add `'__dict__'` to the `__slots__` (note that slots are ordered, and you shouldn't repeat slots that are already in parent classes):

```python
class SlottedWithDict(Child):
    __slots__ = ('__dict__', 'b')

swd = SlottedWithDict()
swd.a = 'a'
swd.b = 'b'
swd.c = 'c'

```

and

```pyhthon
>>> swd.__dict__
{'c': 'c'}

```

Or you don't even need to declare `__slots__` in your subclass, and you will still use slots from the parents, but not restrict the creation of a `__dict__`:

```pyhthon
class NoSlots(Child): pass
ns = NoSlots()
ns.a = 'a'
ns.b = 'b'

```

And:

```pyhthon
>>> ns.__dict__
{'b': 'b'}

```

However, `__slots__` may cause problems for multiple inheritance:

```pyhthon
class BaseA(object):
    __slots__ = ('a',)

class BaseB(object):
    __slots__ = ('b',)

```

Because creating a child class from parents with both non-empty slots fails:

```pyhthon
>>> class Child(BaseA, BaseB): __slots__ = ()
Traceback (most recent call last):
  File "<pyshell#68>", line 1, in <module>
    class Child(BaseA, BaseB): __slots__ = ()
TypeError: Error when calling the metaclass bases
    multiple bases have instance lay-out conflict

```

If you run into this problem, You *could* just remove `__slots__` from the parents, or if you have control of the parents, give them empty slots, or refactor to abstractions:

```pyhthon
from abc import ABC

class AbstractA(ABC):
    __slots__ = ()

class BaseA(AbstractA):
    __slots__ = ('a',)

class AbstractB(ABC):
    __slots__ = ()

class BaseB(AbstractB):
    __slots__ = ('b',)

class Child(AbstractA, AbstractB):
    __slots__ = ('a', 'b')

c = Child() # no problem!

```

### Add `'__dict__'` to `__slots__` to get dynamic assignment:

```pyhthon
class Foo(object):
    __slots__ = 'bar', 'baz', '__dict__'

```

and now:

```pyhthon
>>> foo = Foo()
>>> foo.boink = 'boink'

```

So with `'__dict__'` in slots we lose some of the size benefits with the upside of having dynamic assignment and still having slots for the names we do expect.

When you inherit from an object that isn't slotted, you get the same sort of semantics when you use `__slots__` - names that are in `__slots__` point to slotted values, while any other values are put in the instance's `__dict__`.

Avoiding `__slots__` because you want to be able to add attributes on the fly is actually not a good reason - just add `"__dict__"` to your `__slots__` if this is required.

You can similarly add `__weakref__` to `__slots__` explicitly if you need that feature.

### Set to empty tuple when subclassing a namedtuple:

The namedtuple builtin make immutable instances that are very lightweight (essentially, the size of tuples) but to get the benefits, you need to do it yourself if you subclass them:

```pyhthon
from collections import namedtuple
class MyNT(namedtuple('MyNT', 'bar baz')):
    """MyNT is an immutable and lightweight object"""
    __slots__ = ()

```

usage:

```pyhthon
>>> nt = MyNT('bar', 'baz')
>>> nt.bar
'bar'
>>> nt.baz
'baz'

```

And trying to assign an unexpected attribute raises an `AttributeError` because we have prevented the creation of `__dict__`:

```pyhthon
>>> nt.quux = 'quux'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'MyNT' object has no attribute 'quux'

```

You *can* allow `__dict__` creation by leaving off `__slots__ = ()`, but you can't use non-empty `__slots__` with subtypes of tuple.

## Biggest Caveat: Multiple inheritance

Even when non-empty slots are the same for multiple parents, they cannot be used together:

```pyhthon
class Foo(object):
    __slots__ = 'foo', 'bar'
class Bar(object):
    __slots__ = 'foo', 'bar' # alas, would work if empty, i.e. ()

>>> class Baz(Foo, Bar): pass
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: Error when calling the metaclass bases
    multiple bases have instance lay-out conflict

```

Using an empty `__slots__` in the parent seems to provide the most flexibility, **allowing the child to choose to prevent or allow** (by adding `'__dict__'` to get dynamic assignment, see section above) **the creation of a `__dict__`**:

```pyhthon
class Foo(object): __slots__ = ()
class Bar(object): __slots__ = ()
class Baz(Foo, Bar): __slots__ = ('foo', 'bar')
b = Baz()
b.foo, b.bar = 'foo', 'bar'

```

You don't *have* to have slots - so if you add them, and remove them later, it shouldn't cause any problems.

**Going out on a limb here**: If you're composing [mixins](https://stackoverflow.com/questions/860245/mixin-vs-inheritance/27907511#27907511) or using [abstract base classes](https://stackoverflow.com/questions/372042/difference-between-abstract-class-and-interface-in-python/31439126#31439126), which aren't intended to be instantiated, an empty `__slots__` in those parents seems to be the best way to go in terms of flexibility for subclassers.

To demonstrate, first, let's create a class with code we'd like to use under multiple inheritance

```pyhthon
class AbstractBase:
    __slots__ = ()
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def __repr__(self):
        return f'{type(self).__name__}({repr(self.a)}, {repr(self.b)})'

```

We could use the above directly by inheriting and declaring the expected slots:

```pyhthon
class Foo(AbstractBase):
    __slots__ = 'a', 'b'

```

But we don't care about that, that's trivial single inheritance, we need another class we might also inherit from, maybe with a noisy attribute:

```pyhthon
class AbstractBaseC:
    __slots__ = ()
    @property
    def c(self):
        print('getting c!')
        return self._c
    @c.setter
    def c(self, arg):
        print('setting c!')
        self._c = arg

```

Now if both bases had nonempty slots, we couldn't do the below. (In fact, if we wanted, we could have given `AbstractBase` nonempty slots a and b, and left them out of the below declaration - leaving them in would be wrong):

```
class Concretion(AbstractBase, AbstractBaseC):
    __slots__ = 'a b _c'.split()

```

And now we have functionality from both via multiple inheritance, and can still deny `__dict__` and `__weakref__` instantiation:

```
>>> c = Concretion('a', 'b')
>>> c.c = c
setting c!
>>> c.c
getting c!
Concretion('a', 'b')
>>> c.d = 'd'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Concretion' object has no attribute 'd'

```

## Other cases to avoid slots:

- Avoid them when you want to perform `__class__` assignment with another class that doesn't have them (and you can't add them) unless the slot layouts are identical. (I am very interested in learning who is doing this and why.)
- Avoid them if you want to subclass variable length builtins like long, tuple, or str, and you want to add attributes to them.
- Avoid them if you insist on providing default values via class attributes for instance variables.

You may be able to tease out further caveats from the rest of the `__slots__` [documentation (the 3.7 dev docs are the most current)](https://docs.python.org/3.7/reference/datamodel.html#slots), which I have made significant recent contributions to.

## Critiques of other answers

The current top answers cite outdated information and are quite hand-wavy and miss the mark in some important ways.

### Do not "only use `__slots__` when instantiating lots of objects"

I quote:

> "You would want to use **slots** if you are going to instantiate a lot (hundreds, thousands) of objects of the same class."

Abstract Base Classes, for example, from the `collections` module, are not instantiated, yet `__slots__` are declared for them.

Why?

If a user wishes to deny `__dict__` or `__weakref__` creation, those things must not be available in the parent classes.

`__slots__` contributes to reusability when creating interfaces or mixins.

It is true that many Python users aren't writing for reusability, but when you are, having the option to deny unnecessary space usage is valuable.

### `__slots__` doesn't break pickling

When pickling a slotted object, you may find it complains with a misleading `TypeError`:

```pyhthon
>>> pickle.loads(pickle.dumps(f))
TypeError: a class that defines __slots__ without defining __getstate__ cannot be pickled

```

This is actually incorrect. This message comes from the oldest protocol, which is the default. You can select the latest protocol with the `-1` argument. In Python 2.7 this would be `2` (which was introduced in 2.3), and in 3.6 it is `4`.

```pyhthon
>>> pickle.loads(pickle.dumps(f, -1))
<__main__.Foo object at 0x1129C770>

```

in Python 2.7:

```pyhthon
>>> pickle.loads(pickle.dumps(f, 2))
<__main__.Foo object at 0x1129C770>

```

in Python 3.6

```pyhthon
>>> pickle.loads(pickle.dumps(f, 4))
<__main__.Foo object at 0x1129C770>

```

So I would keep this in mind, as it is a solved problem.

## Critique of the (until Oct 2, 2016) accepted answer

The first paragraph is half short explanation, half predictive. Here's the only part that actually answers the question

> The proper use of **slots** is to save space in objects. Instead of having a dynamic dict that allows adding attributes to objects at anytime, there is a static structure which does not allow additions after creation. This saves the overhead of one dict for every object that uses slots

The second half is wishful thinking, and off the mark:

> While this is sometimes a useful optimization, it would be completely unnecessary if the Python interpreter was dynamic enough so that it would only require the dict when there actually were additions to the object.

Python actually does something similar to this, only creating the `__dict__` when it is accessed, but creating lots of objects with no data is fairly ridiculous.

The second paragraph oversimplifies and misses actual reasons to avoid `__slots__`. The below is *not* a real reason to avoid slots (for *actual* reasons, see the rest of my answer above.):

> They change the behavior of the objects that have slots in a way that can be abused by control freaks and static typing weenies.

It then goes on to discuss other ways of accomplishing that perverse goal with Python, not discussing anything to do with `__slots__`.

The third paragraph is more wishful thinking. Together it is mostly off-the-mark content that the answerer didn't even author and contributes to ammunition for critics of the site.

---

## **Memory usage evidence**

Create some normal objects and slotted objects:

```pyhthon
>>> class Foo(object): pass
>>> class Bar(object): __slots__ = ()

```

Instantiate a million of them:

```pyhthon
>>> foos = [Foo() for f in xrange(1000000)]
>>> bars = [Bar() for b in xrange(1000000)]

```

Inspect with `guppy.hpy().heap()`:

```pyhthon
>>> guppy.hpy().heap()
Partition of a set of 2028259 objects. Total size = 99763360 bytes.
 Index  Count   %     Size   % Cumulative  % Kind (class / dict of class)
     0 1000000  49 64000000  64  64000000  64 __main__.Foo
     1     169   0 16281480  16  80281480  80 list
     2 1000000  49 16000000  16  96281480  97 __main__.Bar
     3   12284   1   987472   1  97268952  97 str
...

```

Access the regular objects and their `__dict__` and inspect again:

```pyhthon
>>> for f in foos:
...     f.__dict__
>>> guppy.hpy().heap()
Partition of a set of 3028258 objects. Total size = 379763480 bytes.
 Index  Count   %      Size    % Cumulative  % Kind (class / dict of class)
     0 1000000  33 280000000  74 280000000  74 dict of __main__.Foo
     1 1000000  33  64000000  17 344000000  91 __main__.Foo
     2     169   0  16281480   4 360281480  95 list
     3 1000000  33  16000000   4 376281480  99 __main__.Bar
     4   12284   0    987472   0 377268952  99 str
...

```

This is consistent with the history of Python, from [Unifying types and classes in Python 2.2](https://www.python.org/download/releases/2.2.2/descrintro/)

> If you subclass a built-in type, extra space is automatically added to the instances to accomodate **dict** and **weakrefs**. (The **dict** is not initialized until you use it though, so you shouldn't worry about the space occupied by an empty dictionary for each instance you create.) If you don't need this extra space, you can add the phrase "**slots** = []" to your class.
