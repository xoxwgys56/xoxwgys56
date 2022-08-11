# git-diff

## compare with other repo

```shell
# add remote repo
git remote add -f b path/to/repo_b.git
git remote update

# diff with remote repo
git diff master remotes/b/master
git remote rm b
```

### compare with specific commit

```shell
# diff with specific commit
git diff COMMIT
# include specific commit only
git diff COMMIT^!
```

### More read about compare-with-other-repo

- [getting-the-difference-between-two-repositories](https://stackoverflow.com/a/1968538/11082758)
- [how-can-i-see-the-changes-in-a-git-commit](https://stackoverflow.com/a/17563864/11082758)