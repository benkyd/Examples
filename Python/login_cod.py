import getpass
import os
import pickle
import time

nope = "I didn't quite get that. Mind trying again?"
yn = {'y': True, 'n': False}

if os.path.exists('players'):
    with open('players', 'rb') as f:
        if os.stat('players').st_size == 0:
            accounts = {}
        else:
            accounts = pickle.loads(f.read())
else:
    f = open('players', 'wb')
    f.close()
    accounts = {}

class Player(object):

    def __init__(self):
        self.name = ""
        self.email = ""
        self.password = ""
        self.age = ""
        self.gender = ""

    def write(self):
        accounts[p.name] = [p.email, p.password, p.age, p.gender]
        with open('players', 'wb') as f:
            pickle.dump(accounts, f)

p = Player()

def askChoices(question, options, errorMessage):
    while True:
        answer = str(input(question)).lower()
        if answer in options:
            return options[answer]
        else:
            print(errorMessage)

def register():

    print("\nWelcome, new player!")

    while True:
        p.name = input("What is your name? ")
        if p.name in accounts:
            print("Name already taken. Please try again.")
        else:
            break

    isEmailValid = False
    while not isEmailValid:
        p.email = str(input("What is your email address? "))
        if '@' in p.email and '.' in p.email:
            isEmailValid == True
            break
        else:
            print(nope, "(Input must contain '@' and '.')")

    p.password = getpass.getpass('Please enter a password. ')

    while True:
        try:
            p.age = int(input("How old are you? "))
            break
        except ValueError:
            print(nope, "(Input must be an integer)")

    p.gender = askChoices("What gender are you? ('m' for male, 'f' for female, 'o' for other) ", # it was not my idea to add the 'other' option
                          {'m': "Male", 'f': "Female", 'o': "Other"},
                          nope)

    print("\nName:", p.name,
          "\nEmail:", p.email,
          "\nPassword:", ('*' * len(p.password)),
          "\nAge:", p.age,
          "\nGender:", p.gender)

    correct = askChoices("Is this information correct? (y/n) ",
                         yn, nope)

    if correct:
        print("\nRegistration successful!")
        p.write()
        login()
    elif not correct:
        tryAgain = askChoices("\nWould you like to try again? (y/n) ",
                              yn, nope)
        if tryAgain:
            register()
        else:
            main()

def login():
    while True:
        name = input("What is your player name? ")
        if name in accounts:
            pw = getpass.getpass("Please enter your password. ")
            if pw == accounts[name][1]:
                print(accounts[name]) # debug placeholder until quiz functionality is added
                break
        else:
            print("Account not found.")
            registerNew = askChoices("Would you like to register a new account? (y/n) ",
                                     yn, nope)
            if registerNew:
                register()
                break
            else:
                pass

def main():
    if os.stat('players').st_size == 0:
        register()
    else:
        player = askChoices("Would you like to REGISTER or LOG IN? ",
                            {'register': True, 'log in': False, 'login': False},
                            nope)
        if player:
            register()
        else:
            login()
    print("\nShutting down...")
    time.sleep(3)

if __name__ == '__main__':
    main()
