inherit "./rlpc_parse.c";

lookup_function (string fun, string file, p, sp)
{
    int def, len, size, arg, end;
    string source_code;

    if (!(file = read_file (file)))
	return -1;

    len = strlen (fun);
    size = strlen (file);

    while (!def && sp < size)
    {
	arg = 0;
	p = sp;
	p += strstr (file, fun, p);
	sp = p + len - 1;

	if (scan_argument (file, sp, &sp) == -1)
	    break;
#if 0
	while (++sp < size) {
	    if (file[sp] == ')') {
		arg = 1;
		break;
	    }
	    if (file[sp] == ';')
		break;
	}
	if (!arg) break;
#endif

	while (++sp < size) {
	    if (file[sp] == '{') {
		def = 1;
		source_code = scan_function (file, &sp, &end);
		break;
	    }
	    if (file[sp] != ' ' && file[sp] != '\n' && file[sp] != '\t')
		break;
	}
    }
    if (def)
	return file [p..sp-1] + source_code;

    return -2;
}
