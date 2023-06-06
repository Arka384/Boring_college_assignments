
class MyString:
    userInput = ""
    count = {}
    def __init__(self, str):
        self.userInput = str
    def display(self):
        print(self.userInput)
    def isPalindrome(self, str):
        if str == str[::-1]: return True
        else: return False
    def findAllUniquePalindor(self):
        print("Palindrome words are: ")
        words = self.userInput.split(" ")
        for word in words:
            if word in self.count:
                self.count[word] += 1
            else:
                self.count[word] = 1
        
        for i in self.count:
            if self.count[i] == 1:
                if self.isPalindrome(i):
                    print(i)
    

inputString = input("Enter a stirng: ")
#str = MyString("dad mad nayan hooh dad noice madam nayan hello")
str = MyString(inputString)
str.findAllUniquePalindor()
