void escape(char[] s, int len) {
	int spaces = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == ' ')
			spaces++;
	if (spaces == 0)
		return;
	for (int i = len - 1; i >= 0; i--) {
		s[i + 2 * spaces] = s[i];
		if (s[i] == ' ') {
			spaces--;
			s[i + 2 * spaces + 0] = '%';
			s[i + 2 * spaces + 1] = '2';
			s[i + 2 * spaces + 2] = '0';
		}
	}
}
