inherit "obj/treasure";

reset(arg) {
    name = "mark";
  short_desc = "A replacement mark of the Servants of Shardak";
 long_desc = "Do the command: guild_leave\n";
}

drop() { return 1;}

query_auto_load() { return "players/balowski/guild/mark:0";}

init() {
  add_action("guild_leave", "guild_leave");
}

guild_leave() {
  this_player()->add_exp(this_player()->query_guild_exp());
  this_player()->set_guild_name(0);
  this_player()->set_home(0);
  this_player()->add_guild_rank(-(this_player()->query_guild_rank()));
  this_player()->add_guild_exp(-(this_player()->query_guild_exp()));
  write("Thanks for playing.\n");
  destruct(this_object());
  return 1;
}
