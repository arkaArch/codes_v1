import random

secret_num = random.randint(1, 20)
print("Guess a number between 1 and 20")

# Ask the player to guess 6 times
for guesses_taken in range(1, 7):
    print("Take a guess")
    guess = int(input())

    if guess < secret_num:
        print('Your guess is too low')
    elif guess > secret_num:
        print('Your guess is too high')
    else:
        break   # For correct guess
    
if guess == secret_num:
    print('Good job! You guessed the number in ' + str(guesses_taken) + ' guesses.')
else:
    print('Nope! The secret number was ' + str(secret_num))
