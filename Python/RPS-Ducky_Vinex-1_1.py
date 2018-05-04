import time
import sys
from random import randint

print('Rock Paper Scissors by Ducky and Vinex', '\t')
print('Beta 1.0.2')
print("\t")

win = True
computer_score = 0
user_score = 0
while True:
    userinput = input('Rock(r), Paper(p), Scissors(s), Lizard(l), Spock(k)?: ').lower()
    if (userinput == "r" or userinput == "rock"):
        print('You choose Rock!')
        userinput = "rock"
    elif (userinput == "p" or userinput == "paper"):
        print('You choose Paper!')
        userinput = "paper"
    elif (userinput == "s" or userinput == "scissors"):
        print('You choose Scissors!')
        userinput = "scissors"
    elif (userinput == "l" or userinput == "lizard"):
        print('You choose Lizard!')
        userinput = "lizard"
    elif (userinput == "k" or userinput == "spock"):
        print('You choose Spock!')
        userinput = "spock"
    else:
        print('That was not a valid answer, are sure you are playing the right game?')
        continue
    # --------------------------------------------------------------------------------------
    print('---Computer is thinking---', '\t')
    time.sleep(.5)
    computerinput = randint(1, 5)
    # --------------------------------------------------------------------------------------
    if (computerinput == 1):
        print('Computer chose Rock!')
        computerinput = "rock"
    elif (computerinput == 2):
        print('Computer chose Paper!')
        computerinput = "paper"
    elif (computerinput == 3):
        print('Computer chose Scissors!')
        computerinput = "scissors"
    elif (computerinput == 4):
        print('Computer chose Lizard!')
        computerinput = "lizard"
    elif (computerinput == 5):
        print('Computer chose Spock!')
        computerinput = "spock"
    else:
        print('A fatal error has occurred during the computer phase')
    # --------------------------------------------------------------------------------------
    if (userinput == computerinput):
        print('It\'s a draw!' "\t")
        print('Computer: ', computer_score, ' to ', 'User: ', user_score)
        print("\t")
        continue
    
    elif (userinput == "rock" and computerinput == "paper"):
        win = False
    elif (userinput == "rock" and computerinput == "spock"):
        win = False
    elif (userinput == "paper" and computerinput == "scissors"):
        win = False
    elif (userinput == "paper" and computerinput == "lizard"):
        win = False
    elif (userinput == "scissors" and computerinput == "rock"):
        win = False
    elif (userinput == "scissors" and computerinput == "spock"):
        win = False
    elif (userinput == "lizard" and computerinput == "rock"):
        win = False
    elif (userinput == "lizard" and computerinput == "scissors"):
        win = False
    elif (userinput == "spock" and computerinput == "rock"):
        win = False
    elif (userinput == "spock" and computerinput == "lizard"):
        win = False

    elif (userinput == "rock" and computerinput == "scissors"):
        win = True
    elif (userinput == "rock" and computerinput == "lizard"):
        win = True
    elif (userinput == "paper" and computerinput == "rock"):
        win = True
    elif (userinput == "paper" and computerinput == "spock"):
        win = True
    elif (userinput == "scissors" and computerinput == "paper"):
        win = True
    elif (userinput == "scissors" and computerinput == "lizard"):
        win = True
    elif (userinput == "lizard" and computerinput == "paper"):
        win = True
    elif (userinput == "lizard" and computerinput == "spock"):
        win = True
    elif (userinput == "spock" and computerinput == "rock"):
        win = True
    elif (userinput == "spock" and computerinput == "scissors"):
        win = True
    else:
        print('A fatal error has occurred juring the last phase')
    # --------------------------------------------------------------------------------------
    if win == False:
        print('Computer Wins!')
        computer_score += 1
        print('The scores are: Computer: ', computer_score, ' to ', 'User: ', user_score)
        print ("\t")
    elif win == True:
        print('User Wins!')
        user_score += 1
        print('The scores are: Computer: ', computer_score, ' to ', 'User: ', user_score)
        print ("\t")
    else:
        print('Error Posting Scores')
        # --------------------------------------------------------------------------------------
    continue
