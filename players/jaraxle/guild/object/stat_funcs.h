status
set_stat(string str, int arg)
{
    if(!Stats[str] || Stats[str] == GSTAT_MAX) return 0;
    else
    {
      Stats[str] = arg;
      return 1;
    }
}

status
query_stat(string str)
{
    if(!Stats[str]) return -1;
    else return Stats[str];
}

