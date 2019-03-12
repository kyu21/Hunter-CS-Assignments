def rle_decode(arr):
    decode = ''
    for x in range(1, len(arr)):
        if isinstance(arr[x], str):
            if isinstance(arr[x - 1], int):
                decode += arr[x] * arr[x - 1]
            else:
                decode += arr[x]
    return decode


print(rle_decode([2, 'a', 3, 'b', 'c', 2, 'd']))
