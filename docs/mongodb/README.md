# MongoDB

## condition

### and

`and` must assgin array property

```mongodb
{
    $and: [{field: value}, {field: value}]
}
```

### or

`or` just same work like **and**

```mongodb
{
    $or: [{field: value}, {field: value}]
}
```

### like

```mongodb
{
    field: /keyword/i
}
```

in typescript use like below:

```ts
const regex = new RegExp([keyword].join(''), 'i')
```

#### include string

```ts
const regex = new RegExp(['(', keyword, ')'].join(''), 'i')
```

### $in

```mongodb
{ 
    field: { $in: [value1, value2, ... valueN ] } 
}
```

### Read more about condition

- stackoverflow [using-and-with-match-in-mongodb](https://stackoverflow.com/questions/20469712/using-and-with-match-in-mongodb)
- stackoverflow [how-to-query-mongodb-with-like](https://stackoverflow.com/questions/3305561/how-to-query-mongodb-with-like)
- stackoverflow [mongodb-is-it-possible-to-make-a-case-insensitive-query#fromHistory](https://stackoverflow.com/questions/1863399/mongodb-is-it-possible-to-make-a-case-insensitive-query#fromHistory)
- mongodb
  - [$in](https://www.mongodb.com/docs/manual/reference/operator/query/in/)

---

## aggregate

### operator

#### split string

```mongodb
{ 
    $split: [ 'string expression', ' ' ]
}
```

it is good to use this operator with `$addField`

##### Read more about operator

- [$split](https://www.mongodb.com/docs/manual/reference/operator/aggregation/split/)


### group

below aggregate remove duplicates by doc's *_id*

```mongodb
{
    _id: '$_id'
}
```

#### Read more about aggregate.group

- [removing-duplicates-in-mongodb-with-aggregate-query](https://stackoverflow.com/questions/39315892/removing-duplicates-in-mongodb-with-aggregate-query)