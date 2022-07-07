# urllib

## parse

[python doc urllib.parse](https://docs.python.org/3/library/urllib.parse.html)

### urljoin

```python
urljoin('http://localhost:8000', 'path')
urljoin('http://localhost:8000/', 'path')
urljoin('http://localhost:8000/', '/path')
# http://localhost:8000/path
```

#### Read more about `urljoin`

- python3 doc [urljoin](https://docs.python.org/ko/3/library/urllib.parse.html#urllib.parse.urljoin)

### url parameter parsing

[dololak.tistory.com](https://dololak.tistory.com/254)

```python
from urllib.parse import urlparse, parse_qs

some_url = "https://someurl.com/with/query_string?i=main&mode=front&sid=12ab&enc=+Hello"
parsed_url = urlparse(some_url)

print(parsed_url)
# ParseResult(scheme='https', netloc='someurl.com', path='/with/query_string', params='', query='i=main&mode=front&sid=12ab&enc=+Hello', fragment='')

print(parsed_url.path)
# /with/query_string

parsed_query = parse_qs(parsed_url.query)
print(parsed_query)
# {'i': ['main'], 'mode': ['front'], 'sid': ['12ab'], 'enc': [' Hello']}
```

파라미터는 리스트로 반환되기 때문에 파라미터가 여러개인 경우 인덱스로 접근할 수 있다.

> 근데 여러개인 경우가 가능한가?

만약 `dict` 로 반환받고 싶다면 아래의 코드를 이용하자.

```python
from urllib.parse import parse_qsl

dict(parse_qsl('foo=bar&baz=qux'))
# {'foo': 'bar', 'baz': 'qux'}
```

## multiple parameters

[correct-way-to-pass-multiple-values-for-same-parameter-name-in-get-request](https://stackoverflow.com/questions/24059773/correct-way-to-pass-multiple-values-for-same-parameter-name-in-get-request)

## Answer

Indeed, there is no defined standard. To support that information, have a look at wikipedia, in the [Query String](http://en.wikipedia.org/wiki/Query_string) chapter. There is the following comment:

> While there is no definitive standard, most web frameworks allow multiple values to be associated with a single field.[3][4]

Furthermore, when you take a look at the [RFC 3986](http://tools.ietf.org/html/rfc3986), in section [3.4 Query](http://tools.ietf.org/html/rfc3986#section-3.4), there is no definition for parameters with multiple values.

Most applications use the first option you have shown: `http://server/action?id=a&id=b`. To support that information, take a look at this [Stackoverflow link](https://stackoverflow.com/questions/724526/how-to-pass-multiple-parameters-in-a-querystring), and this [MSDN link](<http://msdn.microsoft.com/en-us/library/ms524784(v=vs.90).aspx>) regarding ASP.NET applications, which use the same standard for parameters with multiple values.

However, since you are developing the APIs, I suggest you to do what is the easiest for you, since the caller of the API will not have much trouble creating the query string.
