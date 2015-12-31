bool levensteinDistance01(char *a, char *b)
{
	while (*a && *b && *a == *b) {
		a++;
		b++;
	}
	if (!*a && !*b)
		return true;
	if (*a && !strcmp(a+1, b))
		return true;
	if (*b && !strcmp(a, b+1))
		return true;
	if (*a && *b && !strcmp(a+1, b+1))
		return true;
	return false;
}
