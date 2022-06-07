# RxPy

source: [hamait.tistory.com](https://hamait.tistory.com/886?category=79136)

```python
from rx import Observable, Observer


def push_hello_world(observer):
    observer.on_next("hello")
    observer.on_next("world")
    #observer.on_error("error")
    observer.on_completed()


class PrintObserver(Observer):
    def on_next(self, value):
        print("Received {0}".format(value))

    def on_completed(self):
        print("Done!")

    def on_error(self, error):
        print("Error Occurred: {0}".format(error))


if __name__ == '__main__':
    source = Observable.create(push_hello_world)
    source.subscribe(PrintObserver())
```
