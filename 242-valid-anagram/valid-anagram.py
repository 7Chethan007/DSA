

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        myFreq = defaultdict(int)

        # Build frequency map for s
        for c in s:
            myFreq[c] += 1

        # Decrease frequency based on characters in t
        for c in t:
            if c not in myFreq:
                return False
            myFreq[c] -= 1

        # Check if all frequencies are zero
        for count in myFreq.values():
            if count != 0:
                return False

        return True
