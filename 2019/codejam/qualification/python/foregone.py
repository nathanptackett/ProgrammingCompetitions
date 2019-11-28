num_test_cases = int(input())

for x in range(num_test_cases):
    num_to_fix = input()
    string_length = len(num_to_fix)

    num1 = 0
    num2 = 0
    for y in range(string_length):
        ten_to_the = string_length - y - 1
        if num_to_fix[y] == '4':
            num2 += 2*10**ten_to_the
    num1 = int(num_to_fix) - num2
    print("Case #"+str(x+1)+": "+str(num1)+" "+str(num2))