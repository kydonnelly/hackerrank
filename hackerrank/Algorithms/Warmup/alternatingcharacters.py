numTestCases = int(raw_input(""))

for testCase in range(numTestCases):
	inputString = raw_input("")
	numConsecutiveCharacters = 0
	for i in range(1, len(inputString)):
		if (inputString[i] == inputString[i-1]):
			numConsecutiveCharacters += 1

	print numConsecutiveCharacters