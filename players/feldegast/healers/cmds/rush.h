int do_rush(string str)
{
  object targ;
  object ob;

  if((int)TP->query_level() < 16)
    return 0; 

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if((int)TP->query_sp() < 30)
  {
    write("You do not have enough spell points.\n");
    return 1;
  }

  if((int)MYOB->query_casting())
  {
    write("You have not yet recovered from casting your previous spell.\n");
    return 1;
  }

  if(!str)
  {
    notify_fail("Rush who?\n");
    return 0;
  }

  if(!(targ = present(str, environment(TP))))
  {
    notify_fail("That person is not here.\n");
    return 0;
  }

  if((int)targ->query_invis())
  {
    notify_fail("That person is not here.\n");
    return 0;
  }

  if (targ!=TP && (int)this_object()->test_dark())
    return 1;

  if((int)targ->is_ghost())
  {
    write("You cannot cast this on a dead person.\n");
    return 1;
  }

  if(!living(targ))
  {
    write("This spell will not work on that.\n");
    return 1;
  }

  if(present("rush", targ))
  {
    write("That person is already moving quickly.\n");
    return 1;
  }

  write(BOLD+"You accelerate the metabolism and mental processes of "+(string)targ->query_name()+".\n"+NORM);
  tell_object(targ, BOLD+TPN+" accelerates your metabolism and mental processes.\n"+NORM);
  say(BOLD+TPN+" accelerates "+(string)targ->query_name()+"!\n"+NORM, ({ TP, targ }));
  ob = clone_object(OBJPATH+"rush.c");
  move_object(ob, targ);
  TP->add_spell_point(-30);
  MYOB->set_casting(6);
  return 1;
}
