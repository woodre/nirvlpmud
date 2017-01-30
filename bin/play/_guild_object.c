int cmd_guild_object(string str) {
  string gf;
  object gob;
  
  if(!this_player()->query_guild_name()) {
    notify_fail("You aren't in a guild.\n");
    return 0;
  }
  if(present("GI", this_player())) {
    notify_fail("You already have your guild object.\n");
    return 0;
  }
  if(!(gf = (string)this_player()->query_guild_file())) {
    notify_fail("Your guild may not use this command.\n"+
                "Contact a wizard to restore your guild object.\n");
    return 0;
  }
  if(catch(gob = clone_object(gf))) {
    notify_fail("Your guild file is corrupt.\n"+
                "Contact a senior wizard immediately.\n");
    return 0;
  }
  
  write("You restore your missing guild object.\n");
  move_object(gob, this_player());
  gob->guild_login();
  command("save", this_player());
  return 1;
}
