# error handling

use `try-except`

```python
try:
  f = open(“test.txt", 'r')
  data = f.read()
  print("Trying")
except:
  print("Fiddlesticks! Failed")
finally:
  print("Finally!")
  print("All Done")
```

## catch multiple exceptions

```python
except (KeyError, IndexError):
```

### Best practice

To do this in a manner currently and forward compatible with Python, you need to separate the Exceptions with commas and wrap them with parentheses to differentiate from earlier syntax that assigned the exception instance to a variable name by following the Exception type to be caught with a comma.

Here's an example of simple usage:

```python
import sys


try:
    mainstuff()
except (KeyboardInterrupt, EOFError): # the parens are necessary
    sys.exit(0)
```

I'm specifying only these exceptions to avoid hiding bugs, which if I encounter I expect the full stack trace from.

if not, just raise exception!

## inside of `constructor`

만약에 객체를 생성하는 중에 오류가 발생. (올바른 파라미터가 주어지지 않아서라면) 어떻게 핸들링해야할까?

stackoverflow 답변에서는 Parameter exception 경우, `ValueError` 를 발생시키라고 조언한다 (매우 동의한다고). 자세한 내용은 아래의 [Read more](#read-more) 참조

---

## Read more

- python doc [errors](https://docs.python.org/ko/3/tutorial/errors.html)
- [error-handling-in-python-using-with-and-try](https://www.idkrtm.com/error-handling-in-python-using-with-and-try/)
- catch multiple exception
  - [catch-multiple-exceptions-in-one-line-except-block](https://stackoverflow.com/questions/6470428/catch-multiple-exceptions-in-one-line-except-block)
- raise exception inside of constructor
  - [python-is-it-bad-form-to-raise-exceptions-within-init](https://stackoverflow.com/questions/1507082/python-is-it-bad-form-to-raise-exceptions-within-init)
  - [handle-exception-in-init](https://stackoverflow.com/questions/20059766/handle-exception-in-init/20060037)
