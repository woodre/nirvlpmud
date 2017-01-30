inherit "./rstring.c";

private
varargs strstr2 (str, pat, off)
{
    int p;
    
    p = strstr (str, pat, off);
    return p == -1 ? -0x80000000 : p;
}

skip_comment (str, pos) {
    return pos + strstr (str,"*/",pos) + 1;
}

skip_string (str, pos)
{
    int lpos;

    while (1)
    {
	lpos = pos;
	if ((pos = strstr (str, "\"", lpos)) == -1)
	{
	    return strlen (str);
	}
	pos = lpos + pos;
	if (str[pos-1] != '\\')
	{
	    return pos;
	}
	pos++;
    }
}

scan_argument (str, start, end)
{
    int pse, pos, pop, pcl, pst, pco, brackets;

    pos = start;
    while (1)
    {
	pop = strstr2 (str, "(", pos);
	pcl = strstr2 (str, ")", pos);
	pst = strstr2 (str, "\"", pos);
	pco = strstr2 (str, "/*", pos);
	pse = strstr2 (str, ";", pos);
	pos++;
	
	if (pse < pcl && pse < pop && pse < pst && pse < pco)
	    break;
	if (pco < pcl && pco < pop && pco < pst)
	{
	    pos = skip_comment (str, pco + pos);
	}
	else if (pst < pcl && pst < pop)
	    pos = skip_string (str, pst + pos) + 1;
	else if (pop < pcl)
	{
	    pos += pop;
	    brackets++;
	}
	else
	{
	    pos += pcl;
	    brackets--;
	}
	if (brackets == 0)
	{
	    start += strstr (str,"(",start);
	    end = pos - 1;
	    return str[start..end];
	}
    }
    return -1;
}

scan_assignment (str, start, end)
{
    int pos, pse, pst, pco;

    pos = start;
    while (1)
    {
	pse = strstr2 (str, ";", pos);
	pst = strstr2 (str, "\"", pos);
	pco = strstr2 (str, "/*", pos);
	
	if (pco < pst && pco < pse)
	    pos = skip_comment (str, pco + pos);
	else if (pst < pse)
	    pos = skip_string (str, pst + pos + 1) + 1;
	else {
	    end = pos + pse;
	    return str[start..end];
	}
    }
    return -1;
}

scan_function (str, start, end)
{
    int pos, pop, pcl, pst, pco, brackets;

    pos = start;
    while (1)
    {
	pop = strstr2 (str, "{", pos);
	pcl = strstr2 (str, "}", pos);
	pst = strstr2 (str, "\"", pos);
	pco = strstr2 (str, "/*", pos);
	pos++;

	if (pco < pcl && pco < pop && pco < pst)
	{
	    pos = skip_comment (str, pco + pos);
	}
	else if (pst < pcl && pst < pop)
	    pos = skip_string (str, pst + pos) + 1;
	else if (pop < pcl)
	{
	    pos += pop;
	    brackets++;
	}
	else
	{
	    pos += pcl;
	    brackets--;
	}
	if (brackets == 0)
	{
	    start += strstr (str,"{",start);
	    end = pos - 1;
	    return str[start..end];
	}
    }
    return -1;
}
