# javascript

## optional chaining

same work as _typescript_ do.

```js
const adventurer = {
  name: "Alice",
  cat: {
    name: "Dinah",
  },
};

const dogName = adventurer.dog?.name;
console.log(dogName);
// expected output: undefined

console.log(adventurer.someNonExistentMethod?.());
// expected output: undefined
```

read more about [Optional_chaining](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Optional_chaining)

## Get attribute list

use `Object.keys()`.

```js
var keys = Object.keys(myObject);
```

### Read more about get attribute list

- [how-to-list-the-properties-of-a-javascript-object](https://stackoverflow.com/questions/208016/how-to-list-the-properties-of-a-javascript-object)

## Nullish coalescing operator

work like python's `or` operator.

```js
onst foo = null ?? 'default string';
console.log(foo);
// expected output: "default string"
```

### Read more about `??` operator

- [mozilla doc](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Nullish_coalescing_operator)