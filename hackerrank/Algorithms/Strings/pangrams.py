def isPangram (sentence):
	letterMap = dict()
	# assume spaces are the only non characters.
	for c in sentence.replace(" ", "").lower():
		letterMap[c] = 1
	return len(letterMap) >= 26

sentence = raw_input("")
if isPangram(sentence):
	print "pangram"
else:
	print "not pangram"