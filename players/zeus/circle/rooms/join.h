/*  join.h  */
/****************************************************************************/
/****************************** Joining process *****************************/
/* part of ghall.c */

join2(object x){
  tell_object(x, 
    "\nYou slowly drag your finger over the symbols in the circle...\n"+
    "You feel a strange force guiding your finger over them...\n");
  tell_room(environment(x), x->QN+
    " continues to trace the symbols...\n", ({ x }));
}

join3(object x){
  if(!random(2))
  {
    tell_object(x,
    "\nAs you reach the last symbol a gust of wind blows through the trees.\n");
  tell_room(environment(x), "As "+x->QN+" reaches the last symbol "+
    "a gust of wind blows through the trees.\n", ({ x }));
  }
  else
  {
    tell_object(x,
    "\nAs you reach the last symbol, a noise off in the forest is heard.\n");
  tell_room(environment(x), "You hear a noise off in the forest.\n", ({ x }));
  }
}

join4(object x){
  tell_room(environment(x),
    "\nThe symbols of the circle begin to glow a soft bluish hue...\n");
}

join5(object x){
  tell_object(x,
    "\nYou close your eyes....\n"+
    "You can feel something deep down inside you...  ");
  if(x->query_alignment() > 0)
    tell_object(x, "warmth...\n");
  else if(x->query_alignment() < 0)
    tell_object(x, "so cold...\n");
  else
    tell_object(x, "unknown...\n");
  tell_room(environment(x), x->QN+" closes "+x->POS+" eyes.\n", ({ x }));
}

join6(object x){
  tell_object(x,
    "\nThe sensation slowly spreads throughout your body...\n");
  if(x->query_alignment() > 0)
  {
    tell_object(x, "You are engulfed from within by warmth \n");
    if(x->query_level() != 30)
    {
      x->add_alignment((int)x->query_alignment() * 2 / 
      (30 - (int)x->query_level()) + (1400));
    }
    x->heal_self(400);  /* free heal for good players */
  }
  else if(x->query_alignment() < 0)
  {
    tell_object(x, "You are engulfed from within by the coldness \n");
    if(x->query_level() != 30)
    {
      x->add_alignment((int)x->query_alignment() * 2 / 
      (30 - (int)x->query_level()) - (1400));
    }
  }
  else
    tell_object(x, "You are immersed in the power of the circle.\n");
  tell_room(environment(x), "The circle continues to glow...\n", ({ x }));
}

join7(object x){
  object circle;
  tell_object(x,
    "\nAs you open your eyes, you can feel a connection with the circle...\n"+
    "The glow slowly fades as you finish tracing the last symbol.\n"+
    "\n\n\nYou may wish to 'seek information' again.\n\n");
  tell_room(environment(x),
    x->QN+" opens "+x->POS+" eyes...\n"+
    "As "+x->QN+" finishes tracing the symbols, the glow slowly fades.\n",
    ({ x }));

  x->set_guild_name("fallen");
  x->save_me();
  x->reset();
  circle = clone_object("/players/zeus/circle/circle.c");
  move_object(circle, x);
  circle->set_perc(20);
  circle->set_end_mon(1);
  stats(x);
  x->save();
  circle = present("circle_object", x);
  circle->update_obj(1, x);
  call_other(x, "reset", 1);
}

trace_cmd(str)                                            /* to join guild */
{
  if(!uncovered) return 0;
  if(str == "symbols" || str == "the symbols")
  {
    if(!query_touched(TP))
    {
      write("You are not touching the circle.\n");
      return 1;
    }
    if(!guilded(TP))                                     /* are you guilded */
    {
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You still feel an allegiance to another guild.\n");
      return 1;
    }
    if(TP->query_level() < 10)                           /* min level check */
    {
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You must be at least level 10 to begin.\n");
      return 1;
    }
/*
    if(TP->query_level() > 17)                          /* max level check /*
    {
      write("You trace your finger along the symbols but nothing happens.\n"+
        "You cannot exceed level 17 to begin.\n"+
        "If you wish to become level 17 you may:\n"+
        "  'smear blood on the circle'\n");
      return 1;
    }
    if(TP->query_exp() > 1367106)
    {
      int xp_dif;
      xp_dif = (int)TP->query_exp() - 1367106;
      write("Your experience has been lowered so that you may join.\n");
      TP->add_exp((int)TP->query_exp() - xp_dif);
      write_file("/players/zeus/circle/log/JOIN", ctime(time())+
        "   "+capitalize((string)TP->QRN)+" lost "+xp_dif+
        " when "+TP->query_pronoun()+" joined.\n");
    }
*/
    if(present("blade_obj", TP))                       /*  miniguild checks */
      command("break_knife", TP);
    if(present("feline_obj", TP))
      command("i_am_no_feline", TP);
    if(present("gothic_obj", TP))
      command("i_am_no_goth", TP);
    if(present("gypsy_obj", TP))
      command("i_am_no_gypsy", TP);
    if(present("kender_obj", TP))
      command("i_am_no_kender", TP);
    if(present("larn_obj", TP))
      command("abandon_larn", TP);
    if(present("succubus_obj", TP))
      command("i_am_no_succubus", TP);

    say(TP->QN+" starts tracing "+TP->POS+" finger along the symbols...\n");
    write("\n\nYou begin to trace your finger along the symbols...\n");

    call_out("join2", 6, this_player());
    call_out("join3", 12, this_player());
    call_out("join4", 18, this_player());
    call_out("join5", 24, this_player());
    call_out("join6", 32, this_player());
    call_out("join7", 40, this_player());

    write_file("/players/zeus/circle/log/JOIN", ctime(time())+
      " - "+capitalize((string)TP->QRN)+" [L "+
      TP->query_level()+"] joined.\n");

    return 1;
  }
  return 0;
}

