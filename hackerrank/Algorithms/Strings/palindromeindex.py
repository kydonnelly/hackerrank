def isPalindrome (palindrome):
	stack = []
	strLength = len(palindrome)
	stackSize = strLength / 2
	for i in range(stackSize):
		stack.append(palindrome[i])
	for i in range(-1, stackSize - strLength, -1):
		if (stack[0] != palindrome[i]):
			return False
		stack.pop(0)

	return True

def palindromeRemovalIndex (palindrome):
	strLength = len(palindrome)
	rightIter = strLength
	for leftIter in range(int(strLength/2)):
		rightIter -= 1
		leftChar = palindrome[leftIter]
		rightChar = palindrome[rightIter]

		if leftChar != rightChar:
			if isPalindrome(palindrome[leftIter+1 : rightIter+1]):
				return leftIter
			elif isPalindrome(palindrome[leftIter : rightIter]):
				return rightIter
				
	return -1

numTestCases = int(raw_input(""))

for case in range(numTestCases):
	print palindromeRemovalIndex(raw_input(""))