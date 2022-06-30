## Exit nested loop

```python
for i in range(5000):
    for j in range(3000):
        if j > 1000:
           break
    else: 
        continue # no break encountered
    break
```

## More read

- [wikidocs](https://wikidocs.net/12172)