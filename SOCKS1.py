# Author: Chaudhary Hamdan
# Github: https://www.github.com/hamdan-codes/

a, b, c = input().split()

ans = "NO"

if a == b or a == c or b == c:
    ans = "YES"
    
print(ans)
