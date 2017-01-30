int digcount;
 object favor;
id(str) { return str == "office"; }
init() {
      digcount = 0;
if(set_light(0)==0)
       set_light( 1);
      add_action("south","south");
      add_action("east","east");
      add_action("up","up");
      add_action("buy","buy");
      add_action("north","north");
      add_action("down","down");
      add_action("matsu","matsu");
      add_action("look","look");
      add_action("look","l");
      add_action("look","examine");
      add_action("look","move");
}
reset() {
       if (!present("favor")) {
        favor = clone_object("players/boltar/things/ptfv.c");
        move_object(favor, this_object());
         }
}
 short() { return "Legion of the dead office."; }
long() {
 write("This is the office of Boltar's legion of the dead. You too can join\n"+
 "this wonderful origanization.  For only 70 gold coins you will be a full\n"+
   "member of the legion.  Join, its alot of fun.\n");
   write("There is no one here now, but there is an automatic machine that will\n"+
    "take care of you, just type 'buy membership'.\n");
write("note: membership may have to be renewed upon death or advancement.\n" +
      "      Upon membership you may use the member's only area to the north.\n");
    write("You notice some boards coming up in the corner, you may be able to\n"+
  "go under them.\n");
write("\nThere are two doors, one the north and one to the south.\n");
 write("You see a small staircase leading up in the corner.\n");
 write("There is a frosted glass door that is pinned open to the east.\n");
}
 south() {
  digcount = 0;
 call_other(this_player(), "move_player", "south#players/boltar/lv1/room1.c");
   return 1;
}
 down() {
   call_other(this_player(), "move_player", "down#players/boltar/quest/enterance.c");
  return 1;
 }
 north() {
  call_other(this_player(), "move_player", "north#players/boltar/sprooms/dead_bef.c");
  return 1;
}
 up() {
     call_other(this_player(), "move_player", "up#players/boltar/lv2/gamblerroom.c");
  return 1;
}
buy(str) {
    string nme, newtl;
    object newtlnam;
   if(str != "membership") { 
    return 1;
}
  if(call_other(this_player(), "query_title", 0) == "of the legion of the dead.") {
write("You are already a member.\n");
return 1;
}
    if (call_other(this_player(), "query_money", 0) < 70) {
         write("You don't have enough money!\n");
          return 1;
      }
    call_other(this_player(), "add_money", -70);
    write("It costs you 70 gold coins.\n");
     call_other(this_player(), "set_title", "of the legion of the dead.");
    write("You are now a member of the legion of the dead.");
    write("\n");
    nme = call_other(this_player(), "query_name", 0);
    say(nme + " is now part of The Legion of the dead.");
    say("\n");
/*
 write_file("/open/boltar/legion.log", this_player()->query_real_name() + " joined the legion.\n");
*/
  return 1;
}
matsu() {
   object tharm;
    tharm = clone_object("players/boltar/things/thi5.c");
      move_object(tharm, this_object());
 return 1;
}
look(str) {
   if (!str) {
   return 0;
  }
  if (str == "at machine" || str == "in machine"){
    write("The machine has a slot in it for your payment. There's a screen with \n with a message on it asking you to buy membership.\n");
   return 1;
  }
   if (str == "boards" || str == "board" || str == "at boards" || str == "at floor boards"){
     write("Looks like you can slip down under them.\n");
     return 1;
    }
return 0;
}
east() {
call_other(this_player(), "move_player", "east#players/boltar/sprooms/clinic/lobby");
return 1;
}
