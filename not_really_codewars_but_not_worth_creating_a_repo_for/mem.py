import random

n = 100000

arr = list(range(n))

arr[1] = 0

random.shuffle(arr)

i = 0
while i < n:
    this = arr[i]
    that = arr[this]

    # if that index already has this number and im not looking at myself, duplicate
    if i != this and this == that:
        print("Duplicate found")
        exit()

    # swap
    arr[this] = this
    arr[i] = that

    # if this index has the correct number go next
    if i == arr[i]:
        i+=1

print("Duplicate not found")