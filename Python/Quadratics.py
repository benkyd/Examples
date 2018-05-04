from cmath import sqrt

a = ''
b = ''
c = ''

success = False

while success == False:
    try:
        a = float(input("a: "))
        success = True
    except:
        print("That is not a number")

success = False

while success == False:
    try:
        b = float(input("b: "))
        success = True
    except:
        print("That is not a number")

success = False

while success == False:
    try:
        c = float(input("c: "))
        success = True
    except:
        print("That is not a number")

bn = -b
s1 = b ** 2
s2 = 4 * a * c
discriminant = sqrt(s1 - s2)

dinom = 2 * a

if discriminant == 0:
    neum = bn + discriminant
    root = neum1 / dinom
    root = root.real

    print("Root: ", root)
else:
    neum1 = bn - discriminant
    neum2 = bn + discriminant

    root1 = neum1 / dinom
    root2 = neum2 / dinom
    root1 = root1.real
    root2 = root2.real

    print("Root 1: ", root1)
    print("Root 2: ", root2)


