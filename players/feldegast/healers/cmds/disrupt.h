/*
   An attack spell only for undead targets.  This is the only healer attack spell that
   does not drain karma. 
*/

do_disrupt(str)
{
  object ob;

  if(!MYOB)
    return 0;

  if (this_object()->test_dark())
    return 1;

  if((int)TP->query_level() < 13)
    return 0;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

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
    notify_fail("You cannot cast this spell on yourself.\n");
    return 0;
  }

#ifndef __LDMUD__ /* Rumplemintz */
  if( (int)!TP->valid_attack(ob))
#else
  if (!TP->valid_attack(ob))
#endif
  {
    notify_fail("You cannot attack that target.\n");
    return 0;
  }

  if(!ob->id("spirit") &&
     !ob->id("undead") &&
     !ob->id("vampire") &&
     ob->query_guild_string() != "vampire" &&
     !ob->id("skeleton") &&
     !ob->id("ghost") &&
     !ob->id("demon"))
  {
    write("This spell can only be used upon spirits, ghosts, vampires, and demons.\n");
    return 1;
  }

  if( (int)TP->query_sp() < 25)
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
  write(HIY+"You disrupt the chaotic energy that animates "+(string)ob->query_name()+"!\n"+NORM);
  tell_object(ob, HIY+TPN+" disrupts your undead energy!\n"+NORM);
  tell_room(environment(TP), HIY+TPN+" casts a disruption spell at "+(string)ob->query_name()+"!\n"+NORM, ({ TP, ob }));
  /*
    It is unknown how common armors vs good will be in the future... The damage that this spell does should
    be tweaked as needed.
  */
  ob->hit_player(random(40), "other|good");
  return 1;
}
