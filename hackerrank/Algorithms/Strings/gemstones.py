class GemElementFinder:
	ordA = ord('a')

	def __init__ (self):
		self.currentRockId = 0
		self.rockMatrix = [None] * 26

	def addRock (self, rockDescription):
		self.currentRockId += 1

		for element in rockDescription:
			index = ord(element) - self.ordA
			if self.rockMatrix[index] is None:
				self.rockMatrix[index] = dict()
			self.rockMatrix[index][self.currentRockId] = 1

	def allGemCount (self):
		numGems = 0
		for rockMap in (elem for elem in self.rockMatrix if elem is not None):
			if len(rockMap) == self.currentRockId:
				numGems += 1

		return numGems

numRocks = int(raw_input(""))
finder = GemElementFinder()

for rockIter in range(numRocks):
	rock = raw_input("")
	finder.addRock(rock)

print finder.allGemCount()