def binaryRep(n):
    liste = []
    while n // 2 != 0:
        remainder = n % 2
        n //= 2
        liste.append(remainder)
    liste.append(n)
    liste.reverse()
    return liste

print("8 : {}".format(binaryRep(8)))
print("13: {}".format(binaryRep(13)))
print("29: {}".format(binaryRep(29)))