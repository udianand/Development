#!/usr/bin/python -tt
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

"""Wordcount exercise
Google's Python class

The main() below is already defined and complete. It calls print_words()
and print_top() functions which you write.

1. For the --count flag, implement a print_words(filename) function that counts
how often each word appears in the text and prints:
word1 count1
word2 count2
...

Print the above list in order sorted by word (python will sort punctuation to
come before letters -- that's fine). Store all the words as lowercase,
so 'The' and 'the' count as the same word.

2. For the --topcount flag, implement a print_top(filename) which is similar
to print_words() but which prints just the top 20 most common words sorted
so the most common word is first, then the next most common, and so on.

Use str.split() (no arguments) to split on all whitespace.

Workflow: don't build the whole program at once. Get it to an intermediate
milestone and print your data structure and sys.exit(0).
When that's working, try for the next milestone.

Optional: define a helper function to avoid code duplication inside
print_words() and print_top().

"""

import sys
# <--- NOTE (start) --->
# For testing use file "Alice.txt" located in dir Basic Exercises.
# <--- NOTE (end) --->

# +++your code here+++
# Define print_words(filename) and print_top(filename) functions.
# You could write a helper utility function that reads a file
# and builds and returns a word/count dict for it.
# Then print_words() and print_top() can just call the utility function.

###

# This basic command line argument parsing code is provided and
# calls the print_words() and print_top() functions which you must define.
def main():
  if len(sys.argv) != 3:
    print 'usage: ./wordcount.py {--count | --topcount} file'
    sys.exit(1)

  option = sys.argv[1]
  filename = sys.argv[2]
  if option == '--count':
    print_words(filename)
  elif option == '--topcount':
    print_top(filename)
  else:
    print 'unknown option: ' + option
    sys.exit(1)
    
    
# Utility function to count the number of words in a file.    
def word_count(filename):
	
	# A dictionary is used, here, to calculate the number of words. 
	# A word will be used as a key and its frequency will be the value.
	num_word = {}  
	f = open(filename,'r')
	for line in f:
		line = line.lower()
		line = line.split()
		for words in line:
			if not words in num_word:
				num_word[words] = 1
			else:
				num_word[words] = num_word[words] + 1
	f.close()
	return num_word
    
def print_words(filename):
	num_word = word_count(filename)
	for key in sorted(num_word.keys()):
		print key, num_word[key]

def sort_value(word_count_items):
	return word_count_items[1]
			
def print_top(filename):
	common_words = word_count(filename)
	count = 1
	
	# The sortinng will take place according to the "value" in the dictionary.
	sorted_common_items = sorted(common_words.items(),key=sort_key,reverse=True)
	
	for item in sorted_common_items:
		# Another way to print the first 20 numbers: 
		# for item in sorted_common_items[:20]
		# print item[0],item[1]
		if count > 20:
			return
		else:
			count = count + 1
			print item[0],item[1]
				
if __name__ == '__main__':
  main()
