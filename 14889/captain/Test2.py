a = [1, 2, 3, 4]

for i in range(len(a) - 1):
    for j in range(i + 1, len(a)):
        print('a[0] : ', a[i], 'a[1] : ', a[j])