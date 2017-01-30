int do_resurrect(string str) 
{
  object target;
  object ob;

  notify_fail("Usage: resurrect <player>\n");

  if(!str) return 0;
  target=present(str,environment(TP));

  if(!target) return 0;

  if(!target->query_ghost()) {
    write("That person is not dead.\n");
    return 1;
  }

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(target==TP) 
  {
    write("You can't resurrect yourself!\n");
    return 1;
  }

  if(TP->query_sp() < 200) 
  {
    write("You don't have enough energy.\n");
    return 1;
  }

  if (this_object()->test_dark())
    return 1;

  if((int)environment()->query_property("no_res"))
  {
    write("You cannot cast this spell here.\n");
    return 1;
  }

  TP->add_sp(-200);

  write("You gather your strength and wait for the spirit to\n"+
        "decide whether it wants to live or not.\n");
  say(TPN+" gathers "+TP->query_possessive()+" strength and prepares for a resurrection.\n");
  tell_object(target, TPN+" wishes to resurrect you.  Do you wish to 'live'?\n");
  ob=clone_object(OBJPATH+"resur_ob.c");
  ob->set_caster(TP);
  move_object(ob,target);
  return 1;
}
