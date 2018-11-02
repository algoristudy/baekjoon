a = [1, 2, 3, 4, 5]
b = []
for i in range(4):
    b.append(0)
    for j in range(len(a) - i):
        b[0] = a[j]
        if i == 0:
            print(b)
            continue
        for k in range(j + 1, len(a) - i + 1):
            b[1] = a[k]
            if i == 1:
                print(b)
                continue
            for l in range(k + 1, len(a) - i + 2):
                b[2] = a[l]
                if i == 2:
                    print(b)
                    continue
                for m in range(l + 1, len(a) - i + 3):
                    b[3] = a[m]
                    if i == 3:
                        print(b)