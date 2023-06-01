import re

def isValidNum(phoneNum):
    regex = "^[6-9][0-9]{9}"
    valid = re.search(regex, phoneNum)
    if valid is not None:
        print("This is a Valid phone number")
    else:
        print("This is NOT a Valid phone number")

phoneNum = input("Enter a phone number: ")
isValidNum(phoneNum)

