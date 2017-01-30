#include "universal.h"
inherit ROOM;
int x;

reset(arg) {
   if(arg) return;
   x = 1;
   set_light(1);
   set_short(RED+"Worm's Throne Room"+NORM);
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
  add_action("sit","sit"); 
  add_action("stand","stand");}

sit(){
   if (TPRN != "caelin"){
   write("You are NOT Worm.  Get down on your knees and beg his forgiveness, maggot.\n");
   return 1;}
   if (TPRN == "caelin"){
     if( x == 2) {
     write("You are already sitting down, dork.\n");
     return 1;}
     if( x == 1) {
     x = 2;
     write("You sit your fat, lazy ass down.\n");
     say("Worm sits on his throne like the pimp mutha fucker he is.\n");
     return 1;}}}

stand(){
   if (TPRN != "caelin"){
      return 0;}
   if (TPRN == "caelin"){
     if( x == 1) {
     write("You are already standing.\n");
     return 1;}
     if( x == 2) {
     x = 1;
      write("You stand up.\n");
     say("Worm stands up and prepares to execute everyone.\n");
     return 1;}}}

