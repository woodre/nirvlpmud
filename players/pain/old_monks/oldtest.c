 id(str)  { return str == "robes"; }
 
short() { return "Guild Robes"; }
 
long() {
    write("The monk guild has been closed.\n");
    write("Type 'robe' for info on how to leave\n");
    write("the guild and reasons for it's closure.\n");
}
 
init() {
  add_action("robe","robe");
  add_action("clear","clear");
}
drop() { return 0; }
 
robe() {
    cat("/players/pain/leave");
   return 1;
}
 
clear() {
   int gxp, xp;
   this_player()->set_guild_name(0);
   gxp = this_player()->query_guild_exp();
   this_player()->add_guild_exp(-gxp);
   this_player()->add_exp(gxp);
  this_player()->add_guild_rank(-this_player()->query_guild_rank());
  this_player()->set_guild_file(0);
   this_player()->set_home("room/church");
  command("save",this_player());
   destruct(this_object());
   return 1;
}
 
get() {
   return 1;
}
