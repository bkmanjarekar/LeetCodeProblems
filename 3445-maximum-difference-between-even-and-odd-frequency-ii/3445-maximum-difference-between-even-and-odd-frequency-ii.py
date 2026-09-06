class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        def _status(a: int, b: int) -> int:
            return ((a & 1) << 1) | (b & 1)
        n = len(s)
        ans = float('-inf')
        for ca in '01234':
            for cb in '01234':
                if ca == cb:
                    continue
                best = [float('inf')] * 4
                cnt_a = cnt_b = prev_a = prev_b = 0
                left = -1
                for right, ch in enumerate(s):
                    if ch == ca: cnt_a += 1
                    if ch == cb: cnt_b += 1
                    while right - left >= k and (cnt_b - prev_b) >= 2:
                        st = _status(prev_a, prev_b)
                        best[st] = min(best[st], prev_a - prev_b)
                        left += 1
                        if s[left] == ca: prev_a += 1
                        if s[left] == cb: prev_b += 1
                    st = _status(cnt_a, cnt_b)
                    if best[st ^ 2] < float('inf'):
                        diff = cnt_a - cnt_b - best[st ^ 2]
                        if diff > ans:
                            ans = diff
        return ans if ans != float('-inf') else -1
 