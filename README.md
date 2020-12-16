# simple-spellcheck
A C program that corrects typos by measuring the Levenshtein distance from typos to real words in the dictionary

Works by taking a sentence of input from the user, putting each word into an array, then checking to see if each word is in the dictionary. If the word is not in the dictionary, then the word in the dictionary with the smallest levenshtein distance from the user's input word is used instead.


