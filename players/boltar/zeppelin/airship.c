

short()
{
     return "The Zeppelin Airship Graf Nurfberg";
}

query_value()
{
        return 0;
}

  query_weight() {   return 1000000; }
long()
{
    write("The great luxury airship the Graf Nurfberg.\n"+
   "The pride of the fleet, the biggest and fastest airship ever made.\n");
   if (environment(this_player()) == this_object()) {
   write("You are in the boarding room the Graf Nurfburg, it seems odd that\n"+
  "there is no one around. There is a door forward and one aft\n"+
   "and you can also leave the airship.\n");
   }
}

init() {
    set_light(1);
     add_action("leave","leave");
      add_action("enter","enter");
      if(environment(this_player()) == this_object()) {
      add_action("forward","forward");
      add_action("aft","aft");
      }
}

id(str) {
    return str == "airship" || str == "zeppelin" || str == "graf nurfberg";
}

leave() {
    call_other(this_player(), "move_player", "leaves the airship#"+file_name(environment(this_object())));
return 1;
}

enter() {

    say(this_player()->query_name() + " enters the airship.\n");
    write("You climb up the stairway and enter the grand boarding room\n"+
    "of the Graf Nurfburg.\n");
    move_object(this_player(), this_object());
    return 1;
}
forward() {
   call_other("players/boltar/zeppelin/1_class", "set_ship", this_object());
  this_player()->move_player("leaves forward#players/boltar/zeppelin/1_class.c");
  return 1;
  }
aft() {
   call_other("players/boltar/zeppelin/2_class", "set_ship", this_object());
   this_player()->move_player("leaves aft#players/boltar/zeppelin/2_class.c");
   return 1;
   }
