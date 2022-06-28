# Type

## get type

```ts
const anExampleVariable = "Hello World"

typeof var // string
```

## casting

use `as` keyword to casting type.

```ts
function foo() {
    const jsonObject = response.json() as Object;
    const fooInstance = plainToClass(Models.Foo, jsonObject);
    
    return {
        foo: fooInstance
    } as ReturnType;
}
```

### read more about casting

- stackoverflow answer[use `as`](https://stackoverflow.com/a/40042282/11082758)
