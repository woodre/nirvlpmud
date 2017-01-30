inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("smith of darkness");
     set_alt_name("smith_7845");
     set_short();
     set_race("giant");
     set_alias("smith");
     set_long(
  "Tangible darkness. This giant appears to use his hands as hammer and\n"+
  "anvil. He gazes steadily at you from the blackness.\n");
     set_level(24);
     set_ac(40);
     set_wc(30);
     set_hp(600);
     set_heal(10,1);
     set_al(0);
     set_aggressive(0);
   }
}
 
catch_tell(string str) {
  string msg;
  object ns, gd, se;
  object gn, ws;
  if(sscanf(str,"%sforge",msg) || sscanf(str,"%sforge%s",msg) ||
     sscanf(str,"forge%s",msg) ) {
    ns = present("nightshade",this_object());
    gd = present("greydeath",this_object());
    se = present("souleater",this_object());
    gn = present("glowing sword",this_object());
    ws = clone_object("/players/snow/closed/q/wyrmslayer");
    if(ns && gd && se) {
      if(!gn || creator(gn) != "snow") {
        tell_object(this_player(),
          "The dark giant tells you:\n"+
          "  For payment I desire a small gift.\n"+
          "  Bring me the bane of darkness.\n");
        return 1;
      }
    /* Added by Fred [4-10-05] for Bloodfist check */
      /* START */
    if(ns->query_forged() || gd->query_forged() ||
       se->query_forged() || gn->query_forged())
    {
      tell_object(this_player(),
        "\nThe dark giant tells you: \n"+
        " I can't use weapons that were forged by another!\n");
        return 1;
    }
      /* END */
      tell_object(this_player(),
        "The dark giant tells you: \n"+
        " You have done very well. I will forge your mighty weapon.\n");
      destruct(ns);
      destruct(se);
      destruct(gd);
      destruct(gn);
      move_object(ws,environment(this_object()));
      tell_room(environment(this_object()),
        "* * C R A S H * *\n\n");
      tell_room(environment(this_object()),
        "> > > C L A N G < < <\n\n");
      write_file("/players/snow/closed/q/forge", ctime(time())+" "+
        this_player()->query_real_name()+" forged the dragonslayer sword.\n");
      return 1;
    }
    if(!ns && !gd && !se) {
      tell_object(this_player(),
        "The dark giant tells you:\n"+
          "You must give me the three great swords before I can help you.\n");
      return 1;
    }
    tell_object(this_player(),
      "The dark giant tells you:\n");
    tell_object(this_player(),
      "  To forge your weapon I must have-\n");
    if(!ns) tell_object(this_player(),
      "  The sword of the dark flower.\n");
    if(!gd) tell_object(this_player(),
     "  The sword of the vortex.\n");
    if(!se) tell_object(this_player(),
      "  The sword that devours.\n");
    return 1;
  }
}
