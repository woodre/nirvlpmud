
quit_out(){
  int path, road, guth, x, y;
  object *a;
  path = 1 + random(23);
  road = 1 + random(7);
  guth = 1 + random(18);
  x = random(3);
  a = users();
  if(USER->query_attack())
  {
    tell_room(environment(USER), BOLD+BLK+
      "Shadows swirl violently around "+USER->QN+"!\n"+NORM, ({USER}));
    write(BOLD+BLK+"Shadows swirl around your body!\n"+NORM);
  }     
  if(USER->query_level() < 20)  /*  set home for player */
  {
    switch(x)
    {
    case 0:
      USER->set_home("players/zeus/realm/city/path"+path+".c");
      break;
    case 1:
      USER->set_home("players/zeus/realm/taus/road"+road+".c");
      break;
    case 2:
      USER->set_home("players/zeus/realm/taus/guth"+guth+".c");
      break;
    }
  }

  USER->set_guild_name("fallen");   /*  set guild name  */
  save_circle();                    /*  save guild info */

  for(y = 0; y < sizeof(a); y++)    /* quit msg if anyone else on chan */
  {
    if(present("zeus_chatter", a[y]) &&
    (object)present("zeus_chatter", a[y])->query_maker() == USER)
    {
      dspeak(capitalize((string)NAME),"has left the conversation.",1);
      return;
    }
  }

  return;
}
