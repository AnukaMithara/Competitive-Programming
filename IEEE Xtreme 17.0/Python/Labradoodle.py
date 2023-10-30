def find_blends(dictionary, words):
    prefixes = {}
    suffixes = {}
    for word in dictionary:
        for i in range(3, len(word) + 1):
            prefix = word[:i]
            suffix = word[i - 1:]
            if prefix not in prefixes:
                prefixes[prefix] = []
            if suffix not in suffixes:
                suffixes[suffix] = []
            prefixes[prefix].append(word)
            suffixes[suffix].append(word)

    results = []
    for word in words:
        blends = set()
        for i in range(3, len(word)):
            prefix = word[:i]
            suffix = word[i - 1:]
            if prefix in prefixes and suffix in suffixes:
                for pre_word in prefixes[prefix]:
                    for suf_word in suffixes[suffix]:
                        blends.add((pre_word, suf_word))
        if len(blends) > 1:
            results.append('ambiguous')
        elif len(blends) == 0:
            results.append('none')
        else:
            results.append(' '.join(list(blends)[0]))
    return results
