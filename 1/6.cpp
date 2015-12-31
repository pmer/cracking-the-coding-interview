string rleCompression(string in)
{
	string out;
	bool first = true;
	char last;
	int count;
	for (char c : in) {
		if (!first && c == last) {
			count++;
			continue;
		}
		if (!first)
			out += count;
		out += c;
		last = c;
		count = 1;
		first = false;
	}
	if (!first)
		out += count;
	return out.size() > in.size() ? out : in;
}
