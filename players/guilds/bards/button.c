
short() { return "Bard Button"; }
init() {
  add_action("push","push");
}
push(str) {
  if(str!="Bard Button" && str!="bard button") return 0;
  if(this_player()->query_guild_name()!="bard") {
    write("Nothing happens, you aren't a bard\n");
    return 1;
  }
  if(present("instrument",this_player()))  {
    write("You don't need to push it.\n");
    return 1;
  }
  write("A bright flash of light.....\n");
  say(this_player()->query_name()+" leaves in a flash of light\n");
  move_object(this_player(),"players/guilds/bards/orin/orin1");
  return 1;
}
long() { 
  write("a button for bards to push. 'push bard button'\n");
  write("It will send you to a place where you will be fixed up\n"+
        "when you exit.\n");
}
id(str) { 
    return str=="bard button" || str=="Bard Button"||str=="button";
}
query_weight() { return 9999999; }

reset() {
  call_other("/players/guilds/bards/orin/orin1","bleech",0);
 move_object(this_object(),"players/guilds/bards/orin/orin1");
 }
