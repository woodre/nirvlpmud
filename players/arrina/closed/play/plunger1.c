object owner;

id(str) {
  return str == "plunger";
}

short() {
  return "The Plunger of Doom";
}

long() {
  write("This is no ordinary plunger. You can do the following things\n"+
  "with it:\n\n"+
  "lk <playername>       Lock <playername> out of the game.\n"+
  "                      Action irreversible except by L1000+ wiz.\n"+
  "                      This is your primary offense. Be careful with it.\n\n"+
  "nk <playername>       'Safe' nuke of <playername>\n"+
  "                      Calls move_player() to void, then dests.\n\n"+
  "bk <playername>       Bombs <playername>'s inventory.\n"+
  "                      Calls destruct_inventory().\n\n"+
  "NOTE: You CANNOT alias these commands. They are static function calls\n"+
  "and there is no function overload/overlay checking on a mud so be careful.\n");
}

init() {
  add_action("lk","lk");
  add_action("nk","nk");
  add_action("bk","bk");
}

static lk(arg) {
  object victim;
  if(!arg) return 0;
  victim = find_player(arg);
  if(!victim) {
    write("lk: Cannot locate player '" + arg + "'.\n");
    return 1;
  }
  victim->set_guild_file("invalid");
  victim->set_guild_name("Fool");
  victim->save_me();
  victim->destruct_inventory();
  victim->save_me();
  destruct(victim);
  if(victim) {
    write("lk: Error. Victim survived a direct destruct() function call.\n"+
    "    Make SURE that victim is out of the game.\n");
    victim->quit();
  }
  write("lk: Done.\n");
  return 1;
}

static nk(arg) {
  object victim;
  if(!arg) return 0;
  victim = find_player(arg);
  if(!victim) {
    write("nk: Cannot locate player '" + arg + "'.\n");
    return 1;
  }

  victim->move_player("X#room/void");
  destruct(victim);
  if(victim) {
    write("nk: Error. Victim survived a direct destruct() function call.\n"+
    "    Attempting to forcequit player...\n");
    victim->quit();
  }
  if(victim) {
    write("nk: Error. Victim survived a direct quit() command.\n"+
    "    Attempting to lockout player...\n");
    victim->set_guild_file("invalid");
    victim->save_me();
    victim->do_quit();
  }
  if(victim) {
    write("nk: Error. Victim survived a direct do_quit() function call.\n"+
    "    Player is still in game but lockout will take effect next login.\n");
  }
  write("nk: Done.\n");
  return 1;
}

static bk(arg) {
  object victim;
  if(!arg) return 0;
  victim = find_player(arg);
  if(!victim) {
    write("bk: Cannot locate player '" + arg + "'.\n");
    return 1;
  }
  victim->destruct_inventory();
  write("bk: Done.\n");
  return 1;
}
