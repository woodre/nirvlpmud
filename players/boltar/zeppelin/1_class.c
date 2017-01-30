
object airship;

short()
{
      return "1st class section, Graf Nurfberg";
}

long()
{
  write("The first class section of the Nurfberg, the spacious luxury of it\n"+
 "all surrounds you. There are large padded chairs with tables on both\n"+
 "sides along the windows.\n");
  write("There is a door forward and one aft.\n");
}

init() {
    set_light(1);
      add_action("forward","forward");
      add_action("aft","aft");
}


forward() {
  this_player()->move_player("leaves forward#players/boltar/zeppelin/pilot.c");
  return 1;
  }
aft() {
say(this_player()->query_name() + " leaves aft.\n");
    move_object(this_player(), airship);
     airship->long();
   return 1;
   }
set_ship(obj) {

airship = obj;
}
