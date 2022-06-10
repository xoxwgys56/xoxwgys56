# mongoose

## find all

```js
const User = mongoose.model(
  "User",
  Schema({
    name: String,
    email: String,
  })
);

// Empty `filter` means "match all documents"
const filter = {};
const all = await User.find(filter);
```

read more about [mongoose/find-all](https://masteringjs.io/tutorials/mongoose/find-all)
