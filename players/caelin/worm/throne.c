#include "/players/vertebraker/closed/shardak/def.h"
#include "../universal.h"
inherit ROOM;
int x;

reset(arg) {
   if(arg) return;
   x = 1;
   set_light(1);
   set_short(HIR+"T"+NORM+RED+"he "+HIR+"M"+NORM+RED+"aster's "+NORM+HIR+"C"+NORM+RED+"hambers"+NORM+" ["+RED+"shardak"+NORM+"]");
   set_long(
"This dimly lit room extends in length from the massive doors \n"+
"to a dais at the far end. On the dais sits a large throne-like \n"+
"chair. In front of the dais there is one spot in the room where \n"+
"all the lights seem to focus, as if to give the throne's occupant \n"+
"a clearer view of whoever approaches. The rest of the room is \n"+
"lost in greater and smaller darknesses.  The wary find that they \n"+
"feel glad that shadows hide so much of this room.  Still, they \n"+
"cannot help but wonder what inhabits this private sanctuary \n"+
"of the man who has sacrificed so much to serve his god.\n\n"
+RED+"Worm's Bloody Throne\n"+NORM);
add_exit("/players/vertebraker/closed/shardak/room/grotto.c","grotto");
}
okay_follow() { return 1; }

init() {
  ::init();
  if(TPRN == "lillygirl") {
    write("You are not worthy to enter this room.s\n");
    write("The guards do not pass you through.\n");
    this_player()->move_player("/players/vertebraker/closed/shardak/rooms/grotto");
  }

  add_action("cmd_shardak", "shardak");
  add_action("sit","sit"); 
  add_action("heh","commands");
add_action("tasks","tasks");
add_action("go","go");
  add_action("stand","stand");}

heh(){
cat ("/players/caelin/worm/commands");
 return 1;
}
tasks(){
cat ("/players/caelin/worm/tasks");
return 1;}
sit(){
   if (TPRN != "worm"){
   write("You are NOT Worm.  Get down on your knees and beg his forgiveness, maggot.\n");
   return 1;}
   if (TPRN == "worm"){
     if( x == 2) {
     write("You are already sitting down, dork.\n");
     return 1;}
     if( x == 1) {
     x = 2;
     write("You sit your fat, lazy ass down.\n");
     say("Worm sits on his throne like the pimp mutha fucker he is.\n");
     return 1;}}}

stand(){
   if (TPRN != "worm"){
      return 0;}
   if (TPRN == "worm"){
     if( x == 1) {
     write("You are already standing.\n");
     return 1;}
     if( x == 2) {
     x = 1;
      write("You stand up.\n");
     say("Worm stands up and prepares to execute everyone.\n");
     return 1;}}}

int cmd_shardak(string str) {
  object fiend;
  if(str) return 0;

 (PATH+"shardak")->load();
  fiend = find_object(PATH+"shardak");
  if(!fiend || fiend->query_ghost()) {
    write("Shardak cannot be located in the world of the living.\n");
    return 1;
  }

  write("\n\tYou travel to the demonic demi-god Shardak.\n\n");

  say((string)this_player()->query_name() + " \
disappears in a flash.\n");
  move_object(this_player(), environment(fiend));

  command("look", this_player());
  return 1;
}
int go(string str) {
  object fiend;
  if(!str) {
  write("Where are you going?\n");
  return 1;}
if(str == "lockers") {
move_object(TP, "/players/catwoman/t1");
  write("Caelin transports you.\n");
return 1;}
   if(str == "post") {
  move_object(TP, "/room/post");
  write("Caelin has transported you.\n");
  return 1;}
   if(str == "hotel") {
  move_object(TP, "players/boltar/hotel/hotel");
  write("Caelin swoops down and carries you away.\n");
return 1;}

  command("look", this_player());
  return 1;
}

