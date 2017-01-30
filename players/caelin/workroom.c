#include "universal.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Caelin's Hideout");
   set_long(
"A big, empy room WITHOUT ANY CORNERS! \n");
add_exit("/players/vertebraker/closed/shardak/room/grotto.c","grotto");




}
okay_follow() { return 1; }
init() {
  ::init();
   add_action("teller","teller"),
  add_action("coins","coinme"); }

teller(){
   move_object(clone_object("players/zeus/stuff/cae"),this_object());
return 1;}

coins(){
   write("You give yourself 10.000 coins.\n");
  TP->add_money(10000);
   return 1;
}
