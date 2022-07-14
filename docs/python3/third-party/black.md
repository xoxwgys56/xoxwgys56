# Black

formatter

## vscode setting

```json
{
    // "python.defaultInterpreterPath": "<project-path>/venv/bin/python3",
    // "python.formatting.blackPath": "<project-path>/venv/bin/black",
    "python.formatting.provider": "black",
    "editor.formatOnSave": true,
    "python.formatting.blackArgs": [
        "--skip-string-normalization",
        "--line-length",
        "900"
    ]
}
```

## Example `pyproject.toml`

see [here](https://github.com/psf/black/blob/main/pyproject.toml)

## Ignore formatting

start with `fmt: off` and end with `fmt: on`.   
if do not `fmt: on` again, formatting does not work.

```python
# fmt: off
np.array(
    [
        [1, 0, 0, 0],
        [0, -1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, -1],
    ]
)
# fmt: on
```

### Read more about ignore-formatting

- stackoverflow [black-formatter-ignore-specific-multi-line-code](https://stackoverflow.com/a/58584557/11082758)