from sys import maxint

ctoi = lambda c: ord(c) - ord('a')

class LexicographicIncrementer:
	def __init__ (self, inputStr):
		self.string = inputStr
		self.strLength = len(inputStr)

	def indexToShift (self):
		maxChar = 0
		for i in range(self.strLength - 1, -1, -1):
			intValue = ctoi(self.string[i])
			if intValue > maxChar:
				maxChar = intValue
			elif intValue < maxChar:
				return i

		return -1

	def replacementIndex (self, shiftIndex):
		shiftValue = ctoi(self.string[shiftIndex])
		minDiff = maxint
		minIndex = 0

		for i in range(shiftIndex+1, self.strLength):
			diff = ctoi(self.string[i]) - shiftValue
			if diff > 0 and diff < minDiff:
				minDiff = diff
				minIndex = i

		return minIndex

	def solve (self):
		shiftIndex = self.indexToShift()
		if (shiftIndex < 0):
			return "no answer"

		# simulate pop + push
		popIndex = self.replacementIndex(shiftIndex)
		toSort = self.string[shiftIndex : popIndex] + self.string[popIndex+1 : ]
		self.string = self.string[:shiftIndex] + self.string[popIndex] + "".join(sorted(toSort))

		return self.string

numStrings = int(raw_input(""))
for case in range(numStrings):
	incrementer = LexicographicIncrementer(raw_input(""))
	print incrementer.solve()