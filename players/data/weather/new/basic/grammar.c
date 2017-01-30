/*
    basic/grammar.c - basic grammar routines
    Jan 1992 by marion@cs.tu-berlin.de
*/

int
vocal (int c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
	|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string
article (string str)
{
    if (vocal (str[0])) return "an";
    return "a";
}

string
articalize (string str)
{
    return article (str) + " " + str;
}
