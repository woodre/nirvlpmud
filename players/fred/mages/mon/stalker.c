#include "/players/fred/mages/defs.h"

inherit "obj/monster";

short() {return 0;}

reset(arg) {
  ::reset();
  if(arg) return;
   set_name("stalker");
   set_alias("stalker");
   set_long("You can't see the stalker because it is invisible!\n");
   msgin = "stalks";
   msgout = "stalks";
   cap_name = "Something";
   set_aggressive(0);
   set_level(17);
   set_hp(425);
   set_al(-1000);
   set_wc(24);
   set_ac(14);
   set_heart_beat(1);
 }

heart_beat(){
  if(random(100) < 15) move_rand();
  if(query_attack()) {
  attack();
  ::heart_beat();
  }
}

move_rand() {
 int i;
 i = random(4);
  if(i == 2) command("east");
  if(i == 3) command("west");
 }

init(){
 if(!present("dark_circle", TP)) {
   write("Something grabs you and boots your ass out of here.\n");
   TP->move_player("to the church#room/church");
   tell_room("room/church","A screaming "+capitalize(TPN)+" lands in a heap in the corner.\n");
  }
}

