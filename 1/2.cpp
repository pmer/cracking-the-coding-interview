bool isPermutation(string a, string b) {
	char csa[256] = {0};
	char csb[256] = {0};
	for (char c : a)
		csa[c]++;
	for (char c : b)
		csb[c]++;
	for (int i = 0; i < 256; i++)
		if (csa[i] != csb[i])
			return false;
	return true;
}
