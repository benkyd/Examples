import random

target = 'Hello World!'
testString = ''

while testString != target:
    testString = ''
    for i in range(12):
        testString += chr(random.randint(32, 126))
    print(testString)

print(testString)
