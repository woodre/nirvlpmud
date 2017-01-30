int loaded, ticker;

status
drop()
{
    return 1;
}

void
init()
{
    if(environment() && !loaded)
    {
      call_out("hp_regen", 2);
      loaded = 1;
    }
}

void
hp_regen()
{
    object x;
    if(!(x = environment()))
    {
      destruct(this_object());
      return;
    }
    if(((int)x->query_mhp() - (int)x->query_hp()) >= 2)
    {
      ticker ++;
      if(0 == random(10)) tell_object(x, "Some of the pain subsides.\n");
      if(ticker > 11)
      {
        destruct(this_object());
        return;
      }
      x->add_hit_point(2);
    }
    call_out("hp_regen", 2);
}

void
remove_object()
{
    while(remove_call_out("hp_regen") != -1);
}

status
id(string str)
{
    return str == "verte_hp_regen";
}
