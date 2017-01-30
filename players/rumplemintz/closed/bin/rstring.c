#define WHITESPACES ({' ','\t','\n'})

string
trim_string (string str)
{
    int pos, pos2;

    pos2 = strlen (str) - 1;

    while (pos < pos2 && member (WHITESPACES, str[pos]) >= 0)
	pos++;

    while (pos2 >= 0 && member (WHITESPACES, str[pos2]) >= 0)
	pos2--;

    return str[pos..pos2];
}

string
tab_string (string str, int len)
{
    int t, l;

    l = len - strlen(str);
    if (l <= 0)
	return str;
    for (t=0; t<=l/8; t++)
	str += "\t";
    return str;
}

varargs int
next_string (string text, string *search, int /* & */ which, int pos)
{
    int t, p, min;

    min = -0x80000000; which = -1;

    for (t=0; t < sizeof (search); t++)
	if ((p = strstr (text, search[t], pos)) >= 0)
	    if (p < min) { which = t; min = p; }

    return min == -0x80000000 ? -1 : pos + min;
}

varargs int
next_char (string text, string chars, int /* & */ which, int pos)
{
    int t, min;

    for (t=pos; t < strlen (text); t++)
	if ((which = member (chars, text[t])) >= 0)
	    return t;

    return -1;
}
