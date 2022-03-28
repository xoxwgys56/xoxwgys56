from typing import Iterable
from time import time

"""
pure python implementation. without itertools.combination
"""

def combinations(iterable: Iterable, r: int):
    """
    NOTE copied code from https://docs.python.org/3/library/itertools.html#itertools.combinations

    combinations('ABCD', 2) --> AB AC AD BC BD CD
    combinations(range(4), 3) --> 012 013 023 123
    """

    pool = tuple(iterable)
    n = len(pool)

    if r > n:
        print("set of combination can not be greater than it's size.")
        return

    # e.g. [0, 1, 2], [0, 1, 2, 3] ...
    indices = list(range(r))
    yield tuple(pool[i] for i in indices)

    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)


if __name__ == '__main__':
    _start = time()

    for c in combinations('ABSDF', 2):
        print(c)

    print(f'combination took {(time() - _start) * 1000} secs')