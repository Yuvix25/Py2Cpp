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
            print(" ", index / len(divisions) * 100, "%", end="\r")
            fflush(stdout)
        index += 1
    
    print()

    return 2*num


def main():
    print("%.30f" % pi_approx_integral(2**24))
    # perfect_numbers()

    return 0