pairSizes = [2, 4 ,8]
for pairSize in pairSizes:
    print("###### pair size 4 ########")
    level = int(pairSize / 2)
    for i in range(4):
        first = level * ( 2 * i + 1) - 1 
        second = first + level
        print("first:", first, " second:", second)
