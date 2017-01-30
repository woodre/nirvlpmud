do_enhance(str) {
  object targ;
  object spell;
  string who, typ;
  int amt;  

  if(!str || sscanf(str, "%s %s", who, typ) != 2)
  {
    notify_fail("Usage: enhance <who> <stat>\n");
    return 0;
  }

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(!who)
  {
    write("Who do you wish to enhance?\n"); 
    return 1; 
  }

  if(!typ) 
  {
    write("What stat do you wish to enhance?\n"+
          "  <sta,str,mag,ste,wil,luc,int,pie>\n"); 
    return 1; 
  }

  if(typ != "sta" && typ != "mag" && typ != "wil" && typ != "ste" &&
     typ != "str" && typ != "luc" && typ != "pie" && typ != "int") 
  {
    write("What stat do you wish to enhance?\n"+
          "  <sta,str,mag,ste,wil,luc,int,pie>\n"); 
    return 1; 
  }

  if(!(targ=present(who,environment(TP)))) 
  {
    write("That person is not here!\n");
    return 1; 
  }

  if(!interactive(targ) || !targ->is_player())
  {
    write("You may only cast this spell on players.\n"); 
    return 1; 
  }

  if(targ->query_invis()) 
  {
    write("That person is not here!\n"); 
    return 1;
  }

  if(targ->query_ghost())
  {
    write("You can not cast upon a ghost!\n"); 
    return 1; 
  }

  if (this_object()->test_dark())
    return 1;

  if(targ == TP)
  {
    write("You may not cast this upon yourself!\n"); 
    return 1; 
  }

  if(TP->query_level() < 15)
  {
    write("You lack the experience to fully understand this ability.\n");
    return 1;
  }

  if(TP->query_sp() < 100)
  {
    write("You do not have enough energy.\n");
    return 1;
  }

  if(TP->query_attrib("pie") < 16)
  {
    write("You are not pious enough.\n");
    return 1;
  }

  if(targ->query_guild_name()=="polymorph") 
  {
    write(targ->query_name()+"'s extradimensional nature repels your spell.\n");
    return 1;
  }

  if(present("reinstate_spell",targ))
  {
    write("That person has already been enhanced.\n");
    return 1;
  }

  TP->add_spell_point(-100);
  TP->add_hit_point(-random(20));

  amt = TP->query_level() / 5 + TP->query_extra_level() / 10;
  if(amt > 8) amt = 8;

  spell = clone_object(OBJPATH+"enhance.c");
  spell->start(targ,typ,amt);   

  write("You concentrate upon unlocking "+targ->query_name()+"'s natural abilities.\n");
  say(TP->query_name()+" intones for a moment and lightly touches "+
      targ->query_name()+" with a palm.\n");
  tell_object(targ,"You feel great heat pass from "+TP->query_name()+"'s palm into you!\n");

  tell_object(targ, "Your "+typ+" has been temporarily enhanced.\n");
  write("You have enhanced "+capitalize(who)+"'s "+typ+".\n");
  return 1; 
}
