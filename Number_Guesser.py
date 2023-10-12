import random

print("YOU HAVE 5 GUESSES TO GUESS THE NUMBER BETWEEN 1 - 100")
num = random.randint(1,100)

flag = 0
for i in range(5):
    guess = int(input("Enter you Guess: "))
    if(guess == num):
        flag = 1
        print("BINGO!!!! YOU USED",i+1,"GUESS")
        break
    elif(guess < num):
        print("YOU GUESSED LOW.....USED",i+1,"GUESS")
    elif(guess > num):
        print("YOU GUESSED HIGH.....USED",i+1,"GUESS")

if(flag != 1):
    print("SORRY....BETTER LUCK NEXT TIME")
    
