# git

## push ignore pre-commit

add `--no-verify` flag.

```shell
git commit --no-verify -m "commit message"
           ^^^^^^^^^^^
-n
--no-verify
```

read more about [skip-git-commit-hooks](https://stackoverflow.com/questions/7230820/skip-git-commit-hooks)

## HEAD

- [how-can-i-move-head-back-to-a-previous-location-detached-head-undo-commits](https://stackoverflow.com/questions/34519665/how-can-i-move-head-back-to-a-previous-location-detached-head-undo-commits)

## subtree

### get subtree list

there is no explicit way to do.

```shell
git log | grep git-subtree-dir | tr -d ' ' | cut -d ":" -f2 | sort | uniq
```

### Read more about subtree

- github repo [git-subtree](https://github.com/apenwarr/git-subtree)
- stackoverflow
  - [detach-move-subdirectory-into-separate-git-repository](https://stackoverflow.com/questions/359424/detach-move-subdirectory-into-separate-git-repository/17864475#17864475)
  - [when-to-use-git-subtree](https://stackoverflow.com/questions/32407634/when-to-use-git-subtree/33579069#33579069)
  - [git-subtree-only-one-file-or-directory](https://stackoverflow.com/questions/22334382/git-subtree-only-one-file-or-directory)
  - [how-can-i-list-the-git-subtrees-on-the-root](https://stackoverflow.com/a/18339297/11082758)
- medium [mastering-git-subtrees](https://medium.com/@porteneuve/mastering-git-subtrees-943d29a798ec)
- gist.SKempin [Git Subtree Basics](https://gist.github.com/SKempin/b7857a6ff6bddb05717cc17a44091202)
- atlassian [git-subtree](https://www.atlassian.com/git/tutorials/git-subtree)