
shadow_wave(){
  if(User->query_ghost()) return 0;
  TOU BOLD+BLK+
    "You wave a hand, causing shadows to rise up all around you.\n"+NORM);
  TRU BOLD+BLK+User->QN+" waves a hand, causing shadows to rise up all "+
    "around "+User->OBJ+".\n"+NORM,  ({ User }));
  return 1;
}

stand(){
  if(User->query_ghost()) return 0;
  TOU
    "You stand tall as shadows swirl about your body.\n");
  TRU User->QN+
    " stands tall as shadows swirl about "+User->POS+" body.\n",
    ({ User }));
  return 1;
}

battle_cry(){
  if(User->query_ghost()) return 0;
  TOU
    "You breathe deeply, focusing your strength and power...\n"+
    "You let out a fearsome battle cry as you prepare for combat!\n");
  TRU User->QN+
    " breathes deeply, focusing "+User->POS+" strength and power...\n"+
    User->QN+" lets out a fearsome battle cry as "+User->PRO+
    " prepares for combat!\n", ({ User }));
  return 1;
}

fdraw(pic){
  if(User->query_ghost()) return 0;
  TOU
    "You draw your finger through the air in front of you...\n"+
    "A thin line of "+BOLD+BLK+"dark shadows "+NORM+
    "trails after your finger...\n");
  TRU User->QN+
    " draws "+User->POS+" finger through the air in front "+
    "of "+User->OBJ+"...\n"+
    "A thin line of "+BOLD+BLK+"dark shadows"+NORM+
    " trails after "+User->POS+" finger...\n", ({ User }));
  if(pic)
  {
    TOU "You draw a picture of "+pic+" in the air.\n");
    TRU User->QN+" draws a picture of "+pic+" in the air.\n", ({ User }));
  }
  return 1;
}

scoff_cmd(str){
  if(User->query_ghost()) return 0;
  if(!str)
  {
    tell_room(environment(User),
      User->query_name()+" scoffs to "+User->query_objective()+"self.\n",
      ({ User }));
    tell_object(User, "You scoff to yourself.\n");
  }
  else if(str)
  {
    object who;
    who = present(str, environment(User));
    if(!who)
      who = find_player(str);
    if(!who) return 0;
    if(in_editor(who) || who->query_invis() >= User->query_level())
      return 0;
    if(who->query_tellblock())
      tell_object(User, who->query_name()+" is blocking emotes.\n");
    else if(who == User)
    {
      tell_object(User, "You scoff at yourself for being stupid.\n");
      tell_room(environment(User), User->query_name()+" scoffs at "+
        User->query_objective()+"self for being stupid.\n", ({ User }));
    }
    else if(present(who, environment(User)))
    {
      tell_room(environment(User),
        User->query_name()+" scoffs at "+who->query_name()+".\n",
        ({ who })); }
    else
    {
      tell_object(who, User->query_name()+
        " scoffs at you from afar.\n");
      tell_object(User, "You scoff at "+who->query_name()+" from afar.\n");
    }
  }
  return 1;
}

wait_cmd(str){
  if(User->query_ghost()) return 0;
  if(!environment(User)) return 0;
  if(!str)
  {
    tell_room(environment(User),
      User->query_name()+" waits impatiently.\n",
      ({ User }));
    tell_object(User, "You wait impatiently.\n");
  }
  else if(str)
  {
    object who;
    who = present(str, environment(User));
    if(!who)
      who = find_player(str);
    if(!who) return 0;
    if(in_editor(who) || who->query_invis() >= User->query_level())
      return 0;
    if(who->query_tellblock())
      tell_object(User, who->query_name()+" is blocking emotes.\n");
    else if(who == User)
    {
      tell_object(User, "You wait for yourself to get ahead in life.\n");
      tell_room(environment(User), User->query_name()+" seems to be "+
        "waiting for something, but you can't tell what.\n", ({ User }));
    }
    else if(present(who, environment(User)))
    {
      tell_room(environment(User),
        User->query_name()+" waits impatiently for "+who->query_name()+"\n",
        ({ User }));
      tell_object(User, "You wait impatiently for "+who->query_name()+".\n");
    }
    else
    {
      if(environment(User)->short())
      {
        tell_object(who, User->query_name()+
          " is waiting for you at "+environment(User)->short()+".\n");
      }
      else
        tell_object(who, User->query_name()+" is waiting for you.\n");
      tell_object(User, "You wait for "+who->query_name()+".\n");
    }
  }
  return 1;
}
