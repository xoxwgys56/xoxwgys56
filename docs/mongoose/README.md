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

## field include "string"

use `$regex` keyword.

```ts
db.users.findOne({ username: { $regex: "son" } });
```

read more about [checking-if-a-field-contains-a-string](https://stackoverflow.com/questions/10610131/checking-if-a-field-contains-a-string)

## operators

### or

_or_ must include array

```typescript
db.inventory.find({ $or: [{ quantity: { $lt: 20 } }, { price: 10 }] });
```

read more about [or](https://www.mongodb.com/docs/manual/reference/operator/query/or/)

### and

_and_ must include array

```typescript
db.example.find({
  $and: [{ x: { $ne: 0 } }, { $expr: { $eq: [{ $divide: [1, "$x"] }, 3] } }],
});
```

read more about [and](https://www.mongodb.com/docs/manual/reference/operator/query/and/)

## 📕 Model

### save model instance

`.save` and `.findByIdAndUpdate` are same.

> The main difference is that when you use `findById` and `save`, you first get the object from MongoDB and then update whatever you want to and then save. This is ok when you don't need to worry about parallelism or multiple queries to the same object.

```typescript
// use .save
const docInstance = await Document.findById(id);
docInstance.field = newValue;
docInstance.save();
// use .findByIdAndUpdate
Document.findByIdAndUpdate({ _id: id }, { field: newValue });
```

read more about [using-save-vs-findbyidandupdate-for-removing-item-from-array](https://stackoverflow.com/questions/54308553/using-save-vs-findbyidandupdate-for-removing-item-from-array)
