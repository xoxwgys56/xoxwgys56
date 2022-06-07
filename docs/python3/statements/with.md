# `with`

## with catch

[catching-an-exception-while-using-a-python-with-statement](https://stackoverflow.com/questions/713794/catching-an-exception-while-using-a-python-with-statement)

`with`문에서 발생하는 예외를 잡고 싶다면 일반적으로 아래와 같이 작성하면 된다.

```python
from __future__ import with_statement


try:
    with open( "a.txt" ) as f :
        print f.readlines()
except EnvironmentError: # parent of IOError, OSError *and* WindowsError where available
    print 'oops'
```

위의 코드는 나쁜 코드가 아니지만 `with`문이 `try`문 내에 있으면서 한개의 뎁스가 생겼다.
만약 위의 코드와 다르게 `open` 호출에서 예외를 처리하고 싶다면 아래처럼 코드를 작성할 수 있다:

```python
try:
    f = open('foo.txt')
except IOError:
    print('error')
else:
    with f:
        print f.readlines()
```

### NOTE

참고로 아래와 같은 구문은 없다.

```python
with open("a.txt") as f:
    print(f.readline())
except IOError as err:
    print(err)
```
