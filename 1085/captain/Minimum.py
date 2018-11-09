def getCount(x, y, w, h):
    min = y
    if h - y < min:
        min = h - y
    if x < min:
        min = x
    if w - x < min:
        min = w - x
    return min

if __name__=='__main__':
    x, y, w, h = map(int, input().strip().split(' '))
    print(getCount(x, y, w, h))
    