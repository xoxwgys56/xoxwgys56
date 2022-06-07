# ES

> in this document we suppose ES running on `localhost` and use `9200` port.

## GET

### index

get all indices

```curl
GET localhost:9200/_cat/indices
```

### GET API

Get first document

read more about [docs-get](https://www.elastic.co/guide/en/elasticsearch/reference/current/docs-get.html)

```curl
GET localhost:9200/index-name/_doc/0
```

Get document count.

read more about [search-count](https://www.elastic.co/guide/en/elasticsearch/reference/current/search-count.html)

```curl
GET localhost:9200/index-name/_count
```
