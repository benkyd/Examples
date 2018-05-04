int x = input("What number would you like to count to: ")

i = 0

while x <= i:

    for x in range(0, 12):
        x += 1
        print(x)
    
    if x % 10 == 0:
        print("it is divisible by 10")
    else:
        print("it is not divisible by 10")
        
    if x == input2:
        break
