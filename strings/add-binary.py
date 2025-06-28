class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        result = ""

        while i >= 0 or j >= 0 or carry:
            digit1 = 0 if i < 0 else int(a[i])
            digit2 = 0 if j < 0 else int(b[j])

            total = digit1 + digit2 + carry
            carry = total // 2

            result = str(total % 2) + result
            i -= 1
            j -= 1
        
        return result
