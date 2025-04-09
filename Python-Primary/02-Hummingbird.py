while True:
    print('Who are you?')
    name = input()
    # Let's say that the user is me
    if name != 'Arka':
        print("User doesn't exist")
        continue
    print("Hello, Arka. What is the password?")
    password = input()
    if password == "hummingbird":
        break
    print("Sorry, you've entered wrong password. (It's a bird)")
print("Access granted.")
