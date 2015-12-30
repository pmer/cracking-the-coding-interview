bool uniqueChars(string s) {
	char cs[256] = {0};
	for (char c : s) {
		if (cs[c]++)
			return false;
	}
	return true;
}

bool uniqueChars(char *s) {
	if (s[0] == '\0')
		return true;
	for (int i = 1; s[i]; i++) {
		for (int j = 0; j < i; j++)
			if (s[i] == s[j])
				return false;
	}
	return true;
}
