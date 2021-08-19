def perfect_numbers():
    num = 2
    while True:
        num_sqrt = num ** 0.5
        sum = 1
        for i in range(2, ceil(num_sqrt)):
            if i == num_sqrt:
                sum += i
            elif num % i == 0:
                sum += i + num / i
        
        if sum == num:
            print(num)
        
        num += 1


def pi_approx_integral(iters:int) -> float:
    a = -1
    b = 1

    divisions = []
    for i in range(iters+1):
        divisions.append(i/(iters+1))

    num = 0
    width = divisions[1] * (b-a)
    index = 0
    for division in divisions:
        x = (b-a)*division+a+width/2
        num += (1-x**2)**0.5 * width

        if index % 1000 == 0:
            print(" Calculating... ", index / len(divisions) * 100, "%", end="\r")
            fflush(stdout)
        index += 1
    
    print()

    return 2*num


def quick_sort(arr:int[0]) -> int[0]:
    n = len(arr)
    if n <= 1:
        return arr

    mid = arr[n // 2]

    lower = []
    higher = []
    same:int[0] = []

    for i in arr:
        if i < mid:
            lower.append(i)
        elif i > mid:
            higher.append(i)
        elif i == mid:
            same.append(i)
    

    return quick_sort(lower) + same + quick_sort(higher)


def main():
    print("Pi:")
    print("Pi approximation: %.30f" % pi_approx_integral(2**24))
    # perfect_numbers()

    print()

    print("Array sorting using quick sort:")
    x = [2, 4, 5, 3, 7, 2, 4, 2, 1, 6, 4]
    print("Orinal array:")
    for i in x:
        print(i, end=", ")
    print()

    new_arr = quick_sort(x)
    print("Sorted array:")
    for i in new_arr:
        print(i, end=", ")
    print()

    return 0