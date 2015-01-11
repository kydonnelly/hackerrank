### Reused from longestcommonsubsequence.py (not solved yet)
### I/O format is really the only thing that changes.

# this is getting a runtime error on two cases :(

class SubsequenceSolver:
	def __init__ (self, sequence1, sequence2):
		self.sequence1 = sequence1
		self.sequence2 = sequence2
		self.length1 = len(sequence1)
		self.length2 = len(sequence2)
		self.subsequenceInfo = [[None for x in range(self.length2+1)] for y in range(self.length1+1)]

	def generateSubsequenceRecursive (self, len1, len2):
		if (self.subsequenceInfo[len1][len2] is not None):
			return
		
		if len1 <= 0 or len2 <= 0:
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

firstSequence = raw_input("")
secondSequence = raw_input("")

solver = SubsequenceSolver(firstSequence, secondSequence)
print len(solver.findLongestSubsequence())