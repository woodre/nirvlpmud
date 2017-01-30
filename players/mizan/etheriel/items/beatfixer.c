id(str) { return str == "fixer" || str == "beatfixer"; }
short() { return "A happy Beatfixer"; }
long() { 
  write("This is a small button that allows you to jumpstart your\n"+
  "heartbeat if you get one of those nasty 'Game driver tells you\n"+
  "that you have no heart beat' thingy. Simply type 'beatfix' and\n"+
  "everything should be okay...\n");
}

init() {
  if(this_player() && this_player()->query_guild_name() == "polymorph") {
    write("You do not need a beatfixer. An enhanced 'beatfix'\n"+
    "command is embedded in your lump of clay.\n");
    destruct(this_object());
    return 1;
  }
  add_action("beatfix","beatfix");
}
get() { return 1; }
drop() { return 1; }

beatfix() {
  if(find_call_out("do_fix") != -1) {
    write("You are still gathering your strength to fix yourself.\n");
    return 1;
  }
  write("You slowly extend your arm from your body, gather up all your\n");
  write("strength, and....\n");
  call_out("do_fix",5);
  return 1;
}
do_fix() {
  if(environment()->query_ghost())
    {
    tell_object(environment(), "You are DEAD! (No heart to fix)\n");
        return 1;
      }
  environment()->set_heart_beat(1);
  tell_object(environment(), "You smack yourself in the chest and your heart begins beating again.\n");
  return 1;
}
