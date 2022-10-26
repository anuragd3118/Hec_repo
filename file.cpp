bool isHexadecimal(string s)
{
	bool ok = true;
	if (s.size() < 3)
		return false;
	ok &= (s[0] == '0');
	ok &= (s[1] == 'x');
	for (int i = 2; i < s.size(); i++)
	{
		bool check = (s[i] >= '0' && s[i] <= '9');
		check |= (s[i] >= 'a' && s[i] <= 'f');
		ok &= check;
	}
	return ok;
}
