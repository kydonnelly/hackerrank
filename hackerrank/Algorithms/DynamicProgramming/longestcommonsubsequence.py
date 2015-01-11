# not solved yet. fails the second two test cases :(

class SubsequenceSolver:
	def __init__ (self, sequence1, sequence2, length1, length2):
		self.sequence1 = sequence1
		self.sequence2 = sequence2
		self.length1 = int(length1)
		self.length2 = int(length2)
		self.subsequenceInfo = [[None for x in range(self.length2+1)] for y in range(self.length1+1)]

	def generateSubsequenceRecursive (self, len1, len2):
		if (self.subsequenceInfo[len1][len2] is not None):
			pass
		elif len1 <= 0 or len2 <= 0:
			self.subsequenceInfo[len1][len2] = ''
		elif self.sequence1[len1-1] == self.sequence2[len2-1]:
			self.generateSubsequenceRecursive(len1-1, len2-1)
			self.subsequenceInfo[len1][len2] = self.subsequenceInfo[len1-1][len2-1] + self.sequence1[len1-1]
		else:
			self.generateSubsequenceRecursive(len1, len2-1)
			self.generateSubsequenceRecursive(len1-1, len2)

			option1 = self.subsequenceInfo[len1][len2-1]
			option2 = self.subsequenceInfo[len1-1][len2]
			if len(option1) > len(option2):
				self.subsequenceInfo[len1][len2] = option1
			else:
				self.subsequenceInfo[len1][len2] = option2

	def findLongestSubsequence (self):
		self.generateSubsequenceRecursive(self.length1, self.length2)
		return self.subsequenceInfo[self.length1][self.length2]
		

length1, length2 = raw_input("").split(" ")

firstSequence = raw_input("").split(" ")
secondSequence = raw_input("").split(" ")

solver = SubsequenceSolver(firstSequence, secondSequence, length1, length2)
subsequence = solver.findLongestSubsequence()
print ' '.join(list(subsequence))