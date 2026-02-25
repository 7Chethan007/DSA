class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for c in s:
            # Push opening brackets
            if c in "({[":
                stack.append(c)
            else:
                # No opening bracket to match
                # Checks whether the stack is empty before trying to remove (pop) an element from it.
                if len(stack) == 0:
                    return False
                
                top = stack.pop()
                
                # Check matching pairs
                if (c == ')' and top != '(') or \
                   (c == '}' and top != '{') or \
                   (c == ']' and top != '['):
                    return False
        
        # Valid only if no unmatched brackets remain
        return len(stack) == 0