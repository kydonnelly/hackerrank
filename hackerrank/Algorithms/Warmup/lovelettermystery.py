numTestCases = int(raw_input(""))
ordA = ord('a')

for testCase in range(numTestCases):
	inputString = raw_input("")
	inputLength = len(inputString)
	charSum = 0

	for i in range(inputLength / 2):
		charSum += abs(ord(inputString[i]) - ord(inputString[inputLength - i - 1]))

	print charSum