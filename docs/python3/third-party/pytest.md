# Pytest

## Test specific script

use `-k` option

```shell
pytest tests_directory/foo.py -k 'test_001 or test_some_other_test'
```

### Read more about test-specific

- stackoverflow [is-there-a-way-to-specify-which-pytest-tests-to-run-from-a-file](https://stackoverflow.com/a/36539692/11082758)
- pytest [using-k-expr-to-select-tests-based-on-their-name](https://docs.pytest.org/en/latest/example/markers.html#using-k-expr-to-select-tests-based-on-their-name)