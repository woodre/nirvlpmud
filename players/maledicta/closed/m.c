void
mal_fuk_up_text(string arg, string arg2, string arg3)
{
    int i, s;
    string *a, *b, c, d;

    if(!arg || !exists(arg))
      return 0;

    s = sizeof(a = explode(read_file(arg), "\n"));
    b = ({ });
    for(i=0;i<s;i++)
    {
      b += ({ a[i] });
      if(sscanf(a[i], "%s" + arg2 + "%s", c, d))
        b += ({ arg3 });
    }

    rm(arg);
    write_file(arg, implode(b, "\n"));
}
