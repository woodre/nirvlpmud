soul(str) {
  string junk,junk2;
  object here,guild_object,temp;
  
  remove_call_out("timeout");
  remove_call_out("timeout");
  if (!str) return 0;
  if (str != "on" && str != "off") return 0;
  here = environment(this_object());
  if (str == "off" && !soul) {
    tell_object(myself, "You don't have one.\n");
  return 1;
  }
  if (here) save_me();

  temp = first_inventory(this_object());
  while(temp) {
    if (temp->id("GI")) guild_object = temp;
    temp = next_inventory(temp);
  }
  if(!present("GI")){
    if (!guild_object && guild_file && guild_file !="" && guild_file != 0)
    {
      if(!catch(call_other(guild_file, "id", "GI")))
      {
        gob=clone_object(guild_file);
        move_object(gob, this_object());
      }
    }
  }

  if (soul) {
    if (here) {
    tell_object(myself, "You lose your soul!\n");
    if (str == "on")
      tell_object(myself, "Something's odd though...\n");
  }
    if(soul)
    destruct(soul);
  }
  if (str == "off") {
    return 1;
  }
  if (soul) {
    if (here)
    tell_object(myself, "You cannot bring yourself to do this.\n");
  return 1;
  }
  if (level < EXPLORE) {
    soul = clone_object("obj/soul");
  } else if (level < GOD) {
  soul = clone_object("closed/wiz_soul");
  } else {
  soul = clone_object("closed/wiz_soul");
  }
  move_object(soul, myself);
  if (here)
    tell_object(myself, "You have been ensouled.\n");
  return 1;
}

remote_ed(key) {
  string tpa,tpb,file;
#ifndef __LDMUD__ /* Rumplemintz */
  private;
#endif
  file = call_other(soul,"get_handshake",key);
  file = valid_write(file);
  if (!file) {
  write("You cannot edit that file.\n");
  return 1;
  }
  tell_object(myself,"editing: "+file +"\n");
  ed(file);
}
