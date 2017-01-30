/* Simulates mud spells, but includes karma. */
int healer_attack(string str,string name,int dam,int cost,int lvl, int xlvl)
{
  object ob;
  int badkarma;

  if(!MYOB)
    return 0;

  if (this_object()->test_dark())
    return 1;

  if(present("no_spell",this_object()))
  {
    write("You are unable to do that.\n");
    return 1;
  }

  if((int)TP->query_level() < lvl || (int)TP->query_extra_level() < xlvl)
    return 0;

  if (!str)
    ob = (object)this_player()->query_attack();
  else
    ob = present(lower_case(str), environment(this_player()));

  if (!ob || !living(ob)) 
  {
    write("At whom?\n");
    return 1;
  }

  if (ob == this_player())
  {
    write("You cannot cast this spell on yourself.\n");
    return 1;
  }

  if( !TP->valid_attack(ob))
  {
    write("You cannot attack that target.\n");
    return 1;
  }

  if( (int)TP->query_sp() < cost)
  {
    write("You do not have enough spell points.\n");
    return 1;
  }

  if( (int)MYOB->query_casting())
  {
    write("You have not yet recovered from casting your previous spell.\n");
    return 1;
  }

  MYOB->set_casting(1);
  write("You cast a "+name+" at "+(string)ob->query_name()+"!\n");
  tell_object(ob, TPN+" casts a "+name+" spell at you!\n");
  tell_room(environment(TP), TPN+" casts a "+name+" spell at "+(string)ob->query_name()+"!\n");
  badkarma = (int)ob->hit_player(dam);
  MYOB->add_karma(-badkarma);
  return 1;
}

int do_missile(string str)
{
  return healer_attack(str, "magic missile", random(20), 10, 5, 0);
}

int do_shock(string str)
{
  return healer_attack(str, "shock", random(30), 15, 10, 0);
}

int do_fireball(string str)
{
  return healer_attack(str, "fireball", random(40), 20, 15, 0);
}

int do_sonic(string str)
{
  return healer_attack(str, "sonic blast", random(50), 25, 19, 5);
}

int do_mi(string str)
{
  return healer_attack(str, "magic missile", random(20), 10, 5, 0);
}

int do_sh(string str)
{
  return healer_attack(str, "shock", random(30), 15, 10, 0);
}

int do_fi(string str)
{
  return healer_attack(str, "fireball", random(40), 20, 15, 0);
}

int do_so(string str)
{
  return healer_attack(str, "sonic blast", random(50), 25, 19, 5);
}
