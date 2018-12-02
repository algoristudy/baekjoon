# DP 2011번 문제
def getCount(cipher):
    D = [0] * len(cipher)
    if not '0' < cipher[0] <= '9':
        return 0
    D[0] = 1
    if cipher[1] == '0':
        if cipher[0] != '1' or cipher[0] != '2':
            D[1] = 1
        else:
            return 0
    else:
        D[1] = 2 if cipher[0] == '1' or (cipher[0] == '2' and cipher[1] < '7') else 1
    for i in range(2, len(cipher)):
        if cipher[i] == '0':
            if cipher[i - 1] == '0':
                # 연속으로 0이 나오는 경우 100 이상에 할당되는 알파벳이 없는 것으로 간주
                return 0
            elif cipher[i - 1] == '1' or cipher[i - 1] == '2':
                # 10 or 20일 경우
                diff = D[i - 1] - D[i - 2]
                D[i] = D[i - 1] - diff
        elif '0' < cipher[i] <= '9':
            if cipher[i - 1] == '1' or (cipher[i - 1] == '2' and cipher[i] < '7'):
                if cipher[i - 2] == '1' or cipher[i - 2] == '2':
                    D[i] = D[i - 1] + D[i - 2]
                else:
                    D[i] = D[i - 1] + D[i - 1]
            else:
                D[i] = D[i - 1]
        else:
            return 0 
    # print(D)
    return(D[len(cipher) - 1] % 1000000)
    
    

if __name__=='__main__':
    with open('../input.txt', 'r') as f:
        cipher = f.readline()
        print(getCount(cipher))
                    