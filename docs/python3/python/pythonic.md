# Pythonic

## Get *Intersection*

```python
[1, 2, 3] and [1, 2] # [1, 2]

"""
NOTE do not return empty list
"""
[1, 2, 3] and [4] # [4]
[1, 2, 3] and [0] # [0]

 {1, 2, 3} & {1, 2} # {1, 2}
```

### How about `or` operator?

but do not work for `or` operator.  

```python
[1, 2, 3] or [0] # [1, 2, 3]
[] or [1, 2, 3] # [1, 2, 3]
"""
because value [1, 2, 3] is True.
"""
```

## Get *Union*

```python
set([1, 2, 3]) | set([0]) # {0, 1, 2 ,3}

{1, 2, 3} | {0} # {0, 1, 2 ,3}
```