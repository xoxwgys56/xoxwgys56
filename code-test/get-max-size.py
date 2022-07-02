from typing import List
from itertools import combinations
from pprint import pprint


class Solution:
    @staticmethod
    def maxArea(
        h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]
    ) -> int:
        """
        how to resolve this problem. let me see

        ### 1. find meet-points

        `[1, 2, 4]` and `[1, 3]`
        there are several meet-points are generated.

        ```python
        (1, 1), (1, 3)
        (2, 1), (2, 3)
        (4, 1), (4, 3)
        ```

        then add edge points

        ```python
        (0, 0), (0, 4)
        (5, 0), (5, 4)
        ```

        find meet-points with edge of square

        ```python
        (0, 1), (0, 3)
        (1, 0), (1, 4)
        (2, 0), (2, 4)
        (4, 0), (4, 4)
        (5, 1), (5, 3)
        ```

        reduce all of these points

        ```python
        (0, 0), (0, 1), (0, 3), (0, 4)
        (1, 0), (1, 1), (1, 3), (1, 4)
        (2, 0), (2, 1), (2, 3), (2, 4)
        (4, 0), (4, 1), (4, 3), (4, 4)
        (5, 0), (5, 1), (5, 3), (5, 4)
        ```

        ### 2. create true/false 2d matrix

        ```python
        [
            [1, 1, 0, 1, 1],
            [1, 1, 0, 1, 1],
            [1, 1, 0, 1, 1],
            [0, 0, 0, 0, 0],
            [1, 1, 0, 1, 1],
            [1, 1, 0, 1, 1]
        ]
        ```

        ### 3. then get size of square

            start from `(0, 0)`

            1. find closest x-point
            2. find closest y-point
                - In this, we do not need find x-y point.
                - because we expect there is meet-point every-time.
            3. get size from points

            is there no other way?
        """

        points = []
        # collect across points
        horizontalCuts.extend([0, h])
        verticalCuts.extend([0, w])

        for _h in sorted(horizontalCuts):
            row = []
            for _v in sorted(verticalCuts):
                row.append([_h, _v])
            points.append(row)

        pprint(points)

        max_sum = -1
        for idx, row in enumerate(points):
            for jdx, point in enumerate(row):
                x, y = point[0], point[1]
                try:
                    _x, _y = points[idx + 1][jdx + 1]
                except IndexError:
                    _x, _y = h, w

                _w = _x - x
                _h = _y - y
                if _w * _h > max_sum:
                    print(f"{_w}*{_h} ~ {x}, {y} : {_x}, {_y}")
                    max_sum = _w * _h

        print(f"result is {max_sum}")
        return max_sum


if __name__ == "__main__":
    assert Solution.maxArea(5, 4, [1, 2, 4], [1, 3]) == 4
    assert Solution.maxArea(5, 4, [3, 1], [1]) == 6
    assert Solution.maxArea(5, 4, [3], [3]) == 9

    assert Solution.maxArea(1000000000, 1000000000, [2], [2]) == 81
    """
    1,000,000,000
    1,000,000,000

    wtf
    """
