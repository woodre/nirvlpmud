id(str){ return str == "bf_accept"; }

drop(){              return 1; } 
get(){               return 0; }
can_put_and_get(){   return 0; }

void init(){
  input_to("accept");
}

status accept(string str)
{
  object npc;
  if(str == "yes" || str == "y")
  {
    if((npc = present("bale", environment(environment())))
      && npc->is_npc())
      npc->ask_okay(this_player());
  }
  else {
    if((npc = present("bale", environment(environment())))
      && npc->is_npc())
      npc->ask_deny(this_player());
  }
  destruct(this_object());
  return 1;
}
