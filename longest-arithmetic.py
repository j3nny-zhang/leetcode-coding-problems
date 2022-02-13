# return the computes the length of the longest consectutive arithmetic progression found in arr
# examples:
#   1 2 3 4 5 => 5
#   1 2 3 6 8 10 12 => 4
#   1 2 4 6 8 11 12 13 => 4
#   1 => 1
#   1 3 6 => 2

def longest_arith_prog(arr: List[int]) -> int:
    longest_arith = 1
    common_diff = 0
    temp = 1

    if len(arr) == 1:
        return 1
    else:
        common_diff = arr[1] - arr[0]

    for i in range(len(arr) - 1):
        if arr[i + 1] - arr[i] != common_diff:
            common_diff = arr[i + 1] - arr[i]
            temp = 2
        else:
            temp += 1

        if temp > longest_arith:
            longest_arith = temp

    return longest_arith
