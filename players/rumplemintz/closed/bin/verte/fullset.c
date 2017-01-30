status
main(string arg)
{
    string a, z;
    int l, x, tmp, heh, bonus_mouse;
    mixed b;
    object ob;
    
    if(!arg || sscanf(arg, "%s %s", a, b) < 2)
    {
      write("Syntax: 'fullset <who> <level>'.\n");
      return 1;
    }

    if(!(ob = find_player(a)))
    {
      write(capitalize(a) + " is not logged on.\n");
      return 1;
    }

      l = tmp;

    if(sscanf(b, "%d+%d", l, x) < 2)
    {
      if((tmp = atoi(b)) && sscanf(b, "%d", heh) && tmp == heh)
        l = tmp;
      else
      {
        write("\
Level must be a number, or in the form 'L+X'.\n\
i.e. 'fullset joe 19+13' or 'fullset ted 3'.\n");
        return 1;
      }
    }

    if(l <= 0)
    {
      write("Error\n");
      return 1;
    }

    write("l: " + l + " / x: " + x + "\n");
    ob->set_level(l);
    ob->set_extra_level(x);

    if(l > 19)
    {
      write("Hmm.  You can't do that.\n");
      return 1;
    }

    if(x) bonus_mouse = (int)"/room/exlv_guild"->get_next_exp(x-1);
    else bonus_mouse = (int)"/room/adv_guild"->get_next_exp(l-1);
 
    if((string)ob->query_guild_name() == "healer") /* this is gay */
    {
      ob->add_xp(-((int)ob->query_exp()));
      ob->add_xp(bonus_mouse);
    }
    else
    {
      ob->add_exp(-((int)ob->query_exp()));
      ob->add_exp(bonus_mouse);
    }

    tell_object(ob, "You have become level " + b + ".\n");

    write("\
You cast a spell of tinkering upon " + (z = (string)ob->query_name()) + 
".\n" + z + " becomes level " + b + ".\n");

    return 1;
}
