from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    set_a = set(a.split("\n"))
    set_b = set(b.split("\n"))

    return set_a & set_b


def sentences(a, b):
    """Return sentences in both a and b"""
    a_sentences = set(sent_tokenize(a))
    b_sentences = set(sent_tokenize(b))

    return a_sentences & b_sentences


def get_substring(str, n):
    """Return a list of substring of size n"""
    substring = []

    temp = len(str) - n + 1

    for i in range(temp):
        substring.append(str[i:i + n])

    return substring


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a_substring = set(get_substring(a, n))
    b_substring = set(get_substring(b, n))

    return a_substring & b_substring
