for _ in range(int(input())):
	n, m, k = map(int, input().split())
	grid = [ [0 for i in range(m+1) ] ]
	for i in range(1, n+1): grid.append([0] + list(map(int, input().split())))
	
	pref = [ [0 for i in range(m+1)] for j in range(n+1)]
	for i in range(1, n+1):
		for j in range(1, m+1):
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + grid[i][j]
	if pref[n][m] <= k:
		print(-1)
		continue
	
	def getsum(l1, r1, l2, r2):
		return pref[l2][r2] - pref[l1-1][r2] - pref[l2][r1-1] + pref[l1-1][r1-1]
	
	lo, hi = -1, n+m+1
	while lo+1 < hi:
		mid = (lo + hi)//2
		mxsum = 0
		for i in range(1, n+1):
			for j in range(1, m+1):
				if grid[i][j] == 0: continue
				l1 = max(1, i-mid)
				l2 = min(n, i+mid)
				r1 = max(1, j-mid)
				r2 = min(m, j+mid)
				mxsum = max(mxsum, getsum(l1, r1, l2, r2))
		if mxsum <= k: lo = mid
		else: hi = mid
	print(hi)