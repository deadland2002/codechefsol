for _ in range(int(input())):
    n = int(input())
    top, bottom = n//2, (n+1)//2
    print(max(0, top-1 + 2*(bottom-1)))