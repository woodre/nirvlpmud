mapping stuffs;

reset(x)
{
    if(!x) stuffs = ([ ]);
}

add_creat(ob)
{
   stuffs[ob] = 1;
}

query_creat(ob)
{
   return stuffs[ob];
}
