# all, any

굳이 `defaultdict` 를 쓰지 않아도 된다. 까먹을까봐 한번 써본 것.

```python
from collections import defaultdict

int_dict = defaultdict(int)
>>> any(int_dict)
False

int_dict[0] = 'zero'
int_dict['1'] = 1
int_dict[1] = False

>>> any(int_dict)
True
>>> all(int_dict)
False
```

`any` 는 말그대로 무엇이라도 하나 참인 멤버가 있으면 `True` 인 것이고, `all` 은 말그대로 모두 참이어야 `True` 인 것이다.

아래와 같은 경우 사용하기 좋을 것 같다.

```python
class MyClass:
    is_true: bool

    def __init__(self, is_true: bool):
        self.is_true = is_true

    # 각 클래스에서 필요에 따라 override해주었다고 가정했다.
    def __bool__(self) -> bool:
        return self.is_true

class_list = [MyClass(bool(i % 2)) for i in range(10)]

>>> any(class_list)
True
>>> all(class_list)
False
```

활용도가 있는 함수이지만 어떤 곳에서 활용해야할지 잘모르겠다.

---

## References

- all and any
  - [blockdmask.tistory.com/430](https://blockdmask.tistory.com/430)
- defaultdict
  - [dongdongfather.tistory.com](https://dongdongfather.tistory.com/69)
